//#include "InputsHandler.h"
#include "LogicImplementer.h"


LogicImplementer::LogicImplementer(){
      //Serial.println("LogicImplementer CREATED");
}
//---------------------------------------------------------
void LogicImplementer::initialize(){
      
      temperatureTimer.setMode(REPEATING);
      temperatureTimer.setInterval(TIME_TO_INCREASE_1_DEG_MS); 
      temperatureTimer.setCallback(LogicImplementer::temperatureTimerWrapper);
      
      levelTimer.setMode(REPEATING);
      levelTimer.setInterval(TIME_TO_INCREASE_LIQUID_LEVEL_MS);
      levelTimer.setCallback(LogicImplementer::levelTimerWrapper);

      currentState.setWord(0);
      //Serial.print("word is ");Serial.println(currentState.getWord(),BIN);
      //previousState.setWord(0);
      previousTemperature=0;
      //(*outputs_).setOutputs(word_.getWord());

      temperatureTimer.setEnabled(true);
      levelTimer.setEnabled(true);
      
}  
//---------------------------------------------------------
void LogicImplementer::setOutputsHandler(OutputsHandler & outputs){
  outputs_=&outputs;

}  
//---------------------------------------------------------
void LogicImplementer::setLogicImplementerInstance(LogicImplementer & core){
    
    LogicImplementer::logicImplementerInstance=&core;
 }
//---------------------------------------------------------
void LogicImplementer::setCurrentInputs(uint8_t inputsByte, uint8_t temperature){
        bool changedFlag=false;
        
        if(previousTemperature!=temperature){
                previousTemperature=temperature;
                (*outputs_).setTemperature(temperature);
        }

       if(  int2Bool((inputsByte>>0)&1)   != currentState.getBit(14) ){
               // Serial.println("HEATER STATE CHANGE");
                currentState.setBit(14, int2Bool((inputsByte>>0)&1)   );
                changedFlag=true;
       }
       if(  int2Bool((inputsByte>>1)&1)   != currentState.getBit(15) ){
               // Serial.println("MIXER STATE CHANGE");
                currentState.setBit(15, int2Bool((inputsByte>>1)&1)   );
                changedFlag=true;
       }
       if(  int2Bool((inputsByte>>2)&1)   != currentState.getBit(11) ){
               // Serial.println("OUT VALVE STATE CHANGE");
                currentState.setBit(11, int2Bool((inputsByte>>2)&1)   );
                changedFlag=true;
       }
       if(  int2Bool((inputsByte>>3)&1)   != currentState.getBit(10) ){
                //Serial.println("IN VALVE STATE CHANGE");
                currentState.setBit(10, int2Bool((inputsByte>>3)&1)   );
                changedFlag=true;
       }

        if(changedFlag){ //change has been detected. refresh outputs
                (*outputs_).setOutputs(currentState.getWord()); 
        }

       
}
//---------------------------------------------------------
void LogicImplementer::levelTimerEvent(){

         //Serial.println("levelTimerEvent");
         if(currentState.getBit(10) && !(currentState.getBit(11))){  //if inValve(10) is open AND outValve(11) is closed then
                       liquidLevel.LLIncrease();
         }
        if(currentState.getBit(11) && !(currentState.getBit(10))){
                       liquidLevel.LLDecrease();
         }

        uint16_t tempLiquidLevel=liquidLevel.getLLBin();
        for(int i=0;i<10;i++){
                currentState.setBit(i, int2Bool(tempLiquidLevel&1) );
                tempLiquidLevel>>=1;
        }

        //update sensors' indications
        (FULL_SENSOR_POSITION    <= liquidLevel.getLLDec() ) ? currentState.setBit(12,true) : currentState.setBit(12,false);
        (EMPTY_SENSOR_POSITION <= liquidLevel.getLLDec() ) ? currentState.setBit(13,true) : currentState.setBit(13,false);
         
         (*outputs_).setOutputs(currentState.getWord()); 
        
}
//---------------------------------------------------------
void LogicImplementer::temperatureTimerEvent(){

         //Serial.println("temperatureTimerEvent");
}
//---------------------------------------------------------

void LogicImplementer::temperatureTimerWrapper(){
        (*LogicImplementer::logicImplementerInstance).temperatureTimerEvent();    
}
//---------------------------------------------------------

void LogicImplementer::levelTimerWrapper(){
        (*LogicImplementer::logicImplementerInstance).levelTimerEvent();    
}
//---------------------------------------------------------
void LogicImplementer::check(){

    temperatureTimer.check();
    levelTimer.check();
}

//----------------------------------------------------------
uint8_t LogicImplementer::bool2Int(bool val){
        if(val)return 1;
        else return 0;
}
//----------------------------------------------------------
bool LogicImplementer::int2Bool(int val){
        return val!=0;
}
//----------------------------------------------------------
LogicImplementer* LogicImplementer::logicImplementerInstance;





