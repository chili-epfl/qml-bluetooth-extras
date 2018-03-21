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

namespace QMLBluetoothExtras{

LowEnergyCentral::LowEnergyCentral(QQuickItem* parent) : QQuickItem(parent){
    controller = NULL;

    /* USING UNDOCUMENTED CONSTRUCTOR */
    //controller = new QLowEnergyController(QBluetoothAddress("F0:52:FF:E5:EB:54"), QBluetoothAddress("F8:59:71:2F:58:EA"), this);
    controller = new QLowEnergyController(QBluetoothAddress("F0:52:FF:E5:EB:54"), this);

}

LowEnergyCentral::~LowEnergyCentral(){
    if(controller != NULL)
        controller->deleteLater();
}

void LowEnergyCentral::connectToDevice(){
    controller->setRemoteAddressType(QLowEnergyController::PublicAddress);
    controller->connectToDevice();
}

}
