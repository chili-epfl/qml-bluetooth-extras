qml-bluetooth-extras-local-devices-sample
=========================================

Example use of qml-bluetooth-extras in a local device enumeration scenario. Follow the build instructions in
[the qml-bluetooth-extras README](../../README.md) before trying to run this sample. It is tested with Qt 5.10.1 on the
following:

- Ubuntu 17.10
- macOS 10.13.3 with Xcode 9.3
- ~~Windows 10 (UWP x64 (MSVC 2017)) with Visual Studio 2017 Community (with `Universal Windows Platform development` and `C++ Universal Windows Platform tools`)~~ The functionality in this sample is not supported yet by WinRT
- Android 7.1.2 with Ubuntu 17.10 host with Android API 23, Android SDK Tools 25.2.5 and Android NDK r10e

build & run [Ubuntu & macOS & Android]
--------------------------------------

Load the project into QtCreator and press the Run button with the big green arrow.

build & run [Windows]
---------------------

  - Load the project into QtCreator, select the `Release` build (and not the `Debug` and `Profile` build)
  - Press the Run button with the big green arrow once, this will install and launch the app (you may have to enable `Developer mode` in `Settings` -> `Update & Security` -> `For developers` -> `Use developer features`; this windows will pop up anyway if you haven't enabled it already)
  - For all subsequent launches, use the app launcher now installed in the Start Menu
