import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLBluetoothExtras 1.0

ApplicationWindow {
    id: window
    visible: true
    minimumHeight: height
    minimumWidth: width

    function getIntArr(str){
        var ret = [];
        for(var i=0;i<str.length;i++)
            ret.push(str.charCodeAt(i));
        return ret;
    }

    function getStr(intArr){
        var str = "";
        for(var i=0;i<intArr.length;i++)
            str += String.fromCharCode(intArr[i]);
        return str;
    }

    BluetoothServer{
        id: server

        uuid: "{00001101-0000-1000-8000-00805F9B34FB}" //Serial Port Profile
        name: "QML-BLUETOOTH-EXTRAS-SAMPLE-SERVER"

        onNewConnection: {
            serverSocket = socket;
            serverSocket.bytesReceived.connect(function(bytes){console.info("Server received: " + getStr(bytes)); });
            serverSocket.connected.connect(function(){console.info("Server socket connected."); });
            serverSocket.disconnected.connect(function(){console.info("Server socket disconnected."); });
            serverSocket.peerAddressChanged.connect(function(){console.info("Server socket peer address changed: " + serverSocket.peerAddress); });
            serverSocket.uuidChanged.connect(function(){console.info("Server socket uuid changed: " + serverSocket.uuid); });
        }
    }

    property var serverSocket: null

    BluetoothSocketExtented{
        id: clientSocket

        peerAddress: clientAddressField.text
        uuid: "{00001101-0000-1000-8000-00805F9B34FB}" //Serial Port Profile

        onBytesReceived: console.info("Client received: " + getStr(bytes))
        onConnected: console.info("Client socket connected")
        onDisconnected: console.info("Client socket disconnected")
        onPeerAddressChanged: console.info("Client socket peer address changed: " + peerAddress)
        onUuidChanged: console.info("Client socket uuid changed: " + uuid)
    }

    Row{
        GroupBox{
            title: "Server"

            Column{
                Button{
                    text: "Listen"
                    onClicked: {
                        server.listen = true;
                        console.info("Server stared listening.");
                    }
                }

                Button{
                    text: "Send from server"
                    onClicked: serverSocket.writeBytes(getIntArr("hello from server !!!"))
                }
            }
        }

        GroupBox{
            title: "Client"

            Column{
                TextField{
                    id: clientAddressField
                    placeholderText: "MAC address to connect to"
                    text: "XX:XX:XX:XX:XX:XX"
                }

                Button{
                    text: "Connect"
                    onClicked: clientSocket.connectToService()
                }

                Button{
                    text: "Disconnect"
                    onClicked: clientSocket.disconnectFromService()
                }

                Button{
                    text: "Send from client"
                    onClicked: clientSocket.writeBytes(getIntArr("hello from client !!!"))
                }
            }
        }
    }
}
