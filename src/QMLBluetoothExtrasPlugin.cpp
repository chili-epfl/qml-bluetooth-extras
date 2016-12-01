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
 * @file QMLBluetoothExtrasPlugin.h
 * @brief Object that exposes the QMLBluetoothExtras plugin components as QML objects
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#include "QMLBluetoothExtrasPlugin.h"

#include "BluetoothLocalDevice.h"
#include "BluetoothLocalDeviceStatic.h"
#include "BluetoothServer.h"
#include "BluetoothSocketExtended.h"

void QMLBluetoothExtrasPlugin::registerTypes(const char* uri){
    qmlRegisterType<BluetoothLocalDevice>(uri, 1, 0, "BluetoothLocalDevice");
    qmlRegisterSingletonType<BluetoothLocalDeviceStatic>(uri, 1, 0, "BluetoothLocalDeviceStatic",
                                                [] (QQmlEngine* qmlEngine, QJSEngine* jsEngine)->QObject* {
                                                    Q_UNUSED(qmlEngine)
                                                    Q_UNUSED(jsEngine)
                                                    return new BluetoothLocalDeviceStatic();
                                                });
    qmlRegisterType<BluetoothServer>(uri, 1, 0, "BluetoothServer");
    qmlRegisterType<BluetoothSocketExtended>(uri, 1, 0, "BluetoothSocketExtented");
}
