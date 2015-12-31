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

     // temperatureTimer.setEnabled(true);
     // levelTimer.setEnabled(true);
      
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

       // if()
        


        
}
//---------------------------------------------------------
void LogicImplementer::levelTimerEvent(){

         Serial.println("levelTimerEvent");
        
        
}
//---------------------------------------------------------
void LogicImplementer::temperatureTimerEvent(){

         Serial.println("temperatureTimerEvent");
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
void LogicImplementer::updateOutputs(){
 // (*outputs_).setOutputs(word_.getWord());   //TODO
  }
//---------------------------------------------------------
void LogicImplementer::check(){

    temperatureTimer.check();
    levelTimer.check();
}

//----------------------------------------------------------
LogicImplementer* LogicImplementer::logicImplementerInstance;





