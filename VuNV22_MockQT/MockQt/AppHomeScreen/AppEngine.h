#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QDBusMessage>
#include <QDBusConnection>

#include "interface_adaptor.h"
#include "appmain_interface.h"
#include"translator.h"



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
public:
    explicit AppEngine(QGuiApplication &app, QObject *parent = nullptr);
    ~AppEngine();
    void showViewer();
    void hideViewer();
    Q_INVOKABLE void requestShow(int appID);
    Q_INVOKABLE void registerDbusMusic();
    Q_INVOKABLE void registerDbusVideo();
    Q_INVOKABLE void registerDbusLanguage();
signals:
    void sendInfo2QmlMusic(QString title , QString artist ,QString  coverart , bool isPaused);
     void sendInfo2QmlVideo(QString fileName , bool isPaused);
public slots:
    int showWindow(int appID);
    int hideWindow(int appID);
    void onRecceivedMsgfromMusic(QString title  ,QString artist,  QString coverart, bool isPaused);
    void onRecceivedMsgfromVideo(QString fileName , bool isPaused);
    void onLanguageChanged(QString language);

private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;
    Translator *m_translator;

};

#endif // APPENGINE_H
