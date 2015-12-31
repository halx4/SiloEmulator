#ifndef SILOSIMULATOR
#define SILOSIMULATOR

        #include <Arduino.h>
        
        //---
         const int TIME_TO_INCREASE_1_DEG_MS = 500; //ms time to increase or decrease temperature 1 deg celsius 
         const int TIME_TO_INCREASE_LIQUID_LEVEL_MS = 800; //time in ms to increase or decrease 1 level of liquid in the tank

        const byte FULL_SENSOR_POSITION = 1;            // ( 0-10 )
        const byte EMPTY_SENSOR_POSITION = 9;
         
         #define BUZZERENABLED  //comment to disable buzzer
        
        //---
        const byte MAX7219_REG_NOOP        = 0x0;
        // codes 1 to 8 are digit positions 1 to 8
        const byte MAX7219_REG_DECODEMODE  = 0x9;
        const byte MAX7219_REG_INTENSITY   = 0xA;
        const byte MAX7219_REG_SCANLIMIT   = 0xB;
        const byte MAX7219_REG_SHUTDOWN    = 0xC;
        const byte MAX7219_REG_DISPLAYTEST = 0xF;

        const byte OUT_dataPin = 7; 
        const byte OUT_clockPin = 8;
        const byte OUT_latchPin = 9;
        const byte OUT_buzzerPin=6;
        const byte ONE_WIRE_BUS=2;

         
#endif
