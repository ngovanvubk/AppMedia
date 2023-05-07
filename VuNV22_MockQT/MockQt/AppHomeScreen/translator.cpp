#include "translator.h"
#include <QApplication>
#include<QDebug>
Translator::Translator(QObject *parent) : QObject(parent)
{

}

void Translator::setTranslation(QString translation)
{
    qDebug()<<"function is called"<<translation;
    m_translator.load(":/QmlLanguage_" + translation +".qm");
    qApp->installTranslator(&m_translator);
    emit languageChanged();
}

QString Translator::emptyStr()
{
    return "";
}
