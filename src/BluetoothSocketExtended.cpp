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
 * @file BluetoothSocketExtended.cpp
 * @brief QML wrapper source for QBluetoothSocket
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#include "BluetoothSocketExtended.h"

BluetoothSocketExtended::BluetoothSocketExtended(QQuickItem* parent):
    QQuickItem(parent)
{
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this);
    peerAddress = "00:00:00:00:00:00";
    channel = 1;
    connectSocketSignalSlots();
}

BluetoothSocketExtended::BluetoothSocketExtended(QBluetoothSocket* externalSocket, QQuickItem* parent):
    QQuickItem(parent)
{
    socket = externalSocket;
    peerAddress = socket->peerAddress().toString();
    channel = socket->peerPort();
    connectSocketSignalSlots();
}

BluetoothSocketExtended::~BluetoothSocketExtended(){
    socket->close();
    socket->deleteLater();
}

void BluetoothSocketExtended::connectSocketSignalSlots(){
    connect(socket, SIGNAL(connected()), this, SIGNAL(connected()));
    connect(socket, SIGNAL(disconnected()), this, SIGNAL(disconnected()));
    connect(socket, SIGNAL(error(QBluetoothSocket::SocketError)), this, SLOT(emitErrorAsInt(QBluetoothSocket::SocketError)));
    connect(socket, SIGNAL(readyRead()), this, SLOT(publish()));
}

void BluetoothSocketExtended::setPeerAddress(QString peerAddress){
    if(peerAddress != this->peerAddress){
        if(socket->state() != QBluetoothSocket::UnconnectedState)
            qWarning() << "BluetoothSocketExtended::setPeerAddress(): Can only set peer address while disconnected.";
        else{
            this->peerAddress = peerAddress;
            emit peerAddressChanged();
        }
    }
}

void BluetoothSocketExtended::setChannel(int channel){
    if(channel < 1){
        qWarning() << "BluetoothSocketExtended::setChannel(): Given channel too small, setting to 1.";
        channel = 1;
    }
    else if(channel > 60){
        qWarning() << "BluetoothSocketExtended::setChannel(): Given channel too large, setting to 60.";
        channel = 60;
    }

    if(channel != this->channel){
        if(socket->state() != QBluetoothSocket::UnconnectedState)
            qWarning() << "BluetoothSocketExtended::setChannel(): Can only set channel while disconnected.";
        else{
            this->channel = channel;
            emit channelChanged();
        }
    }
}

void BluetoothSocketExtended::connectToService(){
    socket->connectToService(QBluetoothAddress(peerAddress), (quint16)channel);
}

void BluetoothSocketExtended::disconnectFromService(){
    socket->disconnectFromService();
}

void BluetoothSocketExtended::emitErrorAsInt(QBluetoothSocket::SocketError socketError){
    emit error(socketError);
}

void BluetoothSocketExtended::publish(){
    QList<int> list;
    QByteArray receivedBytes = socket->readAll();
    for(char c : receivedBytes)
        list << (int)(*((unsigned char*)(&c)));
    emit bytesReceived(list);
}

bool BluetoothSocketExtended::writeBytes(QList<int> bytes){
    QByteArray container;
    for(int b : bytes){
        if(b < 0 || b > 0xFF){
            qWarning() << "BluetoothSocketExtended::writeBytes(): bytes contain integer not in [0x00,0xFF], not writing";
            return false;
        }
        else
            container.append((char)b);
    }

    int numBytesToWrite = container.size();
    const char* bytesRaw = container.constData();
    while(numBytesToWrite > 0){
        int bytesWritten = socket->write(bytesRaw, numBytesToWrite);
        if(bytesWritten < 0){
            qWarning() << "TcpSocket::writeBytes(): Bytes were not written: " << socket->errorString();
            return false;
        }
        numBytesToWrite -= bytesWritten;
        bytesRaw += bytesWritten;
    }

    return true;
}
