# Work with ProxSpace
This GUI supports clients built from ProxSpace, making it easier to use the latest client with this GUI.  

## 1. Set up ProxSpace  
Please refer to this tutorial to set up ProxSpace and compile Proxmark3 client:  
https://github.com/Gator96100/ProxSpace/blob/HEAD/README.md  

After that, you will get a folder structure like this:  
```
.
├── autobuild.bat
├── msys2
│   ├── autorebase.bat
│   └── ......
├── pm3
│   └── proxmark3
│       ├── client
│       ├── ......
│       ├── pm3
│       ├── README.md
│       └── ......
├── README.md
├── runme64.bat
└── setup
    └── ......
```
The proxmark3 repository is located in `./pm3/proxmark3`

## 2. Download GUI
You can download prebuilt binaries there.  
[Prebuilt binaries](../../../README.md#download-binaries-for-windows)  
Please download a version without the client, like `V0.2.7-win64.7z`.  
After downloading, extract it to a path without non-ASCII characters and spaces. Plus, the target folder should not be the same as the proxmark3 repository.  
For example, if you extract it to ./pm3/GUI/, you will get a folder structure like this:  
```
.
├── autobuild.bat
├── msys2
│   ├── autorebase.bat
│   └── ......
├── pm3
│   ├── GUI
│   │   └── V0.2.7-win64
│   │       ├── plugins
│   │       ├── Proxmark3GUI.exe
│   │       └── ......
│   └── proxmark3
│       ├── client
│       ├── ......
│       ├── pm3
│       ├── README.md
│       └── ......
├── README.md
├── runme64.bat
└── setup
    └── ......
```

## 3. Run the GUI in ProxSpace
Double-click `./runme64.bat` to run the ProxSpace. Now the working directory is `./pm3`.  
In the terminal of ProxSpace, run `cd GUI` to go to the `./pm3/GUI`, then run `./V0.2.7-win64/Proxmark3GUI.exe` to open the GUI.  
***  
**Note:** You can run the GUI in your preferred folder, but please avoid running it in the same directory as the GUI itself, otherwise it will cause errors when loading the client.  
Using the directory structure above as an example, you can first run `cd /pm3` to set the working directory to `/pm3`, then run `./V0.2.7-win64/Proxmark3GUI.exe` to open the GUI.  
However, you should not first run `cd /pm3/GUI/V0.2.7-win64` and then run `./Proxmark3GUI.exe`.  

## 4. Connect to the device in GUI

## Specify the Client Path
Using the directory structure above as an example, assuming the current working directory is `./pm3/GUI`, and the client path is `./pm3/proxmark3/client/proxmark3.exe`, you need to enter `../proxmark3/client/proxmark3.exe` in the `Client Path`.

## Clear the Preload Script Path
The GUI is launched in ProxSpace so it includes the necessary environment variables for the client, there is no need to use any preload script.

## Select the Config File
Depending on the client version, you need to select the corresponding config file. For example, select `config_official.json` for the official client, and select `config_rrgv4.15864.json` for the rrg version v4.15864. If your client version is not listed, try selecting the config file with a similar version number.  

## Connect to the Device
Select the port number of the PM3 hardware, then click `Connect`.
