# 更新日志

[English](../../CHANGELOG.md)  

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