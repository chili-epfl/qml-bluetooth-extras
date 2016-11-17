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
 * @brief QML wrapper header for QBluetoothServer
 * @author Ayberk Özgür
 * @date 2016-11-17
 */

#ifndef BLUETOOTHSERVER_H
#define BLUETOOTHSERVER_H

#include <QQuickItem>
#include <QBluetoothServer>

class BluetoothServer : public QQuickItem {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */

    Q_PROPERTY(bool listen READ isListening WRITE setListening NOTIFY listeningChanged)
    Q_PROPERTY(QString uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

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
     * @brief Gets the current service uuid
     *
     * @return Current uuid, e.g "{00001101-0000-1000-8000-00805F9B34FB}"
     */
    QString getUuid() const { return uuid; }

    /**
     * @brief Sets the service uuid
     *
     * @param host The new full uuid, e.g "{00001101-0000-1000-8000-00805F9B34FB}"
     */
    void setUuid(QString uuid);

    /**
     * @brief Gets the current service name
     *
     * @return Current service name
     */
    QString getName() const { return name; }

    /**
     * @brief Sets the service name
     *
     * @param host The new service name
     */
    void setName(QString name);

signals:

    /**
     * @brief Emitted when listening changes
     */
    void listeningChanged();

    /**
     * @brief Emitted when the service uuid changes
     */
    void uuidChanged();

    /**
     * @brief Emitted when the service name changes
     */
    void nameChanged();

    /**
     * @brief Emitted when a new socket is connected
     *
     * @param socket TODO
     */
    void newConnection();

private slots:

    /**
     * @brief Gets the incoming connections and publishes them each by newConnection()
     */
    void publishConnections();

private:

    QString uuid;                   ///< Service uuid, e.g "{00001101-0000-1000-8000-00805F9B34FB}"
    QString name;                   ///< Service name
    QBluetoothServer server;        ///< The QBluetoothServer object to wrap
    QBluetoothServiceInfo service;  ///< Service that is opened by listen()

};

#endif /* BLUETOOTHSERVER_H */
