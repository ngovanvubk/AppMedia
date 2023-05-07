#include "AppEngine.h"
#include <QTimer>



AppEngine::AppEngine(QGuiApplication &app, QObject *parent) : mApp(&app), QObject(parent)
{
    mViewer = new QQuickView;
    m_player = new QMediaPlayer();
    m_playerGetData = new QMediaPlayer();
    m_playlistSong = new QMediaPlaylist;
    mCurrentStatus = QMediaPlayer::StoppedState;
    getData(0);
    setListSong();
    getFileNames();
    registerDbusVolume();
    QObject::connect(m_player, &QMediaPlayer::stateChanged, this, &AppEngine::handlePlaybackStatusChanged);
    QObject::connect(m_player, &QMediaPlayer::durationChanged, this, &AppEngine::handleDurationChanged);
    QObject::connect(m_player, &QMediaPlayer::positionChanged, this, &AppEngine::handlePositionChanged);
    mViewer->rootContext()->setContextProperty("myEngine", this);
    mViewer->rootContext()->setContextProperty("playlistSong" , m_playlistSong);
    mViewer->rootContext()->setContextProperty("SongList" , m_fileNames);
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));
    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }
    // register object service
    if(!dbus.registerService(SERVICE_NAME_MUSIC))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_MUSIC;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_MUSIC, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_MUSIC;
    }
    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(APP_MUSIC, "AppMusic", SERVICE_NAME_MUSIC, PATH_NAME_MUSIC);
//        showViewer();
}

AppEngine::~AppEngine()
{
    if(mViewer)
    {
        delete mViewer;
        mViewer = nullptr;
    }
    if(mAptor)
    {
        delete mAptor;
        mAptor = nullptr;
    }
    if(m_player)
    {
        delete  m_player;
        m_player = nullptr;
    }
    if(m_playlistSong)
    {
        delete  m_playlistSong;
        m_playlistSong = nullptr;
    }
    if(mInterface)
    {
        mInterface->deregistrationAppID(APP_MUSIC, "AppMusic");
        delete mInterface;
        mInterface = nullptr;
    }
}

void AppEngine::requestShow(int appID)
{
    LOG << "appID: " << appID;
    mInterface->requestShow(appID);
}


void AppEngine::getData(int index){
    QList<QUrl> urls = getMusicUrls();
    if(urls.isEmpty()){
        LOG<<"foldr is empty";
        return;
    }
    QEventLoop loop;
    disconnect(m_playerGetData, &QMediaPlayer::mediaStatusChanged, this, &AppEngine::statusChanged);
    connect(m_playerGetData, &QMediaPlayer::mediaStatusChanged, this, &AppEngine::statusChanged);
    disconnect(m_playerGetData, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), &loop , SLOT(quit()));
    connect(m_playerGetData, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), &loop , SLOT(quit()));
    m_playerGetData->setMedia(QUrl(urls[index]));
    setCoverart(getAlbumArt(QUrl(urls[index])));
    loop.exec();
}


qint64 AppEngine::getDuration(){
    qDebug()<<m_player->duration();
    return m_player->duration();
}

void AppEngine::next(){
    emit mediaIschanged();
    if(m_player->isAudioAvailable()){
        qDebug()<<m_duration;
        m_playlistSong->next();
        m_player->play();
    }
}

void AppEngine::prev(){
    emit mediaIschanged();
    if(m_player->isAudioAvailable()){
        qDebug()<<m_duration;
        m_playlistSong->previous();
        m_player->play();
    }
}

void AppEngine::seekSong(qint64 position){
    if(m_player->isAvailable()){
        m_player->setPosition(position);
    }
}

void AppEngine::requestPlay(){
    LOG<<"Request play";
    if (mCurrentStatus == QMediaPlayer::StoppedState)
    {
        m_player->play();
    } else if (mCurrentStatus == QMediaPlayer::PlayingState) {
        m_player->pause();
    } else if (mCurrentStatus == QMediaPlayer::PausedState)
    {
        m_player->play();
    }
}

void AppEngine::setTitle(QString title)
{
    if (m_title == title)
        return;
    m_title = title;
    emit titleChanged(m_title);
}

void AppEngine::setAlbum(QString album)
{
    if (m_album == album)
        return;

    m_album = album;
    emit albumChanged(m_album);
}

