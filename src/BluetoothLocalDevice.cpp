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
 * @file BluetoothLocalDevice.cpp
 * @brief Source of QtQuick wrapper around QBluetoothLocalDevice
 * @author Ayberk Özgür
 * @date 2016-12-01
 */

#include "BluetoothLocalDevice.h"

namespace QMLBluetoothExtras{

BluetoothLocalDevice::BluetoothLocalDevice(QQuickItem* parent) : QQuickItem(parent){
    #if defined(Q_OS_WINDOWS)
        qCritical() << "BluetoothLocalDevice::BluetoothLocalDevice(): Does not yet work on WinRT";
    #endif
    localDevice = new QBluetoothLocalDevice(this);
    connectAll();
}

BluetoothLocalDevice::~BluetoothLocalDevice(){
    disconnectAll();
    if(localDevice != NULL)
        localDevice->deleteLater();
}

void BluetoothLocalDevice::connectAll(){
    if(localDevice != NULL){
        connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)), this, SIGNAL(hostModeChanged()));
        connect(localDevice, SIGNAL(deviceConnected(QBluetoothAddress)), this, SIGNAL(connectedDevicesChanged()));
        connect(localDevice, SIGNAL(deviceDisconnected(QBluetoothAddress)), this, SIGNAL(connectedDevicesChanged()));
    }
}

void BluetoothLocalDevice::disconnectAll(){
    if(localDevice != NULL){
        disconnect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)), this, SIGNAL(hostModeChanged()));
        disconnect(localDevice, SIGNAL(deviceConnected(QBluetoothAddress)), this, SIGNAL(connectedDevicesChanged()));
        disconnect(localDevice, SIGNAL(deviceDisconnected(QBluetoothAddress)), this, SIGNAL(connectedDevicesChanged()));
    }
}

BluetoothLocalDeviceStatic::HostMode BluetoothLocalDevice::getHostMode() const {
    if(localDevice != NULL)
        return (BluetoothLocalDeviceStatic::HostMode)localDevice->hostMode();
    else
        return BluetoothLocalDeviceStatic::HostModePoweredOff;
}

bool BluetoothLocalDevice::isValid() const {
    if(localDevice != NULL)
        return localDevice->isValid();
    else
        return false;
}

void BluetoothLocalDevice::powerOn(){
    if(localDevice != NULL)
        localDevice->powerOn();
}

QString BluetoothLocalDevice::getName() const {
    if(localDevice != NULL)
        return localDevice->name();
    else
        return "Invalid adapter";
}

QString BluetoothLocalDevice::getAddress() const {
    if(localDevice != NULL)
        return localDevice->address().toString();
    else
        return "Invalid adapter";
}

void BluetoothLocalDevice::setAddress(QString address){
    if(getAddress().toLower() != address.toLower()){
        QBluetoothLocalDevice* newDevice = new QBluetoothLocalDevice(QBluetoothAddress(address), this);
        if(newDevice->isValid()){
            disconnectAll();
            localDevice->deleteLater();
            localDevice = newDevice;
            connectAll();
            emit addressChanged();
            emit nameChanged();
            emit connectedDevicesChanged();
        }
        else{
            qWarning() << "BluetoothLocalDevice::setAddress(): Given address is invalid, local device with such address may not exist.";
            newDevice->deleteLater();
        }
    }
}

QStringList BluetoothLocalDevice::getConnectedDevices(){
    QStringList devices;
    if(localDevice != NULL)
        for(QBluetoothAddress const& deviceAddress : localDevice->connectedDevices())
            devices << deviceAddress.toString();
    return devices;
}

}
