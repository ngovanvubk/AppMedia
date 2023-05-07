/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p appmain_interface.h: ../AppSetup/local.AppMain.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef APPMAIN_INTERFACE_H
#define APPMAIN_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface local.AppMain
 */
class LocalAppMainInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "local.AppMain"; }

public:
    LocalAppMainInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~LocalAppMainInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> deregistrationAppID(int appid, const QString &appname)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appid) << QVariant::fromValue(appname);
        return asyncCallWithArgumentList(QStringLiteral("deregistrationAppID"), argumentList);
    }

    inline QDBusPendingReply<> registrationAppID(int appid, const QString &appname, const QString &servicename, const QString &objectpath)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appid) << QVariant::fromValue(appname) << QVariant::fromValue(servicename) << QVariant::fromValue(objectpath);
        return asyncCallWithArgumentList(QStringLiteral("registrationAppID"), argumentList);
    }

    inline QDBusPendingReply<> requestShow(int appid)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appid);
        return asyncCallWithArgumentList(QStringLiteral("requestShow"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace local {
  typedef ::LocalAppMainInterface AppMain;
}
#endif