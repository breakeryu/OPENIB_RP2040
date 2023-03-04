#ifndef _MCONFIG_H_
#define _MCONFIG_H_


#include "Arduino.h"



#define BOARD_INFO_ADDRESS  0xA     //系统配置信息——起始地址
#define BOARD_INFO_LENGTH   8       //系统配置信息——结构体长度

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


#define BOARD_SOFTWARE_CONFIG_ADDRESS   0x50    //软件配置——起始地址
#define BOARD_SOFTWARE_CONFIG_LENGTH    4       //软件配置——结构体长度

//软件参数地址偏移量
#define comPortConfigTimeThresholdOffset            0
#define LogicControlConfigTImeThresholdOffset       1
#define BlueToothBaudRateOffset                     2
#define Rs485BaudRateOffset                         3


//软件配置结构体
struct BOARD_SOFTWARE_CONFIG
{
    uint8_t ComPortConfigTimeThreshold;
    uint8_t LogicControlConfigTImeThreshold;
    uint8_t BlueToothBaudRate;
    uint8_t Rs485BaudRate;
};







#endif



