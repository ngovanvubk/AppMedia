/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a appmain_adaptor.h: ../AppMain/local.AppMain.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef APPMAIN_ADAPTOR_H
#define APPMAIN_ADAPTOR_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface local.AppMain
 */
class AppMainAdaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "local.AppMain")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"local.AppMain\">\n"
"    <method name=\"registrationAppID\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"appid\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"appname\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"servicename\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"objectpath\"/>\n"
"    </method>\n"
"    <method name=\"deregistrationAppID\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"appid\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"appname\"/>\n"
"    </method>\n"
"    <method name=\"requestShow\">\n"
"      <arg direction=\"in\" type=\"i\" name=\"appid\"/>\n"
"    </method>\n"
"  </interface>\n"
        "")
public:
    AppMainAdaptor(QObject *parent);
    virtual ~AppMainAdaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void deregistrationAppID(int appid, const QString &appname);
    void registrationAppID(int appid, const QString &appname, const QString &servicename, const QString &objectpath);
    void requestShow(int appid);
Q_SIGNALS: // SIGNALS
};

#endif
