#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include "Arduino.h"
#include "src/modbus/mbconfig.h"
#include "src/modbus/noos_config.h"
#include "src/iono/Iono.h"
#include "boardTest.h"


#define MCUDRECEIVELENGTH 256    //接收数据的最大长度











void slaveDataInit(void);
extern void modbusSlave_Init(void);
extern void deviceProcessCmd(void);
extern bool modbusSlave_poll(void);
// extern void serialEvent1(void);


extern AnalogParaTypeDef aPara;
extern DigitalParaTypeDef dPara;

#endif  /* _PROTOCOL_H_ */
