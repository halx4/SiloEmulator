#ifndef SILOSIMULATOR
#define SILOSIMULATOR

        #include <Arduino.h>
        
        //---
         #define TIME_TO_INCREASE_1_DEG_MS 500//ms time to increase or decrease temperature 1 deg celsius 
         #define TIME_TO_INCREASE_LIQUID_LEVEL_MS 800 //time in ms to increase or decrease 1 level of liquid in the tank
         #define BUZZERENABLED  //comment to disable buzzer
        //---
        const byte MAX7219_REG_NOOP        = 0x0;
        // codes 1 to 8 are digit positions 1 to 8
        const byte MAX7219_REG_DECODEMODE  = 0x9;
        const byte MAX7219_REG_INTENSITY   = 0xA;
        const byte MAX7219_REG_SCANLIMIT   = 0xB;
        const byte MAX7219_REG_SHUTDOWN    = 0xC;
        const byte MAX7219_REG_DISPLAYTEST = 0xF;

         
#endif
