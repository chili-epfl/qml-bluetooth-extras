TEMPLATE = lib
TARGET = qmlbluetoothextrasplugin

CONFIG += qt plugin c++11
CONFIG -= android_install

QT += qml quick bluetooth

unix{
    QMAKE_CXXFLAGS -= -O2
    QMAKE_CXXFLAGS_RELEASE -= -O2

    QMAKE_CXXFLAGS += -O3
    QMAKE_CXXFLAGS_RELEASE += -O3
}

TARGET = $$qtLibraryTarget($$TARGET)
uri = QMLBluetoothExtras

HEADERS += \
    src/QMLBluetoothExtrasPlugin.h \
    src/classic/BluetoothServer.h \
    src/classic/BluetoothSocketExtended.h \
    src/BluetoothLocalDeviceStatic.h \
    src/BluetoothLocalDevice.h \
    src/BluetoothScanner.h

SOURCES += \
    src/QMLBluetoothExtrasPlugin.cpp \
    src/classic/BluetoothServer.cpp \
    src/classic/BluetoothSocketExtended.cpp \
    src/BluetoothLocalDeviceStatic.cpp \
    src/BluetoothLocalDevice.cpp \
    src/BluetoothScanner.cpp

OTHER_FILES += qmldir

#Install plugin library, qmldir
qmldir.files = qmldir
installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
qmldir.path = $$installPath
target.path = $$installPath
INSTALLS += target qmldir
