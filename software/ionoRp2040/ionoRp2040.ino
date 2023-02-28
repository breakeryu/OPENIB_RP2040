/*
 * @Author: magyu
 * @Date: 2022-04-28 20:46:37
 * @LastEditors: magyu
 * @LastEditTime: 2023-02-17 17:34:15
 * @Description: iono的主函数
 */
#include "src/iono/Iono.h"
#include "boardTest.h"
#include "Arduino.h"
#include "protocol.h"
#include "VsAction.h"


SEM_EVENT_TYPE ComPortSystemEventNo = SE_RESET;

SEM_EVENT_TYPE LogicControlSystemEventNo = SE_RESET;




//core1 is used to be modbus rtu, only as communication unit
void setup() {

  Iono.setup();
  boardInit();
  modbusSlave_Init();

}

void loop() {


  if(modbusSlave_poll()){
    deviceProcessCmd();
  }
  //Scan_JY601();
  delay(10);
}




//core2 is used to be normal mcu
void setup1() {


}



void loop1() {


}




