/*
 * Copyright (C) 2018 EPFL
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
 * @file BluetoothScanner.h
 * @brief Scans for Bluetooth devices
 * @author Ayberk Özgür
 */

#ifndef BLUETOOTHSCANNER_H
#define BLUETOOTHSCANNER_H

#include <QQuickItem>
#include <QBluetoothDeviceDiscoveryAgent>

namespace QMLBluetoothExtras{

/**
 * @brief Object that scans for Bluetooth devices
 */
class BluetoothScanner : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    /** @brief Whether to scan continuously, default false */
    Q_PROPERTY(bool continuous MEMBER continuous)

    /** @brief Whether to scan for Bluetooth Classic devices (v2.1 and earlier, if supported), default true */
    Q_PROPERTY(bool scanForClassic MEMBER scanForClassic)

    /** @brief Whether to scan for Bluetooth Low Energy devices (v4.0 and later, if supported), default true */
    Q_PROPERTY(bool scanForLE MEMBER scanForLE)

    /** @brief Whether scanning now, read-only */
    Q_PROPERTY(bool scanning READ isScanning NOTIFY scanningChanged)

    /** @brief List of discovered device MAC addresses, read-only */
    Q_PROPERTY(QStringList discoveredDevices READ getDiscoveredDevices NOTIFY discoveredDevicesChanged)

public:

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Creates a new Bluetooth device scanner
     *
     * @param parent Parent of this QML item
     */
    BluetoothScanner(QQuickItem* parent = 0);

    /**
     * @brief Destroys this Bluetooth device scanner
     */
    virtual ~BluetoothScanner();

    /**
     * @brief Gets whether currently scanning
     *
     * @return Whether currently scanning
     */
    bool isScanning() const;

    /**
     * @brief Gets the list of discovered MAC addresses
     *
     * @return The list of discovered MAC addresses
     */
    QStringList getDiscoveredDevices() const { return discoveredDevices; }

    /** @endcond */

signals:

    /**
     * @brief Emitted when a new device is discovered
     *
     * @param macAddr Mac address of the newly discovered device
     * @param name Name of the discovered device if available
     */
    void deviceDiscovered(QString const& macAddr, QString const& name);

    /**
     * @brief Emitted when scanning finishes
     */
    void finished();

    /** @cond DO_NOT_DOCUMENT */

    /**
     * @brief Emitted when scan stops or starts
     */
    void scanningChanged();

    /**
     * @brief Emitted when list of found robot MAC addresses changes
     */
    void discoveredDevicesChanged();

    /** @endcond */

public slots:

    /**
     * @brief Starts scanning
     */
    void start();

    /**
     * @brief Stops scanning
     */
    void stop();

    /**
     * @brief Clears the list of found robots
     */
    void clear();

private slots:

    /**
     * @brief Publishes device if suitable
     *
     * @param info Newly discovered device
     */
    void sortNewDevice(QBluetoothDeviceInfo const& info);

    /**
     * @brief Restarts if continuously scanning
     */
    void decideRestart();

private:

    bool continuous;                        ///< Whether to continuously scan
    bool scanForClassic;                    ///< Whether to scan for Bluetooth Classic devices
    bool scanForLE;                         ///< Whether to scan for Bluetooth Low Energy devices
    QBluetoothDeviceDiscoveryAgent scanner; ///< Bluetooth device scanner
    QStringList discoveredDevices;          ///< List of device MAC addresses that are discovered

};

}

#endif // BLUETOOTHSCANNER_H
