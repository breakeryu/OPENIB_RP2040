#include "VsAction.h"



uint16_t _mconfigBleBandrate;   //读取配置——蓝牙串口波特率
uint16_t _mconfigRs485Bandrate; //读取配置——485串口波特率

/*
 * ComPortSystem Action Function Prototypes.
 */
void aGetComConfig (void)
{
    _mconfigBleBandrate = 9600;
    _mconfigRs485Bandrate = 9600;
}

void aSendErrorCode (void)
{

}

void aSystemReset (void)
{

}


//开启蓝牙串口
void aBleBeginCommunication (void)
{
    IONO_BLE.begin(_mconfigBleBandrate);
}


//关闭蓝牙串口
void aBleColseComPort (void)
{
    IONO_BLE.end();
}


//蓝牙通讯数据处理
void aBleDateProcessing (void)
{

}



//打开485通信串口
void aBeginCommunication (void)
{
    IONO_RS485.begin(_mconfigRs485Bandrate);
}


//485通信数据处理
void aDateProcessing (void)
{

}


//关闭485通信串口
void aRs485ColseComPort (void)
{
    IONO_RS485.end();
}



/*
 * LogicControlSystem Action Function Prototypes.
 */
void aGetLogicConfig (void)
{


}

void aInputTransmitterDateUpdate (void)
{


}

void aRelayStateUpdate (void)
{

}



