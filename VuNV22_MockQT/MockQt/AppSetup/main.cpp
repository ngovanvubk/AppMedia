#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "AppEngine.h"
#include<QQmlContext>
#include<settupinformation.h>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppEngine myEngine(app);


    return app.exec();
}
