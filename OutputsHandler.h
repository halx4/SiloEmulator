#ifndef OUTPUTSHANDLER
#define OUTPUTSHANDLER

#include <Arduino.h>
#include "SiloEmulator.h"
#include <SPI.h>

class OutputsHandler {

public:

        OutputsHandler();
        void setSerial2ParallelPins(int dataPin,int clockPin,int latchPin,int buzzerPin);
        
        void initialize();
        
       void setOutputs(uint16_t _word);
       void setTemperature(int temperature);

private:
        void sendByte (const byte reg, const byte data); 

        int data; 
        int clock;
        int latch;
        int buzzer;
        
        
        //static OutputsHandler* outputsInstance;
        
};

#endif