void AppEngine::setArtist(QString artist)
{
    if (m_artist == artist)
        return;

    m_artist = artist;
    emit artistChanged(m_artist);
}

void AppEngine::setDuration(qint64 duration)
{
    if (m_duration == duration)
        return;

    m_duration = duration;
    emit durationChanged(m_duration);
}

void AppEngine::setPosition(qint64 position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged(m_position);
}

void AppEngine::setCoverart(QString coverart)
{
    if (m_coverart == coverart)
        return;

    m_coverart = coverart;
    emit coverartChanged(m_coverart);
}

void AppEngine::sendInfo2Home(QString title, QString artist, QString coverart, bool isPaused){
    LOG <<title<< artist<< coverart <<isPaused;
    QDBusMessage msgDbus = QDBusMessage::createSignal("/fsoft/music" ,"fsoft.music" , "notifySendInfo2Home");
    msgDbus << QString(title) << QString(artist)<<QString(coverart)<<bool(isPaused);
    QDBusConnection::systemBus().send(msgDbus);
}

void AppEngine::registerDbusVolume(){
    QDBusConnection::systemBus().connect("","/fsoft/music" ,"fsoft.music" , "notifyVolume" , this , SLOT(onRecceivedVolume(int)));
    qDebug()<<"registed dbus volume succesefully";

}

void AppEngine::onRecceivedVolume(int volume){
    m_player->setVolume(volume);
}

void AppEngine::handlePlaybackStatusChanged(QMediaPlayer::State status){
    mCurrentStatus = status;
}

void AppEngine::handleDurationChanged(qint64 duration){
    setDuration(duration);
    getData(m_playlistSong->currentIndex());
    sendInfo2Home(m_title ,m_artist , m_coverart ,true);
    setPosition(0);
}

void AppEngine::handlePositionChanged(qint64 position){
    setPosition(position);
}



QList<QUrl> AppEngine::getMusicUrls()
{
    QFileInfoList fileInfoList ;
    QList<QUrl> urls ;
    QString pathFolder = QStandardPaths::standardLocations(QStandardPaths::MusicLocation).at(0);
    if(!pathFolder.isNull()){
        QDir folderDir(pathFolder);
        QStringList filters;
        filters << "*.mp3" << "*.m4a" << "*.flac" << "*.wav"; // add more file extensions if needed
        folderDir.setNameFilters(filters);
        fileInfoList = folderDir.entryInfoList(QDir::Files);
        for (const QFileInfo &fileInfo : fileInfoList) {
            QUrl fileUrl = QUrl::fromLocalFile(fileInfo.absoluteFilePath());
            urls.append(fileUrl.toString());
        }
        //        qDebug() << urls;
    }
    else{
        qDebug()<<"Null folderPath";
    }
    return urls;
}

void AppEngine::statusChanged(QMediaPlayer::MediaStatus status){
    QString Title = "UnKnow";
    QString Ablum = "UnKnow";
    QString Artist = "Unknow";
    if (status == QMediaPlayer::LoadedMedia){
        // Get the list of keys there is metadata available for
        QStringList metadatalist = m_playerGetData->availableMetaData();
        // Get the size of the list
        int list_size = metadatalist.size();
        // Define variables to store metadata key and value
        QString metadata_key;
        QVariant var_data;
        for (int indx = 0; indx < list_size; indx++)
        {
            metadata_key = metadatalist.at(indx);
            //            var_data = m_playerGetData->metaData(metadata_key);

            if(metadata_key == "Title"){
                var_data = m_playerGetData->metaData(metadata_key);
                Title = var_data.toString();
                //                qDebug() << metadata_key << var_data.toString();
            }
            if(metadata_key == "AlbumTitle"){
                var_data = m_playerGetData->metaData(metadata_key);
                Ablum = var_data.toString();
                //                qDebug() << metadata_key << var_data.toString();
            }
            if(metadata_key == "ContributingArtist"){
                var_data = m_playerGetData->metaData(metadata_key);
                Artist = var_data.toString();
                //                qDebug() << metadata_key << var_data.toString();
            }
            else{
                continue;
            }
            //            qDebug() << metadata_key << var_data.toString();
        }
        qDebug() << Title<<Artist<<Ablum;
        setTitle(Title);
        setAlbum(Ablum);
        setArtist(Artist);
    }
}

