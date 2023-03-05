#ifndef _MCONFIG_H_
#define _MCONFIG_H_


#include "Arduino.h"

/*

Part1. Definition of EEPROM Cofiguration

*/

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



/*

Part2. Definition of RS485 Communication Protocol Cofiguration

*/

/* 线圈指令对应地址 */

#define Device_Stop_State           0x10
#define Device_Operating_State      0x11
#define Bluetooth_Open              0x12
//#define Reverse                     0x13
#define Relay1_Open                 0x14
#define Relay2_Open                 0x15
#define Relay3_Open                 0x16
#define Relay4_Open                 0x17
#define Input_Channel1_Open         0x18
#define Input_Channel2_Open         0x19
#define Input_Channel3_Open         0x1A
#define Input_Channel4_Open         0x1B
#define EEPROM_Error                0x1C
#define AxiModule_Error             0x1D


#define Sys_Reset_State             0x100
#define Relay1_Get_Next_State       0x101
#define Relay2_Get_Next_State       0x102
#define Relay3_Get_Next_State       0x103
#define Relay4_Get_Next_State       0x104
#define Led_Get_Next_State          0x105




/* 寄存器指令对应地址 */


#define InputChannel1_Analog_Value      0x00
#define InputChannel2_Analog_Value      0x01
#define InputChannel3_Analog_Value      0x02
#define InputChannel4_Analog_Value      0x03
#define AxiModule_Ax_Value              0x04
#define AxiModule_Ay_Value              0x05
#define AxiModule_Az_Value              0x06
#define AxiModule_Wx_Value              0x07
#define AxiModule_Wy_Value              0x08
#define AxiModule_Wz_Value              0x09
#define AxiModule_Anglex_Value          0x0A
#define AxiModule_Angley_Value          0x0B
#define AxiModule_Anglez_Value          0x0C
#define AxiModlue_AirPressure_Value     0x0D
#define AxiModlue_Altitude_Value        0x0E
#define AxiModlue_Temperature_Value     0x0F


#define Commnication_Config_Time_Limite 0x50
#define LogicControl_Config_Time_Limite 0x51
#define Baudrate_Of_BluetoothPort       0x52
#define Baudrate_Of_Rs485Port           0x53
#define Hardware_Version_H              0x54
#define Hardware_Version_L              0x55
#define Software_Version_H              0x56
#define Software_Version_L              0x57


#define Analog_Voltage_Ouput            0x100
//#define Reverse                     0x101
//#define Reverse                     0x102
#define Input_Channel1_Enable           0x103
#define Input_Channel2_Enable           0x104
#define Input_Channel3_Enable           0x105
#define Input_Channel4_Enable           0x106
#define Input_Channel1_Config           0x107
#define Input_Channel2_Config           0x108
#define Input_Channel3_Config           0x109
#define Input_Channel4_Config           0x10A
#define Relay_Channels_Config           0x10B


#define Year_Of_Operating_Time          0x180
#define Month_Of_Operating_Time         0x181
#define Day_Of_Operating_Time           0x182
#define Hour_Of_Operating_Time          0x183
#define Minute_Of_Operating_Time        0x184
#define Second_Of_Operating_Time        0x185







#endif



