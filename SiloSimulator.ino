#include "SiloSimulator.h"
#include "LogicImplementer.h"
#include "InputsHandler.h"
#include "OutputsHandler.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SPI.h>




OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
//--------------------------------------
void setup() {
        
        Serial.begin(9600);
        delay(1000);
        Serial.println("BEGIN");
            
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
        
        // SPI.begin ();
        sensors.begin();
        sensors.setResolution(9);   //DS18B20 resolution (9-12 bits)

        
        LogicImplementer core;
        InputsHandler inputs; 
        OutputsHandler outputs;         


         inputs.setObserver(core);
         inputs.setDallasTemperature(sensors);

        outputs.setSerial2ParallelPins(OUT_dataPin,OUT_clockPin,OUT_latchPin,OUT_buzzerPin);
        outputs.initialize();
        //OutputsHandler::setOutputsHandlerInstance(outputs);

        core.setOutputsHandler(outputs);   
        // core.setInputsHandler(inputs);
        core.setLogicImplementerInstance(core);
        core.initialize();

        
        while(1){

                inputs.check();
                core.check();
               
                //delay(100);
        }
  

}

void loop() {
}
