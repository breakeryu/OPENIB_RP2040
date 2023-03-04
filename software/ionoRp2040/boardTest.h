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
#include "mconfig.h"


#define USERTEST 1  //是否使用测试代码 0-不使用，1-使用






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
bool WriteBoardSoftWareConfig(void);
bool ReadBoardSoftWareConfig(void);
void ParasCmd(void);

extern bool bleMoudleIsUsed;

#endif /* BOARDTEST_H_ */

