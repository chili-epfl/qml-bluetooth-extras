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
 * @file BluetoothServer.cpp
 * @brief QML wrapper source for QBluetoothServer (only RFCOMM)
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#include "BluetoothServer.h"

#include <QBluetoothUuid>

#include "BluetoothLocalDeviceStatic.h"

BluetoothServer::BluetoothServer(QQuickItem* parent) :
    QQuickItem(parent),
    server(QBluetoothServiceInfo::RfcommProtocol, this)
{
    QList<QBluetoothHostInfo> adapters = QBluetoothLocalDevice::allDevices();
    if(adapters.size() <= 0)
        qWarning() << "BluetoothServer::BluetoothServer(): No local Bluetooth adapters found, BluetoothServer will not function. ";
    else
        localAdapterAddress = adapters[0].address().toString();
    channel = 0;
    connect(&server, SIGNAL(newConnection()), this, SLOT(publishConnections()));
}

BluetoothServer::~BluetoothServer(){
    server.close();
}

bool BluetoothServer::isListening() const {
    return server.isListening();
}

void BluetoothServer::setListening(bool enable){
    bool wasListening = server.isListening();

    if(enable){
        if(!server.listen(QBluetoothAddress(localAdapterAddress), (quint16)channel))
            qWarning() << "BluetoothServer::setListening(): Couldn't start listening: " << server.error();
    }
    else
        server.close();

    if(wasListening != server.isListening())
        emit listeningChanged();
}

void BluetoothServer::setChannel(int channel){
    if(channel < 0){
        qWarning() << "BluetoothServer::setChannel(): Given channel too small, setting to 0.";
        channel = 0;
    }
    else if(channel > 60){
        qWarning() << "BluetoothServer::setChannel(): Given channel too large, setting to 60.";
        channel = 60;
    }

    if(channel != this->channel){
        bool wasListening = isListening();
        setListening(false);
        this->channel = channel;
        if(wasListening)
            setListening(true);
        emit channelChanged();
    }
}

void BluetoothServer::setLocalAdapterAddress(QString localAdapterAddress){
    if(localAdapterAddress != this->localAdapterAddress){
        bool wasListening = isListening();
        setListening(false);
        this->localAdapterAddress = localAdapterAddress;
        if(wasListening)
            setListening(true);
        emit localAdapterAddressChanged();
    }
}

void BluetoothServer::publishConnections(){
    while(server.hasPendingConnections())
        emit newConnection(new BluetoothSocketExtended(server.nextPendingConnection(), this));
}
