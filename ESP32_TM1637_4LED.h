//  ESP32_TM1637_4LED
//  Alexander Liman
//  liman324@yandex.ru
//  rcl-radio.ru

#ifndef  ESP32_TM1637_4LED_H
#define  ESP32_TM1637_4LED_H

#include <Arduino.h>

#define CODE0    0b10001000
#define CODE1    0x40
#define ADDR0    0xC0

class  ESP32_TM1637_4LED
  {
    public:

  ESP32_TM1637_4LED(uint8_t, uint8_t);
  void print(int t, byte pd_t,   int h0, int h1, int h2, int h3);
  void brig(byte br);
  
    private:
  
  void dec(byte dig);
  void stop();
  void start();
  void del();
  byte qwer;
  uint8_t DIO;
  uint8_t CLK;
  };
#endif
