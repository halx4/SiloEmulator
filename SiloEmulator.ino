#include "SiloEmulator.h"
#include "LogicImplementer.h"
#include "InputsHandler.h"
#include "OutputsHandler.h"
#include <SPI.h>


//--------------------------------------
void setup() {
        
        Serial.begin(9600);
        delay(1000);
        //Serial.println("BEGIN");
            
        pinMode(OUT_dataPin, OUTPUT);
        pinMode(OUT_clockPin, OUTPUT);  
        pinMode(OUT_latchPin, OUTPUT);
        pinMode(OUT_buzzerPin, OUTPUT);  

        pinMode(IN_heaterPin,INPUT);
        pinMode(IN_mixerPin,INPUT);
        pinMode(IN_OutValvePin,INPUT);
        pinMode(IN_InValvePin,INPUT);

        digitalWrite(IN_heaterPin,HIGH);
        digitalWrite(IN_mixerPin,HIGH);
        digitalWrite(IN_OutValvePin,HIGH);
        digitalWrite(IN_InValvePin,HIGH);
        
        LogicImplementer core;
        InputsHandler inputs; 
        OutputsHandler outputs;         

         inputs.setObserver(core);

        
        outputs.setSerial2ParallelPins(OUT_dataPin,OUT_clockPin,OUT_latchPin,OUT_buzzerPin);
        outputs.initialize();

        core.setOutputsHandler(outputs);   
        core.setLogicImplementerInstance(core);
        core.initialize();

        
        while(1){

        inputs.check();
        core.check();
        }
}

void loop() {
}
