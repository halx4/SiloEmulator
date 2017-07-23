#ifndef LOGICIMPLEMENTER
#define LOGICIMPLEMENTER

#include "SiloEmulator.h"
#include "OutputsHandler.h"
#include "MyTimer1.h"
#include "IOWord.h"
#include "LiquidLevel.h"


class LogicImplementer {

public:
             LogicImplementer();
             
             void setOutputsHandler(OutputsHandler& outputs);
             //void setInputsHandler(InputsHandler& inputs);
             static void setLogicImplementerInstance(LogicImplementer& core);
             void initialize();
            
             static void levelTimerWrapper();
             static void temperatureTimerWrapper();
              
             void levelTimerEvent();
             void temperatureTimerEvent();
        
             void setCurrentInputs(uint8_t inputsByte,uint8_t temperature);
             void check();     

private:

            OutputsHandler* outputs_;
            //InputsHandler* inputs_;
            //void updateOutputs();
            
            
            uint8_t bool2Int(bool val);
            bool int2Bool(int val);
                        
            static LogicImplementer* logicImplementerInstance;
           
            MyTimer1 levelTimer, temperatureTimer;
            IOWord currentState;//,previousState;

            LiquidLevel liquidLevel;
            uint8_t previousTemperature;
    
};

#endif
