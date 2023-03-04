OPENBI_RP2040参数配置到EEPROM

[TOC]



# EEPROM硬件参数

| 参数           | 典型值                  |
| -------------- | ----------------------- |
| 容量           | 16 Kbit (2048 x 8 bits) |
| EEPROM擦写次数 | \> 100000               |
| 数据保存时间   | \> 20 years             |

# 软件配置

## 1.系统配置

系统配置的地址起始位置：0xA

| 参数              | 地址     | 占用字节（1Byte = 8 bits） | R/W  | 说明                                                         |
| ----------------- | -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| hardwareVersion_H | 0xA      | 1                          | R    | 硬件版本，指硬件设计方案的版本                               |
| hardwareVersion_L | 0xB      | 1                          | R    | 硬件版本，某一设计方案中的版本改动                           |
| softwareVersion_H | 0xC      | 1                          | R    | 固件版本，软件功能设计方案的版本                             |
| softwareVersion_L | 0xD      | 1                          | R    | 固件版本，软件功能添加、BUG修复                              |
| initDate[3]       | 0xE—0x10 | 3                          | R    | 最后烧录的一次的日期，从数组的第0个元素开始分别代表：年、月、日 |
| functionCode      | 0x11     | 1                          | R    | 是否有蓝牙功能，震动检测功能，LCD功能和普通功能              |



> ❗**系统配置会在出厂时写入，不允许用户更改。可读。**

### 系统配置结构体

```c
#define BOARD_INFO_ADDRESS  10  //系统配置信息——起始地址
#define BOARD_INFO_LENGTH   8   //系统配置信息——结构体长度

#define FUN_ALL         0
#define FUN_NORMAL      1
#define FUN_BLE_NORMAL  2
#define FUN_AXI_NORMAL  3

//系统配置信息结构体
struct BORAD_INFO
{
    uint8_t hardwareVersion_H;
    uint8_t hardwareVersion_L;
    uint8_t softwareVersion_H;
    uint8_t softwareVersion_L;
    uint8_t initDate[3];
    uint8_t functionCode;

};
```

### 系统配置实例化

```c
BORAD_INFO minfo;//板级信息写入结构体

void boardInit(void)
{
    ……
    
    minfo.hardwareVersion_H = 1;
    minfo.hardwareVersion_L = 0;
    minfo.softwareVersion_H = 1;
    minfo.softwareVersion_L = 0;
    minfo.initDate[0] = 22;
    minfo.initDate[1] = 5;
    minfo.initDate[2] = 22;
    minfo.functionCode = FUN_ALL;
    WriteBoardInfo();
    ……
        
}
```

## 2.软件参数

系统配置的地址起始位置：0x50

软件参数包括：

- Modbus协议用户设定参数：该部分参数由用户设定，并保存。

- 软件运行参数：该部分由开发人员设置，例如发送后延时时间参数。


| 参数                 | 地址 | 占用字节（1Byte = 8 bits） | R/W  |                   说明                   |
| -------------------- | :--: | :------------------------: | :--: | :--------------------------------------: |
| 通讯系统配置时间     | 0x50 |             1              | R/W  |   通讯系统配置时间超时阈值（单位：ms）   |
| 逻辑控制系统配置时间 | 0x51 |             1              | R/W  | 逻辑控制系统配置时间超时阈值（单位：ms） |
| 蓝牙串口波特率       | 0x52 |             1              | R/W  |       蓝牙串口波特率（单位：baud）       |
| RS485串口波特率      | 0x53 |             1              | R/W  |      RS485串口波特率（单位：baud）       |

> ❗**软件参数允许用户读取和修改。上电后读取参数到RAM中，供程序运行使用。**

