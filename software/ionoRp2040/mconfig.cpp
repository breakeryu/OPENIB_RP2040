
#include "mconfig.h"



uint8_t _mconfigComPortConfigTimeThreshold = 100;
uint8_t _mconfigLogicControlConfigTImeThreshold = 300;
uint8_t _mconfigBlueToothBaudRate = 9600;
uint8_t _mconfigRs485BaudRate = 115200;
MC_BOARD_INFO_t _mconfig_BOARD_INFO;
MC_BOARD_SOFTWARE_CONFIG_t _mconfig_BOARD_SOFTWARE_CONFIG;


/*****************************************************************************************/
void MC_board_Info_First_Init(void)
{

    MC_BOARD_INFO_t _read_BOARD_INFO;

    _mconfig_BOARD_INFO.hardwareVersion_H = 1;
    _mconfig_BOARD_INFO.hardwareVersion_L = 0;
    _mconfig_BOARD_INFO.softwareVersion_H = 1;
    _mconfig_BOARD_INFO.softwareVersion_L = 0;
    _mconfig_BOARD_INFO.initDate[0] = 2023;
    _mconfig_BOARD_INFO.initDate[1] = 3;
    _mconfig_BOARD_INFO.initDate[2] = 7;
    _mconfig_BOARD_INFO.functionCode = FUN_ALL;

    at24cxx_write(EEPROM_ADRESS, BOARD_INFO_ADDRESS, (uint8_t *)&_mconfig_BOARD_INFO, BOARD_INFO_LENGTH);

    at24cxx_read(EEPROM_ADRESS, BOARD_INFO_ADDRESS, (uint8_t *)&_read_BOARD_INFO, BOARD_INFO_LENGTH);

    if( _read_BOARD_INFO.hardwareVersion_H != _mconfig_BOARD_INFO.hardwareVersion_H ||
        _read_BOARD_INFO.hardwareVersion_L != _mconfig_BOARD_INFO.hardwareVersion_L ||
        _read_BOARD_INFO.softwareVersion_H != _mconfig_BOARD_INFO.softwareVersion_H ||
        _read_BOARD_INFO.softwareVersion_L != _mconfig_BOARD_INFO.softwareVersion_L ||
        _read_BOARD_INFO.initDate[0] != _mconfig_BOARD_INFO.initDate[0] ||
        _read_BOARD_INFO.initDate[1] != _mconfig_BOARD_INFO.initDate[1] ||
        _read_BOARD_INFO.initDate[2] != _mconfig_BOARD_INFO.initDate[2] ||
        _read_BOARD_INFO.functionCode != _mconfig_BOARD_INFO.functionCode   )
    {
        dPara.coil[EEPROM_Error] =  1;  //  eeprom error
    }


}


/*****************************************************************************************/
void MC_board_Software_Config_First_Or_Re_Init(void)
{

    MC_BOARD_SOFTWARE_CONFIG_t _read_BOARD_SOFTWARE_CONFIG;

    _mconfig_BOARD_SOFTWARE_CONFIG.ComPortConfigTimeThreshold = _mconfigComPortConfigTimeThreshold;
    _mconfig_BOARD_SOFTWARE_CONFIG.LogicControlConfigTImeThreshold = _mconfigLogicControlConfigTImeThreshold;
    _mconfig_BOARD_SOFTWARE_CONFIG.BlueToothBaudRate = _mconfigBlueToothBaudRate;
    _mconfig_BOARD_SOFTWARE_CONFIG.Rs485BaudRate = _mconfigRs485BaudRate;

    at24cxx_write(EEPROM_ADRESS, BOARD_SOFTWARE_CONFIG_ADDRESS, (uint8_t *)&_mconfig_BOARD_SOFTWARE_CONFIG, BOARD_SOFTWARE_CONFIG_LENGTH);

    at24cxx_read(EEPROM_ADRESS, BOARD_SOFTWARE_CONFIG_ADDRESS, (uint8_t *)&_read_BOARD_SOFTWARE_CONFIG, BOARD_SOFTWARE_CONFIG_LENGTH);

    if( _read_BOARD_SOFTWARE_CONFIG.ComPortConfigTimeThreshold != _mconfig_BOARD_SOFTWARE_CONFIG.ComPortConfigTimeThreshold ||
        _read_BOARD_SOFTWARE_CONFIG.LogicControlConfigTImeThreshold != _mconfig_BOARD_SOFTWARE_CONFIG.LogicControlConfigTImeThreshold ||
        _read_BOARD_SOFTWARE_CONFIG.BlueToothBaudRate != _mconfig_BOARD_SOFTWARE_CONFIG.BlueToothBaudRate ||
        _read_BOARD_SOFTWARE_CONFIG.Rs485BaudRate != _mconfig_BOARD_SOFTWARE_CONFIG.Rs485BaudRate  )
    {
        dPara.coil[EEPROM_Error] =  1;  //  eeprom error
    }

}







