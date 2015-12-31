#include "SiloSimulator.h"
#include "LogicImplementer.h"
//#include "InputsHandler.h"
#include "OutputsHandler.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#include <SPI.h>


const int OUT_dataPin = 7; 
const int OUT_clockPin = 8;
const int OUT_latchPin = 9;
const int OUT_buzzerPin=6;
const int ONE_WIRE_BUS=2;

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
        

       // SPI.begin ();
          sensors.begin();
        // sensors.setResolution(9);
        LogicImplementer core;
        //InputsHandler inputs; 
        OutputsHandler outputs;         
        
        //inputs.setLatchPin(LATCH);
        //inputs.setTM1638Module(tm1638Module);
       // inputs.setObserver(core);
        

        outputs.setSerial2ParallelPins(OUT_dataPin,OUT_clockPin,OUT_latchPin,OUT_buzzerPin);
        outputs.initialize();
        //outputs.setTM1638Module(tm1638Module);
        //OutputsHandler::setOutputsHandlerInstance(outputs);
        
        
        core.setOutputsHandler(outputs);   
       // core.setInputsHandler(inputs);
        core.setLogicImplementerInstance(core);
        core.initialize();

       // //Serial.println("end main initialization");
        uint16_t a=0;
      while(1){
            a=((a<<1)|1);
            outputs.setOutputs(a);
           
           // delay(500);
            
            if(a==65535)a=0;
                Serial.print("starting");
            sensors.requestTemperatures(); // Send the command to get temperatures
            Serial.println("DONE");
            
           Serial.print("Temperature for Device 1 is: ");
           //Serial.print(sensors.getTempCByIndex(0));
               outputs.setTemperature(sensors.getTempCByIndex(0));      
        }
  

}

void loop() {
}
