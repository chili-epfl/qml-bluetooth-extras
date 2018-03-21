# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`QMLBluetoothExtras`](#namespaceQMLBluetoothExtras) | QML wrappers for missing Qt Bluetooth objects.

# namespace `QMLBluetoothExtras` 

QML wrappers for missing Qt Bluetooth objects.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`QMLBluetoothExtras::BluetoothLocalDevice`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice) | QML wrapper around QBluetoothLocalDevice.
`class `[`QMLBluetoothExtras::BluetoothLocalDeviceStatic`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic) | Object for exposing QBluetoothLocalDevice enums and static methods to QML.
`class `[`QMLBluetoothExtras::BluetoothScanner`](#classQMLBluetoothExtras_1_1BluetoothScanner) | Object that scans for Bluetooth devices.
`class `[`QMLBluetoothExtras::BluetoothServer`](#classQMLBluetoothExtras_1_1BluetoothServer) | QML wrapper for QBluetoothServer.
`class `[`QMLBluetoothExtras::BluetoothSocketExtended`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended) | QML wrapper for QBluetoothSocket.

# class `QMLBluetoothExtras::BluetoothLocalDevice` 

```
class QMLBluetoothExtras::BluetoothLocalDevice
  : public QQuickItem
```  

QML wrapper around QBluetoothLocalDevice.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} `[`QMLBluetoothExtras::BluetoothLocalDeviceStatic::HostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1a45fc999b746711ef44eae85901c551db)` `[`hostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1ae96d441025430705ae923f873397db70) | Current read-only host mode as described in [http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum](http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum).
`{property} QString `[`name`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a19fc16a2a82917678bf1bbb904d760a8) | Read-only local adapter name.
`{property} QString `[`address`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a195dffc10b4fd2e84f7b8108e1ba82dc) | Desired local adapter address.
`{property} QStringList `[`connectedDevices`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a1ac902e032c44402be823c69480d59af) | Read-only list of currently connected remote devices over this adapter.
`{slot} public bool `[`isValid`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1abcf97645d513f1369ac49f81dc198c46)`() const` | Gets whether this local adapter exists.
`{slot} public void `[`powerOn`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1ae378dbf8b47332b60b3c7010cf787f21)`()` | Powers this adapter on.

## Members

#### `{property} `[`QMLBluetoothExtras::BluetoothLocalDeviceStatic::HostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1a45fc999b746711ef44eae85901c551db)` `[`hostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1ae96d441025430705ae923f873397db70) 

Current read-only host mode as described in [http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum](http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum).

#### `{property} QString `[`name`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a19fc16a2a82917678bf1bbb904d760a8) 

Read-only local adapter name.

#### `{property} QString `[`address`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a195dffc10b4fd2e84f7b8108e1ba82dc) 

Desired local adapter address.

#### `{property} QStringList `[`connectedDevices`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1a1ac902e032c44402be823c69480d59af) 

Read-only list of currently connected remote devices over this adapter.

#### `{slot} public bool `[`isValid`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1abcf97645d513f1369ac49f81dc198c46)`() const` 

Gets whether this local adapter exists.

#### Returns
Whether this local adapter exists and is available

#### `{slot} public void `[`powerOn`](#classQMLBluetoothExtras_1_1BluetoothLocalDevice_1ae378dbf8b47332b60b3c7010cf787f21)`()` 

Powers this adapter on.

# class `QMLBluetoothExtras::BluetoothLocalDeviceStatic` 

```
class QMLBluetoothExtras::BluetoothLocalDeviceStatic
  : public QObject
```  

Object for exposing QBluetoothLocalDevice enums and static methods to QML.

This class is **singleton**, you can call `ThisClass.anyFunction()` and use `ThisClass.anyProperty` directly.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{slot} public static QStringList `[`allDevices`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1af6884eb78ffae0f50be09a18a80a2cb0)`()` | Gets the list of the MAC addresses of all local adapters.
`enum `[`HostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1a45fc999b746711ef44eae85901c551db) | Host modes as described in [http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum](http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum).

## Members

#### `{slot} public static QStringList `[`allDevices`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1af6884eb78ffae0f50be09a18a80a2cb0)`()` 

Gets the list of the MAC addresses of all local adapters.

#### Returns
List of MAC addresses of all local adapters

#### `enum `[`HostMode`](#classQMLBluetoothExtras_1_1BluetoothLocalDeviceStatic_1a45fc999b746711ef44eae85901c551db) 

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
HostModePoweredOff            | Powered off.
HostModeConnectable            | Connectable but not discoverable.
HostModeDiscoverable            | Discoverable and connectable.
HostModeDiscoverableLimitedInquiry            | ?

Host modes as described in [http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum](http://doc.qt.io/qt-5/qbluetoothlocaldevice.html#HostMode-enum).

# class `QMLBluetoothExtras::BluetoothScanner` 

```
class QMLBluetoothExtras::BluetoothScanner
  : public QQuickItem
```  

Object that scans for Bluetooth devices.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} bool `[`continuous`](#classQMLBluetoothExtras_1_1BluetoothScanner_1af4431336acc6a5c1b86e13d5ae8f91fa) | Whether to scan continuously, default false.
`{property} bool `[`scanForClassic`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a94fe7229e5883dbca85f0d7050b6384d) | Whether to scan for Bluetooth Classic devices (v2.1 and earlier, if supported), default true.
`{property} bool `[`scanForLE`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a1cc1cd51229bc649dcce9111c798489a) | Whether to scan for Bluetooth Low Energy devices (v4.0 and later, if supported), default true.
`{property} bool `[`scanning`](#classQMLBluetoothExtras_1_1BluetoothScanner_1af50cafed435e16787d6aae3cbf5312ae) | Whether scanning now, read-only.
`{property} QStringList `[`discoveredDevices`](#classQMLBluetoothExtras_1_1BluetoothScanner_1abe58446c95c7a5f87eedd0407613cb78) | List of discovered device MAC addresses, read-only.
`{signal} public void `[`deviceDiscovered`](#classQMLBluetoothExtras_1_1BluetoothScanner_1ae2151722b182b8218d1f7f602de7d188)`(QString const & macAddr,QString const & name)` | Emitted when a new device is discovered.
`{signal} public void `[`finished`](#classQMLBluetoothExtras_1_1BluetoothScanner_1ae7f75e3ae9c29946d5202aa3a7370bdf)`()` | Emitted when scanning finishes.
`{slot} public void `[`start`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a0dcc066b0608c8365300ee0c23e88d73)`()` | Starts scanning.
`{slot} public void `[`stop`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a187335be5166147f691034ac3d0c73f5)`()` | Stops scanning.
`{slot} public void `[`clear`](#classQMLBluetoothExtras_1_1BluetoothScanner_1acbaebf91fd08073fdf6d803b06dc0787)`()` | Clears the list of found robots.

## Members

#### `{property} bool `[`continuous`](#classQMLBluetoothExtras_1_1BluetoothScanner_1af4431336acc6a5c1b86e13d5ae8f91fa) 

Whether to scan continuously, default false.

Whether to continuously scan.

#### `{property} bool `[`scanForClassic`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a94fe7229e5883dbca85f0d7050b6384d) 

Whether to scan for Bluetooth Classic devices (v2.1 and earlier, if supported), default true.

Whether to scan for Bluetooth Classic devices.

#### `{property} bool `[`scanForLE`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a1cc1cd51229bc649dcce9111c798489a) 

Whether to scan for Bluetooth Low Energy devices (v4.0 and later, if supported), default true.

Whether to scan for Bluetooth Low Energy devices.

#### `{property} bool `[`scanning`](#classQMLBluetoothExtras_1_1BluetoothScanner_1af50cafed435e16787d6aae3cbf5312ae) 

Whether scanning now, read-only.

#### `{property} QStringList `[`discoveredDevices`](#classQMLBluetoothExtras_1_1BluetoothScanner_1abe58446c95c7a5f87eedd0407613cb78) 

List of discovered device MAC addresses, read-only.

List of device MAC addresses that are discovered.

#### `{signal} public void `[`deviceDiscovered`](#classQMLBluetoothExtras_1_1BluetoothScanner_1ae2151722b182b8218d1f7f602de7d188)`(QString const & macAddr,QString const & name)` 

Emitted when a new device is discovered.

#### Parameters
* `macAddr` Mac address of the newly discovered device 

* `name` Name of the discovered device if available

#### `{signal} public void `[`finished`](#classQMLBluetoothExtras_1_1BluetoothScanner_1ae7f75e3ae9c29946d5202aa3a7370bdf)`()` 

Emitted when scanning finishes.

#### `{slot} public void `[`start`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a0dcc066b0608c8365300ee0c23e88d73)`()` 

Starts scanning.

#### `{slot} public void `[`stop`](#classQMLBluetoothExtras_1_1BluetoothScanner_1a187335be5166147f691034ac3d0c73f5)`()` 

Stops scanning.

#### `{slot} public void `[`clear`](#classQMLBluetoothExtras_1_1BluetoothScanner_1acbaebf91fd08073fdf6d803b06dc0787)`()` 

Clears the list of found robots.

# class `QMLBluetoothExtras::BluetoothServer` 

```
class QMLBluetoothExtras::BluetoothServer
  : public QQuickItem
```  

QML wrapper for QBluetoothServer.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} bool `[`listen`](#classQMLBluetoothExtras_1_1BluetoothServer_1a2c245ffd03d8defc241d1c9364d3f5f3) | Whether to listen for incoming connections.
`{property} QString `[`uuid`](#classQMLBluetoothExtras_1_1BluetoothServer_1ad4af8eda2c446ab025c22dfb20c08726) | The advertised service UUID, e.g {00001101-0000-1000-8000-00805F9B34FB}.
`{property} QString `[`name`](#classQMLBluetoothExtras_1_1BluetoothServer_1a4d5e6bb32048012af60e229c7c5e02e8) | The advertised service name, e.g {00001101-0000-1000-8000-00805F9B34FB}.
`{signal} public void `[`newConnection`](#classQMLBluetoothExtras_1_1BluetoothServer_1ad45561fa2dd3db0915356d258a1db82d)`(`[`QMLBluetoothExtras::BluetoothSocketExtended`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended)` * socket)` | Emitted when a new socket is connected.

## Members

#### `{property} bool `[`listen`](#classQMLBluetoothExtras_1_1BluetoothServer_1a2c245ffd03d8defc241d1c9364d3f5f3) 

Whether to listen for incoming connections.

#### `{property} QString `[`uuid`](#classQMLBluetoothExtras_1_1BluetoothServer_1ad4af8eda2c446ab025c22dfb20c08726) 

The advertised service UUID, e.g {00001101-0000-1000-8000-00805F9B34FB}.

Service uuid, e.g "{00001101-0000-1000-8000-00805F9B34FB}".

#### `{property} QString `[`name`](#classQMLBluetoothExtras_1_1BluetoothServer_1a4d5e6bb32048012af60e229c7c5e02e8) 

The advertised service name, e.g {00001101-0000-1000-8000-00805F9B34FB}.

Service name.

#### `{signal} public void `[`newConnection`](#classQMLBluetoothExtras_1_1BluetoothServer_1ad45561fa2dd3db0915356d258a1db82d)`(`[`QMLBluetoothExtras::BluetoothSocketExtended`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended)` * socket)` 

Emitted when a new socket is connected.

#### Parameters
* `socket` Newly connected socket

# class `QMLBluetoothExtras::BluetoothSocketExtended` 

```
class QMLBluetoothExtras::BluetoothSocketExtended
  : public QQuickItem
```  

QML wrapper for QBluetoothSocket.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} QString `[`peerAddress`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1aeb0dcd795f821ef20df1191dc4e3414d) | MAC address to connect to, or address of the already open remote connection.
`{property} QString `[`uuid`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a80da2a461233fa351415119d57fc9c9a) | Service UUID to connect to, must be in full form, e.g "{00001101-0000-1000-8000-00805F9B34FB}" for SPP.
`{signal} public void `[`connected`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1ab12ebc600d90ee3d3f18df27979a39a3)`()` | Emitted when the socket is connected.
`{signal} public void `[`disconnected`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1afaac8e605578a3196e3563f174710db2)`()` | Emitted when the socket is disconected.
`{signal} public void `[`error`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1ae57fc1928e6770fda0fffef4aca63892)`(int socketError)` | Emitted when there is an error.
`{signal} public void `[`bytesReceived`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a1f38f46a4e79741d04a0476efd181b26)`(QList< int > bytes)` | Emitted when some bytes are received.
`{slot} public void `[`connectToService`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a2c3df7dede4cddf6e8438394db68c5a4)`()` | Initiates a connection to the service on the peer.
`{slot} public void `[`disconnectFromService`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a9dbe52745967d790c9e5fdcd592f2a7a)`()` | Starts closing the socket.
`{slot} public bool `[`writeBytes`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1aa54ad15b99fea43115b551d1d617871f)`(QList< int > bytes)` | Writes bytes over the socket.

## Members

#### `{property} QString `[`peerAddress`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1aeb0dcd795f821ef20df1191dc4e3414d) 

MAC address to connect to, or address of the already open remote connection.

Peer MAC address.

#### `{property} QString `[`uuid`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a80da2a461233fa351415119d57fc9c9a) 

Service UUID to connect to, must be in full form, e.g "{00001101-0000-1000-8000-00805F9B34FB}" for SPP.

Service uuid to connect to.

#### `{signal} public void `[`connected`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1ab12ebc600d90ee3d3f18df27979a39a3)`()` 

Emitted when the socket is connected.

#### `{signal} public void `[`disconnected`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1afaac8e605578a3196e3563f174710db2)`()` 

Emitted when the socket is disconected.

#### `{signal} public void `[`error`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1ae57fc1928e6770fda0fffef4aca63892)`(int socketError)` 

Emitted when there is an error.

#### Parameters
* `socketError` The error of QBluetoothSocket::SocketError type (see [http://doc.qt.io/qt-5/qbluetoothsocket.html#SocketError-enum](http://doc.qt.io/qt-5/qbluetoothsocket.html#SocketError-enum))

#### `{signal} public void `[`bytesReceived`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a1f38f46a4e79741d04a0476efd181b26)`(QList< int > bytes)` 

Emitted when some bytes are received.

#### Parameters
* `message` Byte array that was received, all elements are guaranteed to be in [0x00, 0xFF]

#### `{slot} public void `[`connectToService`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a2c3df7dede4cddf6e8438394db68c5a4)`()` 

Initiates a connection to the service on the peer.

#### `{slot} public void `[`disconnectFromService`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1a9dbe52745967d790c9e5fdcd592f2a7a)`()` 

Starts closing the socket.

#### `{slot} public bool `[`writeBytes`](#classQMLBluetoothExtras_1_1BluetoothSocketExtended_1aa54ad15b99fea43115b551d1d617871f)`(QList< int > bytes)` 

Writes bytes over the socket.

#### Parameters
* `bytes` Bytes to write, all must be within [0x00,0xFF] 

#### Returns
Whether all bytes were successfully written

Generated by [Moxygen](https://sourcey.com/moxygen)