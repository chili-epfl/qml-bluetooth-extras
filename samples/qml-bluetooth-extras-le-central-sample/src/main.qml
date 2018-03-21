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

        Button{
            text: "connect"
            onClicked: lecentral.connectToDevice()
        }

        Button{
            text: "get state"
            onClicked: console.info("state: " + lecentral.state())
        }

        Button{
            text: "get error"
            onClicked: console.info("error: " + lecentral.error())
        }

        Button{
            text: "discover services"
            onClicked: lecentral.discoverServices()
        }

        Button{
            text: "services"
            onClicked: console.info("services: " + lecentral.services().join('\n'))
        }
    }

    LowEnergyCentral{
        id: lecentral
        remoteAddr: "24:4B:81:16:98:7D"
        localAddr: "00:1A:7D:DA:71:03"
        onConnected: console.info("Connected!")
        onDiscoveryFinished: console.info("Discovery finished!")
    }
}
