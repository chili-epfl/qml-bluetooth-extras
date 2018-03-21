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
 * @file LowEenergyCentral.cpp
 * @brief A Bluetooth Low Energy central controller
 * @author Ayberk Özgür
 */

#include "LowEnergyCentral.h"

#include <QBluetoothAddress>
#include <QBluetoothUuid>

namespace QMLBluetoothExtras{

LowEnergyCentral::LowEnergyCentral(QQuickItem* parent) : QQuickItem(parent){
    controller = NULL;
}

LowEnergyCentral::~LowEnergyCentral(){
    if(controller != NULL)
        controller->deleteLater();
}

void LowEnergyCentral::discoverServices(){
    controller->discoverServices();
}

void LowEnergyCentral::connectToDevice(){

    /* USING UNDOCUMENTED CONSTRUCTOR */
    controller = new QLowEnergyController(QBluetoothAddress(remoteAddr), QBluetoothAddress(localAddr), this);
    //controller = new QLowEnergyController(QBluetoothAddress("FC:F1:52:79:57:3A"), this);

    connect(controller, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(controller, SIGNAL(discoveryFinished()), this, SIGNAL(discoveryFinished()));
    controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    controller->connectToDevice();
}

QStringList LowEnergyCentral::services(){
    QList<QBluetoothUuid> s = controller->services();
    QStringList result;
    for(auto const& service : s)
        result.append(service.toString());
    return result;
}

int LowEnergyCentral::state(){
    return controller->state();
}

int LowEnergyCentral::error(){
    return controller->error();
}


}
