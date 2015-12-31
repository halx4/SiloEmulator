//#include "InputsHandler.h"
#include "LogicImplementer.h"


LogicImplementer::LogicImplementer(){
        //Serial.println("LogicImplementer CREATED");
}
//---------------------------------------------------------
     void LogicImplementer::setInValve(bool newState){
          word_.setBit(10,newState);
          updateOutputs();
      }
     //--------------------------------
     void LogicImplementer::setOutValve(bool newState){
          word_.setBit(11,newState);
          updateOutputs();
      }
     //--------------------------------
     void LogicImplementer::reqHighLevelSensorOutput(){
          
      }
     //--------------------------------
     void LogicImplementer::reqLowLevelSensorOutput(){
          
      }
     //--------------------------------
     void LogicImplementer::setMixerState(bool newState){
          word_.setBit(15,newState);
          updateOutputs();
      }
     //--------------------------------
     void LogicImplementer::setHeaterState(bool newState){
          word_.setBit(14,newState);
          updateOutputs();
      }
//---------------------------------------------------------
void LogicImplementer::initialize(){
      
      tempUpdater.setMode(REPEATING);
      tempUpdater.setIntervalMinutes(TIME_TO_INCREASE_1_DEG_MS); 
      tempUpdater.setCallback(LogicImplementer::tempUpdaterWrapper);
      
      levelUpdater.setMode(REPEATING);
      levelUpdater.setIntervalMinutes(TIME_TO_INCREASE_LIQUID_LEVEL_MS);
      levelUpdater.setCallback(LogicImplementer::levelUpdaterWrapper);

      word_.setWord(0);
      (*outputs_).setOutputs(word_.getWord());
      //TODO INITIALIZE LEVEL SENSORS
}  
//---------------------------------------------------------
void LogicImplementer::setOutputsHandler(OutputsHandler & outputs){
  outputs_=&outputs;

}  
//---------------------------------------------------------
//void LogicImplementer::setInputsHandler(InputsHandler & inputs){
//  inputs_=&inputs;

//}  
//---------------------------------------------------------
void LogicImplementer::setLogicImplementerInstance(LogicImplementer & core){
    
    LogicImplementer::logicImplementerInstance=&core;
 }
//---------------------------------------------------------


//---------------------------------------------------------
void LogicImplementer::levelUpdaterEvent(){

         
        
        
}
//---------------------------------------------------------
void LogicImplementer::tempUpdaterEvent(){

        
}
//---------------------------------------------------------

void LogicImplementer::tempUpdaterWrapper(){
        (*LogicImplementer::logicImplementerInstance).tempUpdaterEvent();    
}
//---------------------------------------------------------

void LogicImplementer::levelUpdaterWrapper(){
        (*LogicImplementer::logicImplementerInstance).levelUpdaterEvent();    
}
//---------------------------------------------------------
void LogicImplementer::updateOutputs(){
  (*outputs_).setOutputs(word_.getWord());
  }
//---------------------------------------------------------
void LogicImplementer::check(){

    tempUpdater.check();
    levelUpdater.check();
}

//----------------------------------------------------------
LogicImplementer* LogicImplementer::logicImplementerInstance;





