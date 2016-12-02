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

        localAdapterAddress: "5C:F3:70:7C:71:0D"
        channel: 20

        onNewConnection: {
            serverSocket = socket;
            serverSocket.bytesReceived.connect(function(bytes){console.log("Server received: " + getStr(bytes)); });
            serverSocket.connected.connect(function(){console.log("Server socket connected."); });
            serverSocket.disconnected.connect(function(){console.log("Server socket disconnected."); });
            serverSocket.peerAddressChanged.connect(function(){console.log("Server socket peer address changed: " + serverSocket.peerAddress); });
            serverSocket.channelChanged.connect(function(){console.log("Server socket channel changed: " + serverSocket.channel); });
        }
    }

    property var serverSocket: null

    BluetoothSocketExtented{
        id: clientSocket

        peerAddress: clientAddressField.text
        channel: 20

        onBytesReceived: console.log("Client received: " + getStr(bytes))
        onConnected: console.log("Client socket connected")
        onDisconnected: console.log("Client socket disconnected")
        onPeerAddressChanged: console.log("Client socket peer address changed: " + peerAddress)
        onChannelChanged: console.log("Client socket channel changed: " + channel)
    }

    Row{
        GroupBox{
            title: "Server"

            Column{
                Button{
                    text: "Listen"
                    onClicked: {
                        server.listen = true;
                        console.log("Server stared listening.");
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
                    text: "5C:F3:70:7C:71:0D"//"XX:XX:XX:XX:XX:XX"
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
