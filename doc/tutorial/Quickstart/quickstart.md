# Quickstart

[中文教程](quickstart_zh_CN.md)  
***
**On Windows**
***
## Use GUI with included client
(1) Download the GUI with included client on [release](https://github.com/wh201906/Proxmark3GUI/releases) page  
![](download_withclient.png)  

(2) Extract the .7z file to a path. The target path should not contain non-ASCII characters  
![](pm3guipath.png)  

(3) Open Proxmark3GUI.exe in the GUI folder, then select the language and click "OK". Now you can use it  
![](pm3gui.png)  
![](language.png)  

## Use the GUI with your own client
(1) Download the standalone GUI on [release](https://github.com/wh201906/Proxmark3GUI/releases) page  
![](download.png)  

(2) Extract the .7z file to a path. The target path should not contain non-ASCII characters. Make sure the client path and the GUI path are different.  

(3) Open the GUI. Input the client path in the "Client Path" editbox on the top of the main window.  
![](pm3path.png)  

(4) Go to "Settings" panel. Input the config file path which matching the client you use.  
![](configpath.png)  

(5) If setup.bat is required, input the script path in the "Preload script path" editbox.  
![](preloadpath.png)  

(6) If using RRG/Iceman repo, input "-p \<port\> -f" in the "Start arguments" editbox.  
![](args.png)  

***
**On Linux**
***
(1) Build the GUI by following the instructions on [README](../../../README.md)  
(2) Config the GUI with the same steps of "On Windows"->"Use the GUI with your own client"  
(3) You might need to change "\<port\>" to "/dev/\<port\>" in "Settings"->"Start arguments" editbox  
![](args_linux.png)  

(4) If you are using Raspbian(Raspberry OS), you might need to check "Keep the client active even the PM3 hardware is disconnected." in the "Settings" panel  
![](keep.png)  

## About preload script
The client might refer to some environment variables to load dependencies  
For example, the RRG client on Windows requires these environment variables  
```
QT_PLUGIN_PATH=<client path>\libs\
QT_QPA_PLATFORM_PLUGIN_PATH=<client path>\libs\
PATH=<client path>\libs\;<client path>\libs\shell\;<old PATH variable>
MSYSTEM=MINGW64
```
So the GUI will run "\<client path\>\\setup.bat" before loading the client, which will set the environment variables to the client properly. The script will not affect the system environment variables.  
The contents of setup.bat are as follows  
```
@echo off
set "HOME=%~dp0"
set "QT_PLUGIN_PATH=%HOME%\libs\"
set "QT_QPA_PLATFORM_PLUGIN_PATH=%QT_PLUGIN_PATH%"
set "PATH=%QT_PLUGIN_PATH%;%QT_PLUGIN_PATH%shell\;%PATH%"
set MSYSTEM=MINGW64
```
You can write your own script by referring to it if you need other client, then input the script path in the "Preload script path" editbox.  