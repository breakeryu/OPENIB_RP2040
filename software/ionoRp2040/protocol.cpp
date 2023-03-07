/*
 * @Author: magyu
 * @Date: 2022-05-23 19:30:55
 * @LastEditors: magyu
 * @LastEditTime: 2023-02-17 17:28:52
 * @Description: 请填写简介
 */

#include "protocol.h"


AnalogParaTypeDef aPara;
DigitalParaTypeDef dPara;

uint16_t localStation=1;
uint16_t mcudRxLength=0;
uint8_t mcudRxBuffer[MCUDRECEIVELENGTH];

/**
 * @arg modbus从站初始化
 * @return {void}
 */
void modbusSlave_Init(void){
  slaveDataInit();
}


void deviceProcessCmd(void){
  //user's cmd paras function
  //ParasCmd();
}

/**
 * @arg modbus解析命令函数
 * @return {void}
 */
bool modbusSlave_poll(void){
  bool pollOk = false;
  uint16_t respondLength=0;

  if(mcudRxLength>=8)
  {
    uint8_t respondBytes[MCUDRECEIVELENGTH];
    respondLength=ParsingMasterAccessCommand(mcudRxBuffer,respondBytes,mcudRxLength,localStation);
    if(respondLength!=65535)
    {

        /* USART1数据发送函数 */
        Iono.serialTxEn(true);
        IONO_RS485.write(respondBytes,respondLength);
        Iono.serialTxEn(false);
        mcudRxLength=0;
        pollOk = true;

    }
  }
  return pollOk;
}


/**
 * @arg modbus测试数据初始化函数
 * @return {void}
 */
void slaveDataInit(void){


  dPara.coil[0x10] = 1;
  dPara.coil[1] = 1;
  dPara.coil[3] = 1;
  dPara.coil[4] = 1;

}


/*
串口的接收中断函数
*/
void serialEvent1(void){

    if(mcudRxLength>=MCUDRECEIVELENGTH)
    {
        mcudRxLength=0;
    }

    uint8_t rData = IONO_RS485.read();

    if((0!=mcudRxLength)||(localStation==rData))
    {
        mcudRxBuffer[mcudRxLength++] = rData;
    }


}






/**
 * @arg 获取想要读取的Coil量的值
 * @param {uint16_t} startAddress 地址
 * @param {uint16_t} quantity 数量
 * @param {bool} *statusList  指向的数组
 * @return {void}
 */
void GetCoilStatus(uint16_t startAddress,uint16_t quantity,bool *statusList)
{
  uint16_t start;
  uint16_t count;
  /*先判断地址是否处于合法范围*/
  start=(startAddress>CoilStartAddress)?((startAddress<=CoilEndAddress)?startAddress:CoilEndAddress):CoilStartAddress;
  count=((start+quantity-1)<=CoilEndAddress)?quantity:(CoilEndAddress-start);

  for(int i=0;i<count;i++)
  {
    statusList[i]=dPara.coil[start+i];
  }
}

/*获取想要读取的保持寄存器的值*/
/**
 * @arg:
 * @param {uint16_t} startAddress
 * @param {uint16_t} quantity
 * @param {uint16_t} *registerValue
 * @return {void}
 */
void GetHoldingRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue)
{
  uint16_t start;
  uint16_t count;
  /*先判断地址是否处于合法范围*/
  start=(startAddress>HoldingRegisterStartAddress)?((startAddress<=HoldingRegisterEndAddress)?startAddress:HoldingRegisterEndAddress):HoldingRegisterStartAddress;
  count=((start+quantity-1)<=HoldingRegisterEndAddress)?quantity:(HoldingRegisterEndAddress-start);

  for(int i=0;i<count;i++)
  {
    registerValue[i]=aPara.holdingRegister[start+i];
  }
}

/*设置单个线圈的值*/
void SetSingleCoil(uint16_t coilAddress,bool coilValue)
{
  /*先判断地址是否处于合法范围*/
  bool noError = (coilAddress>=CoilStartAddress)?((coilAddress<=CoilEndAddress)?true:false):false;

  if(noError)
  {
    dPara.coil[coilAddress]=coilValue;
  }
}

/*设置多个线圈的值*/
void SetMultipleCoil(uint16_t startAddress,uint16_t quantity,bool *statusValue)
{
  uint16_t endAddress=startAddress+quantity-1;

  bool noError=((startAddress>=CoilStartAddress)?((startAddress<=CoilEndAddress)?true:false):false)
                &&((endAddress>=CoilStartAddress)?((endAddress<=CoilEndAddress)?true:false):false);

  if(noError)
  {
    for(int i=0;i<quantity;i++)
    {
      dPara.coil[i+startAddress]=statusValue[i];
    }
  }
}

/*设置单个寄存器的值*/
void SetSingleRegister(uint16_t registerAddress,uint16_t registerValue)
{
  bool noError=(registerAddress>=HoldingRegisterStartAddress)?((registerAddress<=HoldingRegisterEndAddress)?true:false):false;

  if(noError)
  {
    aPara.holdingRegister[registerAddress]=registerValue;
  }

}


/*设置多个寄存器的值*/
void SetMultipleRegister(uint16_t startAddress,uint16_t quantity,uint16_t *registerValue)
{
  uint16_t endAddress=startAddress+quantity-1;

  bool noError=((startAddress>=HoldingRegisterStartAddress)?((startAddress<=HoldingRegisterEndAddress)?true:false):false)
                &&((endAddress>=HoldingRegisterStartAddress)?((endAddress<=HoldingRegisterEndAddress)?true:false):false);

  if(noError)
  {
    for(int i=0;i<quantity;i++)
    {
      aPara.holdingRegister[startAddress+i]=registerValue[i];
    }
  }

}


