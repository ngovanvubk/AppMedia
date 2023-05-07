#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QTranslator>

class Translator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString emptyStr READ emptyStr NOTIFY languageChanged)
public:
    explicit Translator(QObject *parent = 0);
    ~Translator(){
        emptyStr();
    }
signals:
    void languageChanged();
public:
    Q_INVOKABLE void setTranslation(QString translation);
    QString emptyStr();
private:
    QTranslator m_translator;

};

#endif // TRANSLATOR_H
