#ifndef SETTUPINFORMATION_H
#define SETTUPINFORMATION_H


#include<QObject>
#include<QJsonDocument>
#include<QJsonObject>
#include<QFile>
#include<QDebug>
#include<QJsonValue>
#include<QGuiApplication>
class Settupinformation : public QObject
{
private:
    QString m_language;
    QString m_filePath;
    qreal m_volume;
    QGuiApplication *mApp;
public:
    Settupinformation(QGuiApplication &app, QObject *parent = nullptr);
public slots:
    QString getLanguage();
    qreal getVolume();
    void setInformation(QString language, qreal volume);
};

#endif // SETTUPINFORMATION_H
