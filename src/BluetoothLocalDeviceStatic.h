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
 * @file BluetoothLocalDeviceEnums.h
 * @brief Singleton object for exposing QBluetoothLocalDevice enums and static methods to QML
 * @author Ayberk Özgür
 * @date 2016-12-01
 */

#ifndef BLUETOOTHLOCALDEVICESTATIC_H
#define BLUETOOTHLOCALDEVICESTATIC_H

#include <QObject>
#include <QBluetoothLocalDevice>

class BluetoothLocalDeviceStatic : public QObject {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

public:

    BluetoothLocalDeviceStatic(QObject* parent = 0);
    ~BluetoothLocalDeviceStatic();

    enum HostMode {
        HostModePoweredOff = QBluetoothLocalDevice::HostPoweredOff,
        HostModeConnectable = QBluetoothLocalDevice::HostConnectable,
        HostModeDiscoverable = QBluetoothLocalDevice::HostDiscoverable,
        HostModeDiscoverableLimitedInquiry = QBluetoothLocalDevice::HostDiscoverableLimitedInquiry
    };
    Q_ENUM(HostMode)

public slots:

    /**
     * @brief Gets the list of the MAC addresses of all local adapters
     *
     * @return List of MAC addresses of all local adapters
     */
    static QStringList allDevices();

};

Q_DECLARE_METATYPE(BluetoothLocalDeviceStatic::HostMode)

#endif // BLUETOOTHLOCALDEVICESTATIC_H
