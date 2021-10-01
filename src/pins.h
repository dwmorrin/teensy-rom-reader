#ifndef ROM_READER_PINS
#define ROM_READER_PINS
#include <stdint.h>

// index = Ai on ROM
const uint8_t address_pins[] = {
    8, 7, 6, 9, 10, 11, 12, 13, 14};

// instruction position: LSB = O4, ..., MSB = O1
// index: LSB = 0, ..., MSB = 3
const uint8_t data_pins[] = {
    18, 17, 16, 15};

enum
{
  led_pin = 4,
  reset_prog_pin = 5
};
#endif