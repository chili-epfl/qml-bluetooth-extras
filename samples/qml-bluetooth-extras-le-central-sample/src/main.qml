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
    }

    LowEnergyCentral{
        id: lecentral
        //remoteAddr:
        //localAddr:

    }
}
