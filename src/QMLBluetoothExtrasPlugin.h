/*
 * Copyright (C) 2016 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @mainpage qml-bluetooth-extras
 *
 * QML wrappers for missing Qt Bluetooth objects. More Qt Bluetooth wrappers might come soon. See README.md for more information.
 */

/**
 * @file QMLBluetoothExtrasPlugin.h
 * @brief Object that exposes the QMLBluetoothExtras plugin components as QML objects
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#ifndef QMLBLUETOOTHEXTRASPLUGIN_H
#define QMLBLUETOOTHEXTRASPLUGIN_H

#include <QQmlExtensionPlugin>
#include <qqml.h>

namespace QMLBluetoothExtras{

/** @cond DO_NOT_DOCUMENT */

class QMLBluetoothExtrasPlugin : public QQmlExtensionPlugin {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char* uri);
};

/** @endcond */

}

#endif /* QMLBLUETOOTHEXTRASPLUGIN_H */
