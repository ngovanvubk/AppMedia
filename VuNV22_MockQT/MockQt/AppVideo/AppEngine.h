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
#include"videoplayer.h"

#include"songmodel.h"

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

   Q_INVOKABLE void sendInfo2Home(QString fileName , bool isPaused);
public slots:
    int showWindow(int appID);
    int hideWindow(int appID);
    void registerDbusVolume();
    void onRecceivedVolume(int volume);

signals:
    void videoSurfaceChanged(QAbstractVideoSurface* videoSurface);   


    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

private:
    QGuiApplication *mApp;
    QQuickView *mViewer;
    AppEngineAdaptor *mAptor;
    local::AppMain *mInterface;
    QVideoWidget *m_videoWidget;
    QMediaPlaylist *m_playlistVideo;
    VideoPlayer *m_videoPlayer;

};

#endif // APPENGINE_H
