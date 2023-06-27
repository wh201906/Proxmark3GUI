# 使用ProxSpace编译的客户端

[English](work_with_proxspace.md)  
此GUI可以和ProxSpace编译出来的客户端配合运行，满足一部分用户使用最新版客户端的需求  

## 1. 搭建ProxSpace环境  
请参考此教程搭建ProxSpace环境并编译proxmark3客户端:  
https://github.com/Gator96100/ProxSpace/blob/HEAD/README.md  

搭建完成后，你将会获得如下的目录结构：
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
其中proxmark3仓库位于 `./pm3/proxmark3`

## 2. 下载GUI
你可以在此处下载编译好的客户端  
[预编译客户端](../../README/README_zh_CN.md#关于预编译windows客户端)  
下载时请选择不含客户端的版本，例如`V0.2.7-win64.7z`  
下载后请将其解压到不含中文字符和空格的路径中，同时要确保GUI文件和proxmark3仓库不位于同一文件夹下   
以解压到`./pm3/GUI/`为例，你将会获得如下的目录结构  
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

## 3. 从ProxSpace运行GUI
双击`./runme64.bat`运行ProxSpace环境，此时工作目录位于`./pm3`  
在新弹出的终端中运行`cd GUI`来到`./pm3/GUI/`目录下，然后运行`./V0.2.7-win64/Proxmark3GUI.exe`，此时的GUI将会包含客户端运行所需要的所有环境变量  
***
**请注意**，你可以在你喜欢的工作目录下运行GUI，但请不要在GUI文件所在目录下运行，否则加载客户端时会出错  
以上面的目录结构为例，你可以先运行`cd /pm3`将工作目录设为`/pm3`，然后运行`./V0.2.7-win64/Proxmark3GUI.exe`来打开GUI  
但是你不能先运行`cd /pm3/GUI/V0.2.7-win64`，然后运行`./Proxmark3GUI.exe`，否则之后无法正确加载客户端

## 4. 从GUI连接设备
### 填写客户端路径
以上面的目录结构为例，假设此时的工作目录为`./pm3/GUI`，而客户端路径为`./pm3/proxmark3/client/proxmark3.exe`，则需要在客户端路径里面填写`../proxmark3/client/proxmark3.exe`
### 清空预加载脚本路径
因为GUI是从ProxSpace中启动的，本身已包含客户端所需的环境变量，因此不需要使用任何预加载脚本
### 选择(客户端)配置文件
根据客户端版本的不同，你需要选择对应的配置文件。例如official版本对应`config_official.json`，rrg版本号v4.15864对应`config_rrgv4.15864.json`。如果选项中没有你所使用的客户端版本，可以尝试选择版本号相近的对应配置文件
### 连接设备
在“端口”当中选择需要连接的端口号，单击“连接”即可
