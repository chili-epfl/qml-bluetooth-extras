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
 * @file BluetoothLocalDevice.h
 * @brief QML wrapper around QBluetoothLocalDevice
 * @author Ayberk Özgür
 * @date 2016-11-07
 */

#ifndef BLUETOOTHLOCALDEVICE_H
#define BLUETOOTHLOCALDEVICE_H

#include <QQuickItem>
#include <QBluetoothLocalDevice>

#include "BluetoothLocalDeviceStatic.h"

namespace QMLBluetoothExtras {

/**
 * @brief QML wrapper around QBluetoothLocalDevice
 */
class BluetoothLocalDevice : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Current read-only host mode as described in http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum */
    Q_PROPERTY(QMLBluetoothExtras::BluetoothLocalDeviceStatic::HostMode hostMode READ getHostMode NOTIFY hostModeChanged)

    /** @brief Read-only local adapter name */
    Q_PROPERTY(QString name READ getName NOTIFY nameChanged)

    /** @brief Desired local adapter address */
    Q_PROPERTY(QString address READ getAddress WRITE setAddress NOTIFY addressChanged)

    /** @brief Read-only list of currently connected remote devices over this adapter */
    Q_PROPERTY(QStringList connectedDevices READ getConnectedDevices NOTIFY connectedDevicesChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new BluetoothLocalDevice
     *
     * @param parent Parent of this QML item
     */
    explicit BluetoothLocalDevice(QQuickItem* parent = 0);

    /**
     * @brief Destroys this BluetoothLocalDevice
     */
    virtual ~BluetoothLocalDevice();

    /**
     * @brief Gets the host mode
     *
     * @return Host mode
     */
    QMLBluetoothExtras::BluetoothLocalDeviceStatic::HostMode getHostMode() const;

    /**
     * @brief Gets the local adapter name
     *
     * @return Local adapter name
     */
    QString getName() const;

    /**
     * @brief Gets the local adapter address
     *
     * @return Local address in the form "XX:XX:XX:XX:XX:XX"
     */
    QString getAddress() const;

    /**
     * @brief Sets the local adapter address, the local adapter with the given address must exist
     *
     * @param address Local address in the form "XX:XX:XX:XX:XX:XX"
     */
    void setAddress(QString address);

    /**
     * @brief Gets the list of the MAC addresses of all connected devices
     *
     * @return List of MAC addresses of all connected devices
     */
    QStringList getConnectedDevices();

    /** @endcond */

signals:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when the host mode changes
     */
    void hostModeChanged();

    /**
     * @brief Emitted when the local device address changes
     */
    void addressChanged();

    /**
     * @brief Emitted when the local device name changes
     */
    void nameChanged();

    /**
     * @brief Emitted when a device connects or disconnects
     */
    void connectedDevicesChanged();

    /** @endcond */

public slots:

    /**
     * @brief Gets whether this local adapter exists
     *
     * @return Whether this local adapter exists and is available
     */
    bool isValid() const;

    /**
     * @brief Powers this adapter on
     */
    void powerOn();

private:

    /**
     * @brief Connects all signals of localDevice to this wrapper
     */
    void connectAll();

    /**
     * @brief Disconnects all signals of localDevice from this wrapper
     */
    void disconnectAll();

    QBluetoothLocalDevice* localDevice;  ///< Local device interface

};

}

#endif // BLUETOOTHLOCALDEVICE_H
