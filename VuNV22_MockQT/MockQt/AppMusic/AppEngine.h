#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QDBusMessage>
#include <QDBusConnection>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QMediaPlayer>


#include "interface_adaptor.h"
#include "appmain_interface.h"

#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/mpegfile.h>
#include <taglib/id3v2tag.h>
#include <taglib/id3v2frame.h>
#include <taglib/id3v2extendedheader.h>
#include <taglib/attachedpictureframe.h>


#define PATH_NAME_HOME       "/com/path/home"
#define PATH_NAME_MUSIC      "/com/path/music"
#define PATH_NAME_VIDEO      "/com/path/video"
#define PATH_NAME_SETUP      "/com/path/setup"

#define SERVICE_NAME_HOME     "com.service.home"
#define SERVICE_NAME_MUSIC     "com.service.music"
#define SERVICE_NAME_VIDEO    "com.service.video"
#define SERVICE_NAME_SETUP    "com.service.setup"

#define INTERFACE_NAME          "com.interface"


#define PATH_NAME_MAIN       "/com/path/main"
#define SERVICE_NAME_MAIN     "com.service.main"


#define LOG          qDebug() << Q_FUNC_INFO

enum APP_ID: int {
    APP_MAIN,
    APP_HOME,//1
    APP_MUSIC,//2
    APP_VIDEO,//3
    APP_SETUP//4
};

class AppEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString album READ album WRITE setAlbum NOTIFY albumChanged)
    Q_PROPERTY(QString artist READ artist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(qint64 duration READ duration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QString coverart READ coverart WRITE setCoverart NOTIFY coverartChanged)
public:
    explicit AppEngine(QGuiApplication &app, QObject *parent = nullptr);
    ~AppEngine();
    void showViewer();
    void hideViewer();
    Q_INVOKABLE void requestShow(int appID);
    QList<QUrl>  getMusicUrls();
    void statusChanged(QMediaPlayer::MediaStatus status);
    void setListSong();
    void getFileNames();
    QString title() const;
    QString album() const;
    QString artist() const;
    qint64 duration() const;
    qint64 position() const;
    void onPositionChanged(qint64 position);
    QString getAlbumArt(QUrl url);
    QString coverart() const;
    void onMediaStatusChanged(QMediaPlayer::MediaStatus status);


public slots:
    int showWindow(int appID);
    int hideWindow(int appID);
    void getData(int index);
    qint64 getDuration();
    void next();
    void prev();
    void seekSong(qint64 position);
    void requestPlay();
    void setTitle(QString title);
    void setAlbum(QString album);
    void setArtist(QString artist);
    void setDuration(qint64 duration);
    void setPosition(qint64 position);
    void setCoverart(QString coverart);
    void sendInfo2Home(QString title ,QString artist,  QString coverart , bool isPaused);
    void registerDbusVolume();
    void onRecceivedVolume(int volume);
    void handlePlaybackStatusChanged(QMediaPlayer::State status);
    void handleDurationChanged(qint64 duration);
    void handlePositionChanged(qint64 position);
signals:
    void mediaIschanged();
    void titleChanged(QString title);
    void albumChanged(QString album);
    void artistChanged(QString artist);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
    void coverartChanged(QString coverart);

private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;
    QMediaPlayer *m_player;
    QMediaPlayer *m_playerGetData;
    QMediaPlaylist *m_playlistSong;
    QMediaPlayer::State mCurrentStatus;
    QStringList m_fileNames;


    QString m_title;
    QString m_album;
    QString m_artist;
    qint64 m_duration;
    qint64 m_position;
    QString m_coverart;
};

#endif // APPENGINE_H