void AppEngine::setListSong()
{
    QList<QUrl> urls = getMusicUrls();
    if(urls.isEmpty()){
        LOG << "Folder is Empty";
        return;
    }
    else{
        for(auto url: urls){
            m_playlistSong->addMedia(QUrl(url));
        }
        m_playlistSong->currentIndex();
        m_playlistSong->setPlaybackMode(QMediaPlaylist::Loop);
        m_player->setPlaylist(m_playlistSong);
        LOG << "Add list song successfull";
    }

}

void AppEngine::getFileNames(){
    QString pathFolder = QStandardPaths::standardLocations(QStandardPaths::MusicLocation).at(0);
    QDir directory(pathFolder);
    QStringList filters;
    filters << "*.mp3" << "*.wav" << "*.flac";
    directory.setNameFilters(filters);
    QFileInfoList files = directory.entryInfoList();
    if(files.isEmpty()){
        LOG <<"Folder is Empty";
        return;
    }
    else{
        for (int i = 0; i < files.size(); ++i) {
            QFileInfo fileInfo = files.at(i);
            QString fileName = fileInfo.fileName();
            m_fileNames.append(fileName);
            qDebug()<<fileName;
        }
    }

}

QString AppEngine::title() const
{
    return m_title;
}

QString AppEngine::album() const
{
    return m_album;
}

QString AppEngine::artist() const
{
    return m_artist;
}

qint64 AppEngine::duration() const
{
    return m_duration;
}

qint64 AppEngine::position() const
{
    return m_position;
}

void AppEngine::onPositionChanged(qint64 position){
    setPosition(position);
}

QString AppEngine::getAlbumArt(QUrl url){
    static const char *IdPicture = "APIC" ;
    TagLib::MPEG::File mpegFile(url.path().toStdString().c_str());
    TagLib::ID3v2::Tag *id3v2tag = mpegFile.ID3v2Tag();
    TagLib::ID3v2::FrameList Frame ;
    TagLib::ID3v2::AttachedPictureFrame *PicFrame ;
    void *SrcImage ;
    unsigned long Size ;
    FILE *jpegFile;
    jpegFile = fopen(QString(url.fileName()+".jpg").toStdString().c_str(),"wb");
    if ( id3v2tag )
    {
        // picture frame
        Frame = id3v2tag->frameListMap()[IdPicture] ;
        if (!Frame.isEmpty() )
        {
            for(TagLib::ID3v2::FrameList::ConstIterator it = Frame.begin(); it != Frame.end(); ++it)
            {
                PicFrame = static_cast<TagLib::ID3v2::AttachedPictureFrame*>(*it) ;
                if ( PicFrame->type() == TagLib::ID3v2::AttachedPictureFrame::FrontCover)
                {
                    // extract image (in it’s compressed form)
                    Size = PicFrame->picture().size() ;
                    SrcImage = malloc ( Size ) ;
                    if ( SrcImage )
                    {
                        memcpy ( SrcImage, PicFrame->picture().data(), Size ) ;
                        fwrite(SrcImage,Size,1, jpegFile);
                        fclose(jpegFile);
                        free( SrcImage ) ;
                        return QUrl::fromLocalFile(url.fileName()+".jpg").toDisplayString();
                    }
                }
            }
        }
    }
    else
    {
        qDebug() <<"id3v2 not present";
        return "qrc:/Image/album_art.png";
    }
    return "qrc:/Image/album_art.png";
}

QString AppEngine::coverart() const
{
    return m_coverart;
}

void AppEngine::onMediaStatusChanged(QMediaPlayer::MediaStatus status){
    if(status == QMediaPlayer::LoadedMedia){
        if(m_player->isAudioAvailable()){
            setDuration(m_player->duration());
            getData(m_playlistSong->currentIndex());
            getAlbumArt(m_coverart);
            setDuration(m_player->duration());
            qDebug()<<m_duration;
            m_player->play();
        }
    }

}

void AppEngine::showViewer()
{
    mViewer->show();
}

void AppEngine::hideViewer()
{
    mViewer->hide();
}

int AppEngine::showWindow(int appID)
{
    LOG << "appID: " << appID;
    if(appID == APP_MUSIC)
    {
        mViewer->show();
        return 1;
    }
    else
    {
        return 0;
    }
}

int AppEngine::hideWindow(int appID)
{
    LOG << "appID: " << appID;
    if(appID == APP_MUSIC)
    {

        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}
