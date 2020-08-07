# Proxmark3GUI
A GUI for [Proxmark3](https://github.com/Proxmark/proxmark3) client

[中文](README/README.zh_CN.md)

***

## Features

+ Easy to find available Serial Port
+ Support raw commands of Proxmark3 client(Official/Iceman)
+ Have a friendly UI to test Mifare cards
    + Support different card size(MINI, 1K, 2K, 4K)
    + Easy to edit Mifare data files
    + Easy to read all blocks with well-designed read logic
    + Support binary(.bin .dump) files and text(.eml) files
    + Analyze Access Bits
    + Support Chinese Magic Card
+ Customize UI
+ ...

***

## Previews
![nested_attack](README/mf_nested_attack.gif)  

![mf_load_file](README/mf_load_file.gif)  

![mf_edit_file](README/mf_edit_file.gif)  

![raw_command](README/raw_command.gif)  

***

## Update Log:

### V0.1.1
+ Complete Mifare module(support simulate and sniff)

### V0.1
+ Able to deal with Mifare card and related files

### V0.0.1
+ a dumb version with a useless GUI and a serial choose box.