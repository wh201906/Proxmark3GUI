# 更新日志

[English](../../CHANGELOG.md)  

### V0.2.8
+ 支持冰人版客户端 v4.16717  
+ 修复若干Bug  
+ 便于在不同版本客户端之间切换  
+ 支持蓝牙及TCP连接  

### V0.2.7
+ 修复使用冰人版v4.15864时无法写入块0的问题  
+ 默认关闭Linux/macOS系统下对PM3硬件断连的检测  
+ 修复配置文件中的小Bug  
+ 修复访问控制位解码器  
+ 在访问控制位解码器中显示更多细节  
+ 添加暗黑主题(源于https://github.com/ColinDuquesnoy/QDarkStyleSheet)  
+ 支持自定义主题，透明度，字体  
+ 修复若干翻译问题  

### V0.2.6
+ 支持冰人版客户端 v4.15864 [#37](https://github.com/wh201906/Proxmark3GUI/issues/37)  
+ 优化Mifare Classic卡写卡逻辑  
+ 修复lf config默认配置  
+ 添加客户端无法启动的提示  
+ 添加PM3硬件连接失败的提示  
+ 为PM3对应串口添加提示，并自动选中  
+ 修复原始指令框中有多余空行的问题  
+ 内嵌不同客户端的配置文件  
+ 去除从nested attack切换到staticnested attack的等待时间  

### V0.2.5
+ 修复 [#28](https://github.com/wh201906/Proxmark3GUI/issues/28)

### V0.2.4
+ 复制EM410x卡（一种常见的低频ID卡）  

### V0.2.3
+ 修复 [#27](https://github.com/wh201906/Proxmark3GUI/issues/27)
+ 尝试支持中文启动路径

### V0.2.2
+ 从外部文件加载客户端命令格式  
+ 修复 [#20](https://github.com/wh201906/Proxmark3GUI/issues/20), [#21](https://github.com/wh201906/Proxmark3GUI/issues/21), [#22](https://github.com/wh201906/Proxmark3GUI/issues/22)  
+ 兼容冰人版客户端 v4.13441

### V0.2.1
+ 优化MIFARE Classic读卡逻辑
+ 修复 [#16](https://github.com/wh201906/Proxmark3GUI/issues/16) （配合新版RRG固件时无法读取扇区数据）
+ 修复 [#15](https://github.com/wh201906/Proxmark3GUI/issues/15) （路径中支持空格）

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