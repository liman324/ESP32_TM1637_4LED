#include <ESP32_TM1637_4LED.h>

ESP32_TM1637_4LED::ESP32_TM1637_4LED(uint8_t clk, uint8_t dio){
         CLK = clk;
         DIO = dio;
};

void ESP32_TM1637_4LED::brig(byte br){
     qwer = br + CODE0;
  }

void ESP32_TM1637_4LED::del(){delayMicroseconds(100);}


void ESP32_TM1637_4LED::dec(byte dig){
       for(int i = 0; i < 8; i++) {
         pinMode(CLK,OUTPUT);del();
       if (dig & 0x01)
         pinMode(DIO,INPUT);
       else
         pinMode(DIO,OUTPUT);del();
         pinMode(CLK,INPUT);del();
         dig = dig >> 1;
  }
         pinMode(CLK,OUTPUT);
         pinMode(DIO,INPUT);del();
         pinMode(CLK,INPUT);del();

       
       if (digitalRead(DIO) == 0)
         pinMode(DIO,OUTPUT);del();
         pinMode(CLK,OUTPUT);del();
  }
            
void ESP32_TM1637_4LED::stop(){
         pinMode(DIO,OUTPUT);del();
         pinMode(CLK,INPUT);del();
         pinMode(DIO,INPUT);del();
  }  

void ESP32_TM1637_4LED::start(){
         pinMode(DIO,OUTPUT);del();
  }


void ESP32_TM1637_4LED::print(int t, byte pd_t,   int h0, int h1, int h2, int h3){
        start();dec(qwer);stop();start();
        dec(CODE1);stop();start();
 
        int data0 = t / 1000 % 10;
        int data1 = t / 100 % 10;
        int data2 = t / 10 % 10;
        int data3 = t % 10;
 
      for(byte n = 0; n < 4; n++){
        int data;
      switch(n){
        case 0: data = data0;break;
        case 1: data = data1;break;
        case 2: data = data2;break;
        case 3: data = data3;break;
        }
 
      switch(data){    // XGFEDCBA
        case 0:  data = 0b00111111;break;     // 0
        case 1:  data = 0b00000110;break;     // 1
        case 2:  data = 0b01011011;break;     // 2
        case 3:  data = 0b01001111;break;     // 3
        case 4:  data = 0b01100110;break;     // 4
        case 5:  data = 0b01101101;break;     // 5
        case 6:  data = 0b01111101;break;     // 6
        case 7:  data = 0b00000111;break;     // 7
        case 8:  data = 0b01111111;break;     // 8
        case 9:  data = 0b01101111;break;     // 9
        }
 
        if(n == 0){data0 = data;}
        if(n == 1){data1 = data;}
        if(n == 2){data2 = data;}
        if(n == 3){data3 = data;}
        }
      switch(pd_t){
        case 1 : data2 = data2+0b10000000;break;
        case 2 : data1 = data1+0b10000000;break;
        case 3 : data0 = data0+0b10000000;break;
        }
        if(h0>=0){data0 = h0;}
        if(h1>=0){data1 = h1;}
        if(h2>=0){data2 = h2;}
        if(h3>=0){data3 = h3;}
      dec(0xC0);dec(data0);dec(data1);dec(data2);dec(data3);stop();
}  
