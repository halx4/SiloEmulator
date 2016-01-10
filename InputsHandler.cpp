#include "InputsHandler.h"
#include "LogicImplementer.h"



InputsHandler::InputsHandler(){
        //Serial.println("InputsHandler CREATED");

}
//------------------------------------
void InputsHandler::setObserver(LogicImplementer & core){
        //Serial.println("InputsHandler::setObserver ran");
        core_=&core; 

}      
//------------------------------------
void InputsHandler::check(){
        uint8_t inputsByte=0;
        if(!digitalRead(IN_heaterPin))inputsByte+=B1;                   
        if(!digitalRead(IN_mixerPin))inputsByte+=B10;
        if(!digitalRead(IN_OutValvePin))inputsByte+=B100;
        if(!digitalRead(IN_InValvePin))inputsByte+=B1000;
        

        
        (*core_).setCurrentInputs(inputsByte);
}




