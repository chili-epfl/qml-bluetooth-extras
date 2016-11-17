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
 * @brief QML wrapper source for QBluetoothServer
 * @author Ayberk Özgür
 * @date 2016-11-10
 */

#include "BluetoothServer.h"

#include <QBluetoothUuid>

BluetoothServer::BluetoothServer(QQuickItem* parent):
    QQuickItem(parent),
    server(QBluetoothServiceInfo::RfcommProtocol, this)
{
    uuid = "{00000000-0000-0000-0000-000000000000}";
    name = "";
    connect(&server, SIGNAL(newConnection()), this, SLOT(publishConnections()));
}

BluetoothServer::~BluetoothServer(){
    service.unregisterService();
    server.close();
}

bool BluetoothServer::isListening() const{
    return server.isListening();
}

void BluetoothServer::setListening(bool enable){
    bool wasListening = server.isListening();

    if(enable){
        service = server.listen(QBluetoothUuid(uuid), name);
        if(!service.isValid())
            qWarning() << "BluetoothServer::setListening(): Couldn't start listening: " << server.error();
    }
    else{
        service.unregisterService();
        server.close();
    }

    if(wasListening != server.isListening())
        emit listeningChanged();
}

void BluetoothServer::setUuid(QString uuid){
    if(uuid != this->uuid){
        if(QBluetoothUuid(uuid) == QBluetoothUuid(QString("{00000000-0000-0000-0000-000000000000}")))
            qWarning() << "BluetoothServer::setUuid(QString): Invalid uuid. ";
        else{
            bool wasListening = isListening();
            setListening(false);
            this->uuid = uuid;
            if(wasListening)
                setListening(true);
            emit uuidChanged();
        }
    }
}

void BluetoothServer::setName(QString name){
    if(name != this->name){
        bool wasListening = isListening();
        setListening(false);
        this->name = name;
        if(wasListening)
            setListening(true);
        emit nameChanged();
    }
}

void BluetoothServer::publishConnections(){
    while(server.hasPendingConnections())
        emit newConnection(new BluetoothSocketExtended(server.nextPendingConnection(), this));
}
