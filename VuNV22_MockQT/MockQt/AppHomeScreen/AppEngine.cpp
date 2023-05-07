#include "AppEngine.h"
#include <QTimer>

AppEngine::AppEngine(QGuiApplication &app, QObject *parent) : mApp(&app), QObject(parent)
{
    mViewer = new QQuickView;
    m_translator = new Translator;
    mViewer->rootContext()->setContextProperty("myEngine", this);
    mViewer->rootContext()->setContextProperty("translator" , m_translator);
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));
    m_translator->setTranslation("VietNamese");
    QDBusConnection dbus = QDBusConnection::sessionBus();

    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_HOME))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_HOME;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_HOME, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_HOME;
    }

    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(APP_HOME, "AppHomeScreen", SERVICE_NAME_HOME, PATH_NAME_HOME);
    registerDbusMusic();
    registerDbusLanguage();
//    showViewer();
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

void AppEngine::registerDbusMusic(){
    QDBusConnection::systemBus().connect("","/fsoft/music" ,"fsoft.music" , "notifySendInfo2Home" , this , SLOT(onRecceivedMsgfromMusic(QString , QString,QString , bool)));
    qDebug()<<"registed dbus music succesefully";
}

void AppEngine::registerDbusVideo()
{
    QDBusConnection::systemBus().connect("","/fsoft/music" ,"fsoft.music" , "notifyFromVideo2Home" , this , SLOT(onRecceivedMsgfromVideo(QString , bool)));
    qDebug()<<"registed dbus video succesefully";

}

void AppEngine::registerDbusLanguage()
{
    QDBusConnection::systemBus().connect("","/fsoft/music" ,"fsoft.music" , "notifyVLanguage" , this , SLOT(onLanguageChanged(QString)));
    qDebug()<<"registed dbus language succesefully";
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
    if(appID == APP_HOME)
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
    if(appID == APP_HOME)
    {
        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}

void AppEngine::onRecceivedMsgfromMusic(QString title, QString artist, QString coverart ,bool isPaused){
    LOG <<title <<artist<<coverart << isPaused;
    emit sendInfo2QmlMusic(title ,artist ,coverart, isPaused);
}

void AppEngine::onRecceivedMsgfromVideo(QString fileName, bool isPaused){
    LOG <<fileName << isPaused;
    emit sendInfo2QmlVideo(fileName , isPaused);
}

void AppEngine::onLanguageChanged(QString language){
    LOG <<"language is changed"<<language;
    m_translator->setTranslation(language);
}

