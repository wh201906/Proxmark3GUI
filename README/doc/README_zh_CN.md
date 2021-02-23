# Proxmark3GUI
![downloads](https://img.shields.io/github/downloads/wh201906/Proxmark3GUI/total)  

一个自制的[Proxmark3](https://github.com/Proxmark/proxmark3) GUI，可在Windows/Linux系统下运行

[English](../../README.md)

***

## 功能

+ 快速查找可用端口并连接
+ 支持直接输入PM3命令(官方版/冰人版)
+ 有针对于Mifare卡（IC卡）的图形界面
    + 支持不同大小的卡片(MINI, 1K, 2K, 4K)
    + 支持编辑Mifare扇区数据
    + 支持读取全卡/选中扇区，读卡逻辑更加智能
    + 支持写入全卡/选中扇区
    + 可以打开二进制/文本格式的扇区数据文件
    + 分析访问控制位（Access Bits）
    + 支持UID卡操作（UID快速读写，UFUID锁卡）
+ 支持部分低频命令
+ 自定义UI界面，各选项卡可拆分组合
+ ...

***

## 预览图
![preview](../img/preview_zh_CN.png)  

 [更多预览](../doc/previews.md)  

***

 ## 关于冰人版
 [冰人版](https://github.com/RfidResearchGroup/proxmark3)(Iceman/RRG)的客户端和固件更新更为激进，相比官方版具有更多的功能  
 此GUI所有功能均兼容冰人版（在v4.9237上测试通过）  

***

## 关于预编译Windows客户端

一位国外大佬 [Gator96100](https://github.com/Gator96100) 做了个 [ProxSpace](https://github.com/Gator96100/ProxSpace) 以便在Windows平台上编译PM3固件和客户端，他还把自己编译好的客户端放到了[网站](https://www.proxmarkbuilds.org/)上  
release页面中有含客户端的GUI。这个GUI也可以搭配你自己的客户端使用  
(本来打算在CSDN下载里面放几个最新版客户端的，结果不能把下载币改为0)  
感谢大佬  

***

## 在Linux系统下编译

    cd ~
    git clone https://github.com/wh201906/Proxmark3GUI.git
    cd Proxmark3GUI
    mkdir build
    cd build
    qmake ../
    make
    make clean
    cp -r ../lang ./
    ./Proxmark3GUI

***

## 更新日志:

### V0.2
+ 使用浮动窗口，界面配置更加灵活  
+ 支持部分低频命令  
+ 修复原始命令选项卡中的一个Bug  

### V0.1.4
+ 优化性能  
+ 优化用户界面  
+ 自动搜索可用端口  
+ 支持高分屏  
+ 可通过外部脚本配置环境变量  
(在客户端需要配置环境变量时很有用)  
+ 全功能兼容冰人版（在v4.9237上测试通过）  
+ 支持指定客户端工作路径
+ 修复部分bug

### V0.1.3
+ 修复访问控制位解码器
+ 写多个块时显示写入结果

### V0.1.2
+ 优化读卡逻辑
+ UI自定义
+ 自动保存客户端路径
+ 添加访问控制位解码器（也可用于自己构造访问控制位）（有bug，请使用V0.1.3或更高版本）
+ 支持仅读写选中块
+ 支持部分冰人功能
+ 修复部分bug

### V0.1.1
+ 完成整个Mifare模块（支持模拟卡和嗅探功能）

### V0.1
+ 支持处理Mifare卡片及相关数据文件

### V0.0.1
+ 一个带串口选择框的实验版本