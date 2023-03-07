/*
 * @Author: magyu
 * @Date: 2022-04-30 22:25:26
 * @LastEditors: magyu
 * @LastEditTime: 2023-02-17 17:30:46
 * @Description: 请填写简介
 */

#include "boardTest.h"

bool bleMoudleIsUsed = false;//标志是否使用蓝牙模块，默认false-不使用
bool axiMoudleIsUsed = false;//标志是否使用震动传感器模块，默认false-不使用
MC_BOARD_INFO_t minfo;//板级信息写入结构体
MC_BOARD_INFO_t rinfo;//板级信息读取结构体

MC_BOARD_SOFTWARE_CONFIG_t msoftConfigStruct;
MC_BOARD_SOFTWARE_CONFIG_t rsoftConfigStruct;



/**
 * @arg 板级初始化函数。
 * 该函数的功能是进行：1.EEPROM初始化，读取相关参数。2.选择性初始化蓝牙模块、震动传感器模块。3.初始化板级IO和485功能.
 * @return {void}
 */
void boardInit(void)
{

    Wire2Init();
    ReadBoardInfo();

    if(rinfo.functionCode == FUN_ALL){  //全模式
        bleMoudleIsUsed = true;
        axiMoudleIsUsed = true;
        BleUartInit();
        JY901.StartIIC();
    }else if (rinfo.functionCode == FUN_BLE_NORMAL) //仅蓝牙模式
    {
        bleMoudleIsUsed = true;
        BleUartInit();
    }else if (rinfo.functionCode == FUN_AXI_NORMAL) //仅震动传感器模式
    {
        axiMoudleIsUsed = true;
        JY901.StartIIC();
    }

    if(ScanWireDevices() == false){
        if(bleMoudleIsUsed == true){
            IONO_BLE.println("Scan Process error, software is Stop! Please Check this Divice Problem!");
        }
        //todo 添加错误代码
    }else
    {
        if(bleMoudleIsUsed == true){
            IONO_BLE.println("Scan Process is Done! All Device are ok!");
        }
        //todo 添加错误代码
    }

    //用于测试,代码确定后，参数一般只需要写入一次。
#if USERTEST
    DO_testFlip();
    minfo.hardwareVersion_H = 0;
    minfo.hardwareVersion_L = 2;
    minfo.softwareVersion_H = 0;
    minfo.softwareVersion_L = 2;
    minfo.initDate[0] = 23;
    minfo.initDate[1] = 3;
    minfo.initDate[2] = 4;
    minfo.functionCode = FUN_ALL;
    WriteBoardInfo();
    ReadBoardInfo();
    msoftConfigStruct.ComPortConfigTimeThreshold = 100;
    msoftConfigStruct.LogicControlConfigTImeThreshold = 300;
    msoftConfigStruct.BlueToothBaudRate = 9600;
    msoftConfigStruct.Rs485BaudRate = 115200;
    WriteBoardSoftWareConfig();
    ReadBoardSoftWareConfig();
#endif

}


/**
 * @arg: 蓝牙模块初始化，波特率9600
 * @return {void}
 */
void BleUartInit(void)
{
    IONO_BLE.setRX(5);
    IONO_BLE.setTX(4);
    IONO_BLE.begin(9600);
}

/**
 * @arg IIC初始化
 * @return {void}
 */
void Wire2Init(void)
{
    Wire.setSCL(1);
    Wire.setSDA(0);
    Wire.begin();
}


/**
 * @arg 查找IIC设备
 * @return {bool}，没有查找到设备则出错，
 */
bool ScanWireDevices(void)
{
    // Scan_AllDevice();

    if (Scan_AH24C16() == false){
        if(bleMoudleIsUsed == true){
            IONO_BLE.println("EEPROM ERROR!!!");
        }
        //todo 添加错误代码
        return false;
    }

    if (axiMoudleIsUsed == true)
    {
        if(Scan_JY601() == false){
            if(bleMoudleIsUsed == true){
                IONO_BLE.println("JY601 ERROR!!!");
            }
            //todo 添加错误代码
            return false;
        }
    }


    return true;
}

/**
 * @arg IIC搜索所有设备，仅用于测试。
 * @return {void}
 */
void Scan_AllDevice(void)
{
    byte error, address;
    int nDevices;
    IONO_BLE.println("Scanning...");
    nDevices = 0;
    for (address = 1; address < 127; address++ ) {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
        IONO_BLE.print("I2C device found at address 0x");
        if (address < 16)
            IONO_BLE.print("0");
        IONO_BLE.print(address, HEX);
        IONO_BLE.println(" !");
        nDevices++;
        } else if (error == 4) {
        IONO_BLE.print("Unknow error at address 0x");
        if (address < 16)
            IONO_BLE.print("0");
        IONO_BLE.println(address, HEX);
        }
    }
    if (nDevices == 0)
        IONO_BLE.println("No I2C devices found\n");
    else
        IONO_BLE.println("done\n");
}

bool Scan_AH24C16(void)
{
    return at24cxx_checkConnection();
}

