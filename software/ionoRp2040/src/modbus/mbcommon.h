/******************************************************************************/
/** 模块名称：Modbus通讯                                                     **/
/** 文件名称：mbcommon.h                                                     **/
/** 版    本：V1.0.0                                                         **/
/** 简    介：用于实现Modbus各种情况下的公用部分                             **/
/**--------------------------------------------------------------------------**/
/** 修改记录：                                                               **/
/**     版本      日期              作者              说明                   **/
/**     V1.0.0  2015-07-18          木南              创建文件               **/
/**                                                                          **/
/******************************************************************************/ 

#ifndef __mbcommon_h
#define __mbcommon_h

#include "stdbool.h"
#include "stdint.h"
#include <Arduino.h>

/*定义更新读取回来的对象值的函数指针类型*/
/*更新读回来的线圈状态*/
typedef void (*UpdateCoilStatusType)(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,bool *stateValue);

/*更新读回来的输入状态值*/
typedef void (*UpdateInputStatusType)(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,bool *stateValue);

/*更新读回来的保持寄存器*/
typedef void (*UpdateHoldingRegisterType)(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*更新读回来的输入寄存器*/
typedef void (*UpdateInputResgisterType)(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,uint16_t *registerValue);

/*将接收到的写单个Coil值转化为布尔量，对应0x05功能码*/
bool CovertSingleCommandCoilToBoolStatus(uint16_t coilValue,bool value);

/*检验所写数据是否符合物理量要求范围并处理(单精度浮点数)*/
float CheckWriteFloatDataIsValid(float value,float range,float zero);
 
 /*检验所写数据是否符合物理量要求范围并处理(双精度浮点数)*/
double CheckWriteDoubleDataIsValid(double value,double range,double zero);

/*检验所写数据是否符合物理量要求范围并处理(16位整数)*/
uint16_t CheckWriteInt16DataIsValid(uint16_t value,uint16_t range,uint16_t zero);
 
 /*检验所写数据是否符合物理量要求范围并处理(32位整数)*/
uint32_t CheckWriteInt32DataIsValid(uint32_t value,uint32_t range,uint32_t zero);

/*获取想要读取的Coil量的值*/
extern void GetCoilStatus(uint16_t startAddress,uint16_t quantity,bool *statusList) __attribute__((weak));

/*获取想要读取的InputStatus量的值*/
extern void GetInputStatus(uint16_t startAddress,uint16_t quantity,bool *statusValue) __attribute__((weak));

/*获取想要读取的保持寄存器的值*/
extern void GetHoldingRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue) __attribute__((weak));

/*获取想要读取的输入寄存器的值*/
extern void GetInputRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue) __attribute__((weak));

/*设置单个线圈的值*/
extern void SetSingleCoil(uint16_t coilAddress,bool coilValue) __attribute__((weak));

/*设置单个寄存器的值*/
extern void SetSingleRegister(uint16_t registerAddress,uint16_t registerValue) __attribute__((weak));

/*设置多个线圈的值*/
extern void SetMultipleCoil(uint16_t startAddress,uint16_t quantity,bool *statusValue) __attribute__((weak));

/*设置多个寄存器的值*/
extern void SetMultipleRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue) __attribute__((weak));

/*更新读回来的线圈状态*/
extern void UpdateCoilStatus(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,bool *stateValue) __attribute__((weak));

/*更新读回来的输入状态值*/
extern void UpdateInputStatus(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,bool *stateValue) __attribute__((weak));

/*更新读回来的保持寄存器*/
extern void UpdateHoldingRegister(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,uint16_t *registerValue) __attribute__((weak));

/*更新读回来的输入寄存器*/
extern void UpdateInputResgister(uint8_t salveAddress,uint16_t startAddress,uint16_t quantity,uint16_t *registerValue) __attribute__((weak));

#endif //__mbcommon_h
/*********** (C) COPYRIGHT 1999-2019 Moonan Technology *********END OF FILE****/