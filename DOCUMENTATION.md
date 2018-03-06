QML API
-------

### `BluetoothLocalDeviceStatic [Singleton]`

QML wrapper for static QBluetoothLocalDevice methods and enums.

**Enums:**

>  - **HostMode** : Same as http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum

**Slots:**

>  - **list&lt;string&gt; allDevices()**: Gets list of all local adapter MAC addresses

### `BluetoothLocalDevice`

QML wrapper for QBluetoothLocalDevice.

**Properties:**

>  - **address** :  `string` - Local adapter MAC address, can be set by the user to an existing local adapter address on Linux
>  - **hostMode** : `readonly HostMode` -  Host mode (i.e powered off, discoverable etc.)
>  - **name** :     `readonly string` -  Local adapter name
>  - **connectedDevices** : `readonly list<string>` - List of connected devices' MAC addresses, but see https://bugreports.qt.io/browse/QTBUG-57417. Doesn't work on Android.

**Slots:**

>  - **bool isValid()**: Gets whether the local adapter is valid
>  - **void powerOn()**: Powers the adapter on if possible

### `BluetoothServer`

QML wrapper for QBluetoothServer; listens for incoming connections. When a new connection is made, emits a
`BluetoothSocketExtended` that can be used in QML.

**Properties:**

>  - **listen** :   `bool` -    Whether to listen for incoming connections, default false
>  - **uuid** :     `string` -  UUID of the service to advertise, must be in full form, e.g "{00001101-0000-1000-8000-00805F9B34FB}" for SPP
>  - **name** :     `string` -  Name of the service to advertise, must be set to a nonempty string

**Signals:**

>  - **newConnection(BluetoothSocketExtended socket)**: Emitted when a new connection is made to the server

### `BluetoothSocketExtended`

QML wrapper for QBluetoothSocket with critical functionality missing in Qt's official BluetoothSocket.

**Properties:**

>  - **peerAddress** :  `string` -  MAC address to connect to, or address of the already open remote connection
>  - **uuid** :         `string` -  Service UUID to connect to, must be in full form, e.g "{00001101-0000-1000-8000-00805F9B34FB}" for SPP

**Signals:**

>  - **connected()** :                      Emitted when the socket connects
>  - **disconnected()** :                   Emitted when the socket disconnects
>  - **error(enum socketError)** :          Emitted when an error occurs
>  - **bytesReceived(list&lt;int&gt; bytes)** :   Emitted when new bytes arrive, all elements will be within [0x00, 0xFF]

**Slots:**

>  - **void connectToService()**:           Connects to the given peer address on the given service
>  - **void disconnectFromService()**:      Disconnects from the service
>  - **bool writeBytes(list&lt;int&gt; bytes)**:  Writes the bytes to the socket, each element must be within [0x00, 0xFF], returns whether all bytes were successfully written
