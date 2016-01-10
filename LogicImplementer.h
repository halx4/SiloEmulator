#ifndef LOGICIMPLEMENTER
#define LOGICIMPLEMENTER

#include "SiloSimulator.h"
#include "OutputsHandler.h"
#include "MyTimer1.h"
#include "IOWord.h"
#include "LiquidLevel.h"


class LogicImplementer {

public:
             LogicImplementer();
             
             void setOutputsHandler(OutputsHandler& outputs);
             
             static void setLogicImplementerInstance(LogicImplementer& core);
             void initialize();
            
             static void levelTimerWrapper();
             static void temperatureTimerWrapper();
              
             void levelTimerEvent();
             void temperatureTimerEvent();
        
             void setCurrentInputs(uint8_t inputsByte);
             void check();     

private:

            OutputsHandler* outputs_;

            
            uint8_t bool2Int(bool val); //TODO remove it
            bool int2Bool(int val);
                        
            static LogicImplementer* logicImplementerInstance;
           
            MyTimer1 levelTimer, temperatureTimer;
            IOWord currentState;

            LiquidLevel liquidLevel;
            uint8_t temperature;
    
};

#endif
