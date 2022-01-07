#include <ESP32_TM1637_4LED.h>
  ESP32_TM1637_4LED  tm(12,13);// CLK, DIO

void setup() {
  delay(100);
  tm.brig(7); // яркость 0...7
  
}

void loop() {
  tm.print(100,0,  0b01111000,-1,-1,-1);
  delay(100);

}
