#include "videoplayer.h"
#include<QFileInfoList>
#include<QStandardPaths>
#include<QDir>
#include<QUrl>
#include <iostream>
using namespace std;
VideoPlayer::VideoPlayer(QObject *parent ):m_surface(nullptr),QObject(parent)
{
    mMediaPlayer = new QMediaPlayer();
    m_playlistVideo = new QMediaPlaylist();
    mCurrentStatus = QMediaPlayer::StoppedState;
    QObject::connect(mMediaPlayer, &QMediaPlayer::stateChanged, this, &VideoPlayer::handlePlaybackStatusChanged);
    QObject::connect(mMediaPlayer, &QMediaPlayer::positionChanged, this, &VideoPlayer::handlePlayingTimeChanged);
    QObject::connect(mMediaPlayer, &QMediaPlayer::durationChanged, this, &VideoPlayer::handleDurationChanged);

    QFileInfoList fileInfoList;
    QString pathFolder = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).at(0);
    if(!pathFolder.isNull()){
        QDir folderDir(pathFolder);
        QStringList filters;
        filters << "*.mp4" ; // add more file extensions if needed
        folderDir.setNameFilters(filters);
        fileInfoList = folderDir.entryInfoList(QDir::Files);
        if(fileInfoList.isEmpty()){
            qDebug()<< "Folder is empty";
            return;
        }
        for (const QFileInfo &fileInfo : fileInfoList) {
            m_fileNames.append(fileInfo.fileName());
            QUrl fileUrl = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            m_playlistVideo->addMedia(QUrl(fileUrl));
        }
        m_playlistVideo->setCurrentIndex(0);
        mMediaPlayer->setPlaylist(m_playlistVideo);
        m_playlistVideo->setPlaybackMode(QMediaPlaylist::Loop);
    }
    else{
        qDebug()<<"Null folderPath";
    }
}

VideoPlayer::~VideoPlayer()
{
    m_surface = nullptr;
    mMediaPlayer->setVideoOutput(m_surface);
}

QAbstractVideoSurface *VideoPlayer::videoSurface() const
{
    return m_surface;
}

void VideoPlayer::setVideoSurface(QAbstractVideoSurface *surface)
{
    if(m_surface != surface)
    {
        m_surface = surface;
        mMediaPlayer->setVideoOutput(m_surface);
        emit videoSurfaceChanged();
    }
}

void VideoPlayer::requestPlay()
{
    cout<<"Request play";
    if (mCurrentStatus == QMediaPlayer::StoppedState)
    {
        mMediaPlayer->play();
    } else if (mCurrentStatus == QMediaPlayer::PlayingState) {
        mMediaPlayer->pause();
    } else if (mCurrentStatus == QMediaPlayer::PausedState)
    {
        mMediaPlayer->play();
    }
}

void VideoPlayer::nextVideo(){
    m_playlistVideo->next();
    setFilename(m_fileNames.at(m_playlistVideo->currentIndex()));
    mMediaPlayer->play();
}

void VideoPlayer::prevVideo(){
    m_playlistVideo->previous();
    setFilename(m_fileNames.at(m_playlistVideo->currentIndex()));
    mMediaPlayer->play();
}

QMediaPlayer* VideoPlayer::getPlayer()
{
    return mMediaPlayer;
}

QMediaPlaylist *VideoPlayer::getPlayList(){
    return m_playlistVideo;
}

QString VideoPlayer::filename() const
{
    return m_filename;
}

qint64 VideoPlayer::duration() const
{
    return m_duration;
}

qint64 VideoPlayer::position() const
{
    return m_position;
}

void VideoPlayer::handleDurationChanged(qint64 duration){

    setDuration(mMediaPlayer->duration());
    setFilename(m_fileNames.at(m_playlistVideo->currentIndex()));
}


void VideoPlayer::handlePlayingTimeChanged(qint64 position)
{
    setPosition(position);
    cout<<"position change to:"<<position<<endl;
}

void VideoPlayer::handlePlaybackStatusChanged(QMediaPlayer::State status)
{
    mCurrentStatus = status;

    cout <<" status change to:"<<(int)status<<endl;
}

void VideoPlayer::setFilename(QString filename)
{
    if (m_filename == filename)
        return;

    m_filename = filename;
    emit filenameChanged(m_filename);
}

void VideoPlayer::setDuration(qint64 duration)
{
    if (m_duration == duration)
        return;

    m_duration = duration;
    emit durationChanged(m_duration);
}

void VideoPlayer::setPosition(qint64 position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged(m_position);
}

void VideoPlayer::seekSong(qint64 position){
    if(mCurrentStatus == QMediaPlayer::StoppedState){
        m_playlistVideo->next();
        mMediaPlayer->play();
        return;
    }
    else if (mCurrentStatus == QMediaPlayer::PlayingState)
    {
        mMediaPlayer->setPosition(position);
    }


}
