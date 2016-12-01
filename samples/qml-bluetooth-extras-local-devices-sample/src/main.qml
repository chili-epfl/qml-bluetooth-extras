import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLBluetoothExtras 1.0

ApplicationWindow {
    id: window
    visible: true
    minimumHeight: height
    minimumWidth: width

    property var allDevices: BluetoothLocalDeviceStatic.allDevices()

    Column{
        Repeater{
            model: allDevices.length

            Row{
                id: row
                spacing: 5

                Text{ text: device.address + "; " + device.name + "; connected devices: " + device.connectedDevices }

                BluetoothLocalDevice{
                    id: device
                    address: allDevices[index]
                    onAddressChanged: powerOn()
                }
            }
        }
    }
}
