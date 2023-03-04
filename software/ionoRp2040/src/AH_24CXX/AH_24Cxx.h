
#ifndef AH_24Cxx_h
#define AH_24Cxx_h

#include <Arduino.h>   //Arduino IDE >= V1.0
#include <Wire.h>

#define AT24C16

#ifdef AT24C02
#define PAGE_SIZE   (8)
#endif
#if defined (AT24C04) || defined (AT24C08) || defined (AT24C16)
#define PAGE_SIZE   (16)
#endif
#if defined(AT24C32) || defined(AT24C64)
#define PAGE_SIZE   (32)
#endif

#define EEPROM_ADRESS   0x56        //device address
#define EEPROM_SIZE     2048        //AT24C16 2048byte
#define EEPROM_CHECK_ADRESS     2
#define EEPROM_CHECK_KEY        0x56


void at24cxx_init(void);
int at24cxx_read_byte(int slave, int addr);
void at24cxx_write_byte(int slave, int addr, int data);
int at24cxx_write(int slave, int addr, const uint8_t *buf, int buflen);
int at24cxx_read(int slave, int addr, uint8_t *buf, int buflen);
bool at24cxx_checkConnection(void);


#endif
