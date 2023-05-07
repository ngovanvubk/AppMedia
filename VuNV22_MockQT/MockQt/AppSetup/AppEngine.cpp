#include "AppEngine.h"
#include <QTimer>
#include<settupinformation.h>
AppEngine::AppEngine(QGuiApplication &app, QObject *parent)
    :  m_volume(5) , m_filePath("setupInformation.json") , m_language("VietNamese"),  mApp(&app) ,QObject(parent)
{
    mViewer = new QQuickView;
    m_translator = new Translator;
    mViewer->setSource(QUrl::fromLocalFile(":/main.qml"));
    mViewer->rootContext()->setContextProperty("myEngine", this);
    mViewer->rootContext()->setContextProperty("translator", m_translator);
    QDBusConnection dbus = QDBusConnection::sessionBus();
    initInformation();
    m_translator->setTranslation("VietNamese");
    if(!dbus.isConnected())
    {
        LOG << "Can not connect to dbus";
    }

    // register object service
    if(!dbus.registerService(SERVICE_NAME_SETUP))
    {
        LOG << "Can not Register Service " << SERVICE_NAME_SETUP;
    }

    // register object paths
    if(!dbus.registerObject(PATH_NAME_SETUP, this))
    {
        LOG << "cannot registerObject" << PATH_NAME_SETUP;
    }

    mAptor = new AppEngineAdaptor(this);
    mInterface = new local::AppMain(QString(SERVICE_NAME_MAIN), QString(PATH_NAME_MAIN), dbus, this);
    mInterface->registrationAppID(APP_SETUP, "AppSetup", SERVICE_NAME_SETUP, PATH_NAME_SETUP);
//    showViewer();
}

AppEngine::~AppEngine()
{
    LOG << "decontructor";
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
    if(m_translator){
        delete  m_translator;
        m_translator= nullptr;
    }
    if(mInterface)
    {
        mInterface->deregistrationAppID(APP_SETUP, "AppSetup");
        delete mInterface;
        mInterface = nullptr;
    }
}

void AppEngine::requestShow(int appID)
{
    LOG << "appID: " << appID;
    mInterface->requestShow(appID);
}

void AppEngine::initInformation(){
    QFile file(m_filePath);
    if (file.exists()) {
        qDebug() << "File exists in the build folder";
    } else {
        qDebug() << "File does not exist in the build folder";
        QJsonObject recordObject;
        recordObject.insert("Language" ,"English");
        recordObject.insert("Volume" ,5);
        QJsonDocument doc(recordObject);
        if (file.open(QIODevice::WriteOnly)) {
            file.write(doc.toJson());
            file.close();
        }
        //        qDebug() << doc.toJson();
        qDebug() << "successfully create json file";
    }
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        QJsonObject jsonObj = jsonDoc.object();
        QJsonValue languageValue= jsonObj.value("Language");
        QJsonValue volumeValue = jsonObj.value("Volume");
        QString language = languageValue.toString();
        int volume = volumeValue.toInt();
        qDebug()<<language<<volume;
        sendVolume2MusicAndVideo(volume*10);
        notifyLanguegeChanged(language);
    }
    else{
        qDebug() << "Failed to open file: " << file.errorString();
    }
}

void AppEngine::writeInformation(){
    QJsonObject recordObject;
    recordObject.insert("Language" ,m_language);
    recordObject.insert("Volume", m_volume);
    QFile file(m_filePath);
    QJsonDocument doc(recordObject);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
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
    if(appID == APP_SETUP)
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
    if(appID == APP_SETUP)
    {
        mViewer->hide();
        return 1;
    }
    else
    {
        return 0;
    }
}

QString AppEngine::getLanguage(){
    return m_language;
}

qreal AppEngine::getVolume(){
    return m_volume;
}

void AppEngine::setLanguage(QString language){
    m_language = language ;
    writeInformation();
}

void AppEngine::setVolme(qreal volume){
    m_volume = volume;
    writeInformation();

}

void AppEngine::sendVolume2MusicAndVideo(int volume){
    LOG <<volume;
    QDBusMessage msgDbus = QDBusMessage::createSignal("/fsoft/music" ,"fsoft.music" , "notifyVolume");
    msgDbus << int(volume);
    QDBusConnection::systemBus().send(msgDbus);
}

void AppEngine::notifyLanguegeChanged(QString language){
    LOG <<language;
    QDBusMessage msgDbus = QDBusMessage::createSignal("/fsoft/music" ,"fsoft.music" , "notifyVLanguage");
    msgDbus << QString(language);
    QDBusConnection::systemBus().send(msgDbus);
}
