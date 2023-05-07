#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlContext>
#include <QDBusMessage>
#include <QDBusConnection>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QDebug>
#include<QJsonValue>

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
    void initInformation();
    void writeInformation();



public slots:
    int showWindow(int appID);
    int hideWindow(int appID);
    QString getLanguage();;
    qreal getVolume();;
    void setLanguage(QString language);;
    void setVolme( qreal volume);
    void sendVolume2MusicAndVideo(int volume);
    void notifyLanguegeChanged(QString language);
private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;
    QString m_language;
    QString m_filePath;
    int m_volume;
    Translator *m_translator;

};

#endif // APPENGINE_H
