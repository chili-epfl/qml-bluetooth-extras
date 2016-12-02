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
 * @file BluetoothServer.h
 * @brief QML wrapper header for QBluetoothServer (only RFCOMM)
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#ifndef BLUETOOTHSERVER_H
#define BLUETOOTHSERVER_H

#include <QQuickItem>
#include <QBluetoothServer>

#include "BluetoothSocketExtended.h"

class BluetoothServer : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    Q_PROPERTY(bool listen READ isListening WRITE setListening NOTIFY listeningChanged)
    Q_PROPERTY(QString localAdapterAddress READ getLocalAdapterAddress WRITE setLocalAdapterAddress NOTIFY localAdapterAddressChanged)
    Q_PROPERTY(int channel READ getChannel WRITE setChannel NOTIFY channelChanged)

public:

    /**
     * @brief Creates a new BluetoothServer with the given QML parent
     *
     * @param parent The QML parent
     */
    BluetoothServer(QQuickItem* parent = 0);

    /**
     * @brief Destroys this BluetoothServer
     */
    ~BluetoothServer();

    /**
     * @brief Gets whether the server is listening
     *
     * @return Whether the server is listening
     */
    bool isListening() const;

    /**
     * @brief Enables/disables listening
     *
     * @param enable Whether to listen or close the server and stop listening
     */
    void setListening(bool enable);

    /**
     * @brief Gets the local adapter MAC address that this server is supposed to listen on
     *
     * @return Local adapter MAC address that this server is supposed to listen on
     */
    QString getLocalAdapterAddress() const { return localAdapterAddress; }

    /**
     * @brief Sets the local adapter MAC address that this server is supposed to listen on
     *
     * Local adapter with given address must exist.
     * Setting this to a different address resets the server if already listening.
     *
     * @param localAdapterAddress Local adapter MAC address that this server is supposed to listen on
     */
    void setLocalAdapterAddress(QString localAdapterAddress);

    /**
     * @brief Gets the desired channel or automatically set channel upon listen
     *
     * @return The RFCOMM channel
     */
    int getChannel() const { return channel; }

    /**
     * @brief Channel to listen to, must be already unoccupied; set to 0 to choose automatically
     *
     * Setting this to a different channel resets the server if already listening.
     *
     * @param channel 0 to choose automatically or a value in [1,60] chosen manually
     */
    void setChannel(int channel);

signals:

    /**
     * @brief Emitted when listening changes
     */
    void listeningChanged();

    /**
     * @brief Emitted when the local adapter address changes
     */
    void localAdapterAddressChanged();

    /**
     * @brief Emitted when the channel changes
     */
    void channelChanged();

    /**
     * @brief Emitted when a new socket is connected
     *
     * @param socket Newly connected socket
     */
    void newConnection(BluetoothSocketExtended* socket);

private slots:

    /**
     * @brief Gets the incoming connections and publishes them each by newConnection()
     */
    void publishConnections();

private:

    QString localAdapterAddress;    ///< MAC address of the desired local adapter
    quint16 channel;                ///< Desired RFCOMM channel, or automatically set channel upon listen
    QBluetoothServer server;        ///< The QBluetoothServer object to wrap

};

#endif /* BLUETOOTHSERVER_H */
