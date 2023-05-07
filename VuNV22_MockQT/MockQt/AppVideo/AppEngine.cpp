#include "AppEngine.h"
#include <QTimer>



AppEngine::AppEngine(QGuiApplication &app, QObject *parent) : mApp(&app), QObject(parent)
{
    mViewer = new QQuickView;
    m_videoPlayer = new VideoPlayer;
    mViewer->rootContext()->setContextProperty("myEngine", this);
    mViewer->rootContext()->setContextProperty("playlistVideo" , m_videoPlayer);
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));
    registerDbusVolume();
//    mViewer->show();
    QDBusConnection dbus = QDBusConnection::sessionBus();
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_VIDEO))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_VIDEO;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_VIDEO, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_VIDEO;
    }

    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(APP_VIDEO, "AppVideo", SERVICE_NAME_VIDEO, PATH_NAME_VIDEO);
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

    if(m_playlistVideo)
    {
        delete  m_playlistVideo;
        m_playlistVideo = nullptr;
    }
    if(mInterface)
    {
        mInterface->deregistrationAppID(APP_HOME, "AppHomeScreen");
        delete mInterface;
        mInterface = nullptr;
    }
}

void AppEngine::requestShow(int appID)
{
    LOG << "appID: " << appID;
    mInterface->requestShow(appID);
}

void AppEngine::sendInfo2Home(QString fileName, bool isPaused){
    LOG << fileName;
    QDBusMessage msgDbus = QDBusMessage::createSignal("/fsoft/music" ,"fsoft.music" , "notifyFromVideo2Home");
    msgDbus << QString(fileName)<<bool(isPaused);
    QDBusConnection::systemBus().send(msgDbus);
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
    if(appID == APP_VIDEO)
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
    if(appID == APP_VIDEO)
    {
        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}

void AppEngine::registerDbusVolume(){
    QDBusConnection::systemBus().connect("","/fsoft/music" ,"fsoft.music" , "notifyVolume" , this , SLOT(onRecceivedVolume(int)));
    qDebug()<<"registed dbus volume succesefully";

}

void AppEngine::onRecceivedVolume(int volume){
    m_videoPlayer->getPlayer()->setVolume(volume);
}