/**
 * @arg 查找震动传感器模块
 * @return {void}
 */
bool Scan_JY601(void)
{
    //TODO  通过加速度可以看出来安装面
    JY901.GetAcc();
    IONO_BLE.print("Acc:");IONO_BLE.print((float)JY901.stcAcc.a[0]/32768*16);IONO_BLE.print(" ");IONO_BLE.print((float)JY901.stcAcc.a[1]/32768*16);IONO_BLE.print(" ");IONO_BLE.println((float)JY901.stcAcc.a[2]/32768*16);

    // JY901.GetGyro();
    // IONO_BLE.print("Gyro:");IONO_BLE.print((float)JY901.stcGyro.w[0]/32768*2000);IONO_BLE.print(" ");IONO_BLE.print((float)JY901.stcGyro.w[1]/32768*2000);IONO_BLE.print(" ");IONO_BLE.println((float)JY901.stcGyro.w[2]/32768*2000);

    // JY901.GetAngle();
    // IONO_BLE.print("Angle:");IONO_BLE.print((float)JY901.stcAngle.Angle[0]/32768*180);IONO_BLE.print(" ");IONO_BLE.print((float)JY901.stcAngle.Angle[1]/32768*180);IONO_BLE.print(" ");IONO_BLE.println((float)JY901.stcAngle.Angle[2]/32768*180);

    // IONO_BLE.println("");

    return JY901.testConnection();
}

/**
 * @arg 继电器测试程序。
 * 程序现象：四个继电器分别开-关。
 * @return {void}
 */
void DO_testFlip(void)
{
    Iono.write(DO1,HIGH);
    delay(1000);
    Iono.write(DO1,LOW);
    Iono.write(DO2,HIGH);
    delay(1000);
    Iono.write(DO2,LOW);
    Iono.write(DO3,HIGH);
    delay(1000);
    Iono.write(DO3,LOW);
    Iono.write(DO4,HIGH);
    delay(1000);
    Iono.write(DO4,LOW);
    delay(1000);
}


//Users other than administrators are prohibited from using this function!
bool WriteBoardInfo(void)
{
    at24cxx_write(EEPROM_ADRESS, BOARD_INFO_ADDRESS, (uint8_t *)&minfo, BOARD_INFO_LENGTH);
    return true;
}


/**
 * @arg EEPROM读取板级参数
 * @return {bool}
 */
bool ReadBoardInfo(void)
{
    at24cxx_read(EEPROM_ADRESS, BOARD_INFO_ADDRESS, (uint8_t *)&rinfo, BOARD_INFO_LENGTH);

#if USERTEST
    IONO_BLE.print("hardwareVersion = ");IONO_BLE.print(rinfo.hardwareVersion_H);IONO_BLE.print(".");IONO_BLE.println(rinfo.hardwareVersion_L);
    IONO_BLE.print("softwareVersion = ");IONO_BLE.print(rinfo.softwareVersion_H);IONO_BLE.print(".");IONO_BLE.println(rinfo.softwareVersion_L);
    IONO_BLE.print("init date = ");IONO_BLE.print(2000+rinfo.initDate[0]);IONO_BLE.print(".");IONO_BLE.print(rinfo.initDate[1]);IONO_BLE.print(".");IONO_BLE.println(rinfo.initDate[2]);
    IONO_BLE.print("fun code = ");IONO_BLE.println(rinfo.functionCode);
#endif

    return true;

}

//Users other than administrators are prohibited from using this function!
bool WriteBoardSoftWareConfig(void)
{
    at24cxx_write(EEPROM_ADRESS, BOARD_SOFTWARE_CONFIG_ADDRESS, (uint8_t *)&msoftConfigStruct, BOARD_SOFTWARE_CONFIG_LENGTH);
    return true;
}


/**
 * @arg EEPROM读取软件参数
 * @return {bool}
 */
bool ReadBoardSoftWareConfig(void)
{
    at24cxx_read(EEPROM_ADRESS, BOARD_SOFTWARE_CONFIG_ADDRESS, (uint8_t *)&rsoftConfigStruct, BOARD_SOFTWARE_CONFIG_LENGTH);

#if USERTEST
    IONO_BLE.print("hardwareVersion = ");IONO_BLE.print(rinfo.hardwareVersion_H);IONO_BLE.print(".");IONO_BLE.println(rinfo.hardwareVersion_L);
    IONO_BLE.print("softwareVersion = ");IONO_BLE.print(rinfo.softwareVersion_H);IONO_BLE.print(".");IONO_BLE.println(rinfo.softwareVersion_L);
    IONO_BLE.print("init date = ");IONO_BLE.print(2000+rinfo.initDate[0]);IONO_BLE.print(".");IONO_BLE.print(rinfo.initDate[1]);IONO_BLE.print(".");IONO_BLE.println(rinfo.initDate[2]);
    IONO_BLE.print("fun code = ");IONO_BLE.println(rinfo.functionCode);
#endif

    return true;
}




void ParasCmd(void)
{


}

