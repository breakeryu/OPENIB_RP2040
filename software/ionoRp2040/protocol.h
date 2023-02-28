#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include "Arduino.h"
#include "src/modbus/mbconfig.h"
#include "src/modbus/noos_config.h"
#include "src/iono/Iono.h"
#include "boardTest.h"


#define MCUDRECEIVELENGTH 256    //接收数据的最大长度

/* 线圈指令对应地址 */

#define LED_STRIP_READ_SYS_STATUS               0x10
#define LED_STRIP_READ_THEATER_MODE_STATUS      0x11
#define LED_STRIP_READ_RAINBOW_MODE_STATUS      0x12
#define LED_STRIP_READ_TEST_MODE_STATUS         0x13

#define LED_STRIP_SET_SYS_OPEN                  0x100
#define LED_STRIP_SET_THEATER_MODE_OPEN         0x101
#define LED_STRIP_SET_RAINBOW_MODE_OPEN         0x102
#define LED_STRIP_SET_TEST_MODE_OPEN            0x103
#define VL_READ_RW_ENABLE                       0x104
#define VL_WRITE_RW_ENABLE                      0x105
#define VL_READ_RESULT_ENABLE                   0x106




/* 寄存器指令对应地址 */

#define SENSOR_READ_SYS_VOLTAGE                 0x0A
#define SENSOR_READ_GAS_DENSITY                 0x0B
#define SENSOR_READ_LIGHT_INTENSITY             0x0C
#define SENSOR_READ_TEMPERTURE                  0x0D
#define SENSOR_READ_HUMIDITY                    0x0E
#define SENSOR_READ_DISTANCE                    0x0F



   



void slaveDataInit(void);
extern void modbusSlave_Init(void);
extern void deviceProcessCmd(void);
extern bool modbusSlave_poll(void);
// extern void serialEvent1(void);


extern AnalogParaTypeDef aPara;
extern DigitalParaTypeDef dPara;

#endif  /* _PROTOCOL_H_ */
