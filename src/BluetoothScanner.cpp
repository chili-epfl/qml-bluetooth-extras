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
 * @file CelluloBluetoothScanner.cpp
 * @brief Scans for Cellulo robots
 * @author Ayberk Özgür
 * @date 2017-03-16
 */

#include "BluetoothScanner.h"

namespace QMLBluetoothExtras{

BluetoothScanner::BluetoothScanner(QQuickItem* parent) : QQuickItem(parent){
    continuous = false;
    scanForClassic = true;
    scanForLE = true;

    connect(&scanner, SIGNAL(finished()), this, SIGNAL(finished()));
    connect(&scanner, SIGNAL(canceled()), this, SIGNAL(finished()));
    connect(this, SIGNAL(finished()), this, SIGNAL(scanningChanged()));
    connect(this, SIGNAL(finished()), this, SLOT(decideRestart()));
    connect(&scanner, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo const&)), this, SLOT(sortNewDevice(QBluetoothDeviceInfo const&)));
}

BluetoothScanner::~BluetoothScanner(){}

bool BluetoothScanner::isScanning() const {
    return scanner.isActive();
}

void BluetoothScanner::start(){
    if(!isScanning()){
        clear();
        scanner.start(
            (scanForClassic ? QBluetoothDeviceDiscoveryAgent::ClassicMethod : QBluetoothDeviceDiscoveryAgent::NoMethod) |
            (scanForLE ? QBluetoothDeviceDiscoveryAgent::LowEnergyMethod : QBluetoothDeviceDiscoveryAgent::NoMethod)
        );
        emit scanningChanged();
    }
}

void BluetoothScanner::stop(){
    if(isScanning()){
        scanner.stop();
        emit scanningChanged();
    }
}

void BluetoothScanner::clear(){
    if(!discoveredDevices.isEmpty()){
        discoveredDevices.clear();
        emit discoveredDevicesChanged();
    }
}

void BluetoothScanner::decideRestart(){
    if(continuous)
        start();
}

void BluetoothScanner::sortNewDevice(QBluetoothDeviceInfo const& info){
    QString name = info.name();
    QString macAddr = info.address().toString().toUpper();
    if(!discoveredDevices.contains(macAddr)){
        if(
            ((info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration) && scanForLE) ||
            ((info.coreConfigurations() & QBluetoothDeviceInfo::BaseRateCoreConfiguration) && scanForClassic) ||
            (scanForLE && scanForClassic)
        ){
            discoveredDevices.append(macAddr);
            emit discoveredDevicesChanged();
            emit deviceDiscovered(macAddr, name);
        }
    }
}

}
