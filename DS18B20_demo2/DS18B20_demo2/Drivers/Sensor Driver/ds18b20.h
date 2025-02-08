/*
 * ds18b20.h
 * *  hardware configuration   REQUIRE :
 *  PULL UP resıstor between vcc and DQ line
 *  OPEN darin port on microcontroller
 *
 *  One wire Bus System:
 *  DS18B20 only use as a slave device
 *
 *  3 topics important to start the system.
 *  1- hardware configuration
 *  2- transaction sequence
 *  3- 1 - wire signaling ( signal type and timing)
 *
 *  2-Transaction sequence:
 *
 *  Step one - Reset and Presence signal  (Initialization)
 *  Step two - ROM command
 *  Step there - DS18B20 funtion command
 *
 *  Note: It is very important to follow this sequence every time the
DS18B20 is accessed, as the DS18B20 will not respond
if any steps in the sequence are missing or out of order.
 *
 *
 *
 *
 *  Initialization :
 *  All transactions on the 1-Wire bus begin with an initialization
sequence. The initialization sequence consists of a
reset pulse transmitted by the bus master followed by
presence pulse(s) transmitted by the slave(s). The presence
pulse lets the bus master know that slave devices
(such as the DS18B20) are on the bus and are ready
to operate.
 *
 *
 *
 *
 *  ROM CODES:
 *
 *  After the bus master has detected a presence pulse, it
can issue a ROM command. These commands operate
on the unique 64-bit ROM codes of each slave device
and allow the master to single out a specific device if
many are present on the 1-Wire bus. These commands
also allow the master to determine how many and what
types of devices are present on the bus or if any device
has experienced an alarm condition. There are five ROM
commands, and each command is 8 bits long. The master
device must issue an appropriate ROM command before
issuing a DS18B20 function command.
 *
 *
 *
 * Function Commands:
 *
 * After the bus master has used a ROM command to
address the DS18B20 with which it wishes to communicate,
the master can issue one of the DS18B20 function
commands. These commands allow the master to write
to and read from the DS18B20’s scratchpad memory,
initiate temperature conversions and determine the power
supply mode.
 *  Created on: Jan 13, 2025
 *      Author: kinan
 */

#ifndef SENSOR_DRIVER_DS18B20_H_
#define SENSOR_DRIVER_DS18B20_H_

#include "stm32f0xx_hal.h"

#define skip_rom_command 0xCC
#define convert_temprature_value 0x44
#define read_skratch_pad 0xBE


// uint8_t DS18B20_Init(void);
 uint8_t DS18B20_ReadBit(void);
 uint8_t DS18B20_ReadByte(void);
 void DS18B20_WriteByte(uint8_t);
void DS18B20_SampleTemp(void);
float DS18B20_ReadTemp(void);
//void uart_initt(uint32_t baud);

#endif /* SENSOR_DRIVER_DS18B20_H_ */
