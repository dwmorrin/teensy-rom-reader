#ifndef ROM_READ_6306
#define ROM_READ_6306
#include <stdint.h>

/**
 * MMI 6306 PROM
 * 2 k bits (not bytes)
 * 9 address pins, 4 output pins = 512 addresses, 4 bits in each address
 * 512 x 4 bits = 2048 bits = 256 8-bit bytes
 *       ___ ___
 *   A6 |1  U 16| Vcc
 *   A5 |       | A7
 *   A4 |       | A8
 *   A3 |       | P/!E1
 *   A0 |       | O1
 *   A1 |       | O2
 *   A2 |       | O3
 *  GND |7     8| O4
 *       ------- 
 * 
 * Vcc = 5V +/- 0.5V
 * Logical "1" voltage: >2V (will work with 3.3V mC)
 * tAA (ns) Address access time max: 60 ns
 */

const unsigned int address_access_delay_ns = 60;

void set_address(uint16_t address);
uint8_t read(uint16_t address);
#endif