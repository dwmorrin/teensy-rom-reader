#include <Arduino.h>
#include "pins.h"
#include "mmi6306.h"

void read_rom()
{
  for (uint16_t i = 0; i < 512; ++i)
    Serial.println(read(i), HEX);
}

void setup()
{
  pinMode(led_pin, OUTPUT);
  for (uint8_t i = 0; i < 9; ++i)
    pinMode(address_pins[i], OUTPUT);
  for (uint8_t i = 0; i < 4; ++i)
    pinMode(data_pins[i], INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(reset_prog_pin, INPUT);

  digitalWrite(led_pin, HIGH);
  Serial.begin(9600);
  while (!Serial)
    ;
  digitalWrite(led_pin, LOW);
}

void loop()
{
  static unsigned long last_time = 0;
  static uint8_t last_state = LOW;
  uint8_t reset_prog_state = digitalRead(reset_prog_pin);
  if (reset_prog_state != last_state)
  {
    last_time = millis();
  }
  if ((millis() - last_time) > 100)
  {
    if (reset_prog_state == HIGH)
    {
      digitalWrite(led_pin, HIGH);
      read_rom();
      digitalWrite(led_pin, LOW);
      last_time = millis();
    }
  }
  last_state = reset_prog_state;
}