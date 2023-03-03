/*
 * @Author: magyu
 * @Date: 2022-04-30 22:25:36
 * @LastEditors: magyu
 * @LastEditTime: 2023-02-17 17:31:28
 * @Description: 请填写简介
 */
#ifndef BOARDTEST_H_
#define BOARDTEST_H_

#include "Arduino.h"
#include "src/iono/Iono.h"
#include "src/AH_24CXX/AH_24Cxx.h"
#include "src/JY601P/JY901.h"
#include "Wire.h"


#define USERTEST 0  //是否使用测试代码 0-不使用，1-使用

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




void boardInit(void);
void Wire2Init(void);
bool ScanWireDevices(void);
void BleUartInit(void);
bool Scan_AH24C16(void);
void DO_testFlip(void);
void Scan_AllDevice(void);
bool Scan_JY601(void);
bool WriteBoardInfo(void);
bool ReadBoardInfo(void);
void ParasCmd(void);

extern bool bleMoudleIsUsed;

#endif /* BOARDTEST_H_ */

