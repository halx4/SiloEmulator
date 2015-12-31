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

       // inputs.setObserver(core);
        
        outputs.setSerial2ParallelPins(OUT_dataPin,OUT_clockPin,OUT_latchPin,OUT_buzzerPin);
        outputs.initialize();
        //OutputsHandler::setOutputsHandlerInstance(outputs);

        core.setOutputsHandler(outputs);   
       // core.setInputsHandler(inputs);
        core.setLogicImplementerInstance(core);
        core.initialize();

        uint16_t a=0;
        while(1){
          /*  a=((a<<1)|1);
            outputs.setOutputs(a);
           
           // delay(500);
            
            if(a==65535)a=0;
                Serial.print("starting");
            sensors.requestTemperatures(); // Send the command to get temperatures
            Serial.println("DONE");
            
           Serial.print("Temperature for Device 1 is: ");
           //Serial.print(sensors.getTempCByIndex(0));
               outputs.setTemperature(sensors.getTempCByIndex(0));      
        */
        inputs.check();
        delay(500);
        }
  

}

void loop() {
}
