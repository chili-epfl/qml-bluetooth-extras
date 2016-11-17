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
 * @file BluetoothSocketExtended.h
 * @brief QML wrapper header for QBluetoothSocket
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#ifndef BLUETOOTHSOCKETEXTENDED_H
#define BLUETOOTHSOCKETEXTENDED_H

#include <QQuickItem>
#include <QBluetoothSocket>
#include <QList>

class BluetoothSocketExtended : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    Q_PROPERTY(QString peerAddress READ getPeerAddress WRITE setPeerAddress NOTIFY peerAddressChanged)
    Q_PROPERTY(QString uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)

public:

    /**
     * @brief Creates a new BluetoothSocketExtended with the given QML parent
     *
     * @param parent The QML parent
     */
    BluetoothSocketExtended(QQuickItem* parent = 0);

    /**
     * @brief Creates a new TcpSocket with the given QML parent with an existing QBluetoothSocket
     *
     * @param externalSocket Descriptor to the external native socket that was opened outside this wrapper, calls deleteLater() on it in the end
     * @param parent The QML parent
     */
    BluetoothSocketExtended(QBluetoothSocket* externalSocket, QQuickItem* parent = 0);

    /**
     * @brief Destroys this BluetoothSocketExtended
     */
    ~BluetoothSocketExtended();

    /**
     * @brief Gets the current peer MAC address
     *
     * @return Current peer MAC address, e.g "XX:XX:XX:XX:XX:XX"
     */
    QString getPeerAddress() const { return peerAddress; }

    /**
     * @brief Sets the peer MAC address to connect to
     *
     * @param peer The new peer MAC address, e.g "XX:XX:XX:XX:XX:XX"
     */
    void setPeerAddress(QString peerAddress);

    /**
     * @brief Gets the current uuid
     *
     * @return Current uuid
     */
    QString getUuid() const { return uuid; }

    /**
     * @brief Sets the uuid to connect to
     *
     * @param port The new full uuid, e.g "{00001101-0000-1000-8000-00805F9B34FB}"
     */
    void setUuid(QString uuid);

public slots:

    /**
     * @brief Initiates a connection to the service on the peer
     */
    void connectToService();

    /**
     * @brief Starts closing the socket
     */
    void disconnectFromService();

    /**
     * @brief Writes bytes over the socket
     *
     * @param bytes Bytes to write, all must be within [0x00,0xFF]
     * @return Whether all bytes were successfully written
     */
    bool writeBytes(QList<int> bytes);

signals:

    /**
     * @brief Emitted when the peer MAC address changes
     */
    void peerAddressChanged();

    /**
     * @brief Emitted whe the service uuid changes
     */
    void uuidChanged();

    /**
     * @brief Emitted when the socket is connected
     */
    void connected();

    /**
     * @brief Emitted when the socket is disconected
     */
    void disconnected();

    /**
     * @brief Emitted when there is an error
     *
     * @param socketError The error of QBluetoothSocket::SocketError type (see http://doc.qt.io/qt-5/qbluetoothsocket.html#SocketError-enum)
     */
    void error(int socketError);

    /**
     * @brief Emitted when some bytes are received
     *
     * @param message Byte array that was received, all elements are guaranteed to be in [0x00, 0xFF]
     */
    void bytesReceived(QList<int> bytes);

private slots:

    /**
     * @brief Publishes all available received bytes via bytesReceived(QVariant)
     */
    void publish();

    /**
     * @brief Emits error(int socketError)
     *
     * @param socketError The socket error to emit
     */
     void emitErrorAsInt(QBluetoothSocket::SocketError socketError);

private:

    /**
     * @brief Connects low level socket signal/slots to this wrapper
     */
    void connectSocketSignalSlots();

    QBluetoothSocket* socket;   ///< The low level socket
    QString peerAddress;        ///< Peer MAC address
    QString uuid;               ///< Service uuid to connect to

};

Q_DECLARE_METATYPE(BluetoothSocketExtended*)

#endif /* BLUETOOTHSOCKETEXTENDED_H */
