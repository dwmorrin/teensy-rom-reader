#include <Arduino.h>
#include "mmi6306.h"
#include "pins.h"

void set_address(uint16_t address)
{
  for (uint8_t i = 0; i < 9; ++i)
    digitalWrite(address_pins[i], address & (1 << i) ? HIGH : LOW);
  delayNanoseconds(address_access_delay_ns);
}

uint8_t read(uint16_t address)
{
  set_address(address);
  uint8_t data = 0;
  for (uint8_t i = 0; i < 4; ++i)
    data |= digitalRead(data_pins[i]) << i;
  return data;
}