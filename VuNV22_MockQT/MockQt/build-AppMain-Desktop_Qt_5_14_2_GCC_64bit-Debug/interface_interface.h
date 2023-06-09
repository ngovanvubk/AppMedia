/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -p interface_interface.h: ../AppMain/com.interface.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef INTERFACE_INTERFACE_H
#define INTERFACE_INTERFACE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface local.AppEngine
 */
class LocalAppEngineInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "local.AppEngine"; }

public:
    LocalAppEngineInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = nullptr);

    ~LocalAppEngineInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> hideWindow(int appID)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appID);
        return asyncCallWithArgumentList(QStringLiteral("hideWindow"), argumentList);
    }

    inline QDBusPendingReply<> requestShow(int appID)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appID);
        return asyncCallWithArgumentList(QStringLiteral("requestShow"), argumentList);
    }

    inline QDBusPendingReply<> showWindow(int appID)
    {
        QList<QVariant> argumentList;
        argumentList << QVariant::fromValue(appID);
        return asyncCallWithArgumentList(QStringLiteral("showWindow"), argumentList);
    }

Q_SIGNALS: // SIGNALS
};

namespace local {
  typedef ::LocalAppEngineInterface AppEngine;
}
#endif
