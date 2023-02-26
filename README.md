# Proxmark3GUI
[![downloads](https://img.shields.io/github/downloads/wh201906/Proxmark3GUI/total?label=GitHub%20release%20downloads)](https://github.com/wh201906/Proxmark3GUI/releases)  
[![downloads](https://img.shields.io/sourceforge/dt/proxmark3gui.svg?label=SourceForge%20downloads)](https://sourceforge.net/projects/proxmark3gui/)  

A cross-platform GUI for [Proxmark3](https://github.com/Proxmark/proxmark3)/[Proxmark3 Iceman fork](https://github.com/RfidResearchGroup/proxmark3) client  

(The [orignal Proxmark3 repo](https://github.com/Proxmark/proxmark3) has been unmaintained for a long time. I personally suggest using the [Proxmark3 Iceman fork](https://github.com/RfidResearchGroup/proxmark3))

[中文介绍](doc/README/README_zh_CN.md)

***

## Features

+ Easy to find available Serial Port
+ Support raw commands of Proxmark3 client(Official/Iceman)
+ Have a friendly UI to test Mifare cards
    + Support different card size(MINI, 1K, 2K, 4K)
    + Easy to edit Mifare block data
    + Easy to read all/selected blocks with well-designed read logic
    + Easy to write all/selected blocks
    + Support binary(.bin .dump) files and text(.eml) files
    + Analyze Access Bits
    + Support Chinese Magic Card
+ Have basic support for LF commands
+ Customize UI  
+ ...  

***

## Preview
![preview](doc/README/preview.png)  

[more previews](doc/preview/previews.md)  

***

## About Compiled Windows clients

A cool guy [Gator96100](https://github.com/Gator96100) creates [ProxSpace](https://github.com/Gator96100/ProxSpace) and makes it possible to compile both the firmware and the client on Windows.  
Also, he makes the [pre-compiled Windows client](https://www.proxmarkbuilds.org/) so you can download it and run your PM3 client on Windows instantly.  
I included his compiled client in my releases so you can use the GUI on the fly, and you can also use the GUI with your prefered client.  
Great thanks to him.  

***

## Download binaries for Windows 
You can download pre-built Windows binaries in [release](https://github.com/wh201906/Proxmark3GUI/releases) page  
`Vx.x.x-win64.7z` only contains the GUI  
`Vx.x.x-win64-xxxxxxx.7z` contains the GUI and corresponding client. You just need to open `Vx.x.x-win64-xxxxxxx\GUI\Proxmark3GUI.exe`  

You can also download them in SourceForge  
[![Download Proxmark3GUI](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/proxmark3gui/files/latest/download)  

## Build on Linux
```
cd ~
sudo apt-get update
sudo apt-get install git build-essential
sudo apt-get install qt5-default libqt5serialport5-dev
git clone https://github.com/wh201906/Proxmark3GUI.git --depth=1
cd Proxmark3GUI
mkdir build && cd build
qmake ../src
make -j4 && make clean
./Proxmark3GUI
```

## Build on macOS
```
cd ~
brew update
brew install qt@5
brew link qt5 --force
git clone https://github.com/wh201906/Proxmark3GUI.git --depth=1
cd Proxmark3GUI
mkdir build && cd build
qmake ../src
make -j4 && make clean
open Proxmark3GUI.app
```

> In order for the GUI to connect to the device in macOS, you'd need to tweak the settings a little bit

![macOS_settings](doc/README/macOS_settings.png)

***
## Tutorial

[1.Quickstart](doc/tutorial/Quickstart/quickstart.md)  
[2.Edit Mifare Classic data](doc/tutorial/Edit_Mifare_Classic_data/Edit_Mifare_Classic_data.md)(Proxmark3 hardware is not necessary)  
***

## Change Log
[Change Log](CHANGELOG.md)
