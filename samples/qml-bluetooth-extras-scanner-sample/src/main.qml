import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLBluetoothExtras 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 400
    height: 800

    Column{
        id: column

        spacing: 5

        CheckBox{
            id: scanForClassic
            text: "Scan for Classic devices?"
            checked: true
        }

        CheckBox{
            id: scanForLE
            text: "Scan for Low Energy devices?"
            checked: true
        }

        Button{
            text: "Start"
            onClicked: {
                devices.text = "";
                scanner.start();
            }
        }

        Button{
            text: "Stop"
            onClicked: scanner.stop()
        }

        Button{
            text: "Clear"
            onClicked: {
                devices.text = "";
                scanner.clear();
            }
        }

        BusyIndicator{
            running: scanner.scanning
            height: scanForClassic.height
        }
    }

    TextArea{
        id: devices
        readOnly: true
        width: window.width
        anchors.top: column.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
    }

    BluetoothScanner{
        id: scanner
        scanForClassic: scanForClassic.checked
        scanForLE: scanForLE.checked
        onDeviceDiscovered: devices.text += macAddr + " - " + name + "\n"
    }
}
