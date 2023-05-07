#include "settupinformation.h"
Settupinformation::Settupinformation(QGuiApplication &app, QObject *parent ) : mApp (&app), QObject(parent)
{



    QString filePath = "setupInformation.json";
    m_filePath = filePath;
    QFile file(m_filePath);
    if (file.exists()) {
        qDebug() << "File exists in the build folder";
    } else {
        qDebug() << "File does not exist in the build folder";
        QJsonObject recordObject;
        recordObject.insert("Language" ,"English");
        recordObject.insert("Volume" ,10);
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
        m_language = languageValue.toString();
        m_volume = volumeValue.toDouble();
        qDebug()<<m_language<<m_volume;
    }
    else{
        qDebug() << "Failed to open file: " << file.errorString();
    }
}

QString Settupinformation::getLanguage(){
    return  m_language;
}

qreal Settupinformation::getVolume(){
    return  m_volume;
}

void Settupinformation::setInformation(QString language, qreal volume){
    m_language = language;
    m_volume = volume;
}
