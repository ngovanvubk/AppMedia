/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -i appmain_interface.h -p :appmain_interface.cpp ../AppHomeScreen/local.AppMain.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "appmain_interface.h"
/*
 * Implementation of interface class LocalAppMainInterface
 */

LocalAppMainInterface::LocalAppMainInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : QDBusAbstractInterface(service, path, staticInterfaceName(), connection, parent)
{
}

LocalAppMainInterface::~LocalAppMainInterface()
{
}

