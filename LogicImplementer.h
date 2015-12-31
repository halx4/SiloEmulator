#ifndef LOGICIMPLEMENTER
#define LOGICIMPLEMENTER

#include "SiloSimulator.h"
#include "OutputsHandler.h"
#include "MyTimer1.h"
#include "IOWord.h"
//#include "InputsHandler.h"
//class OutputsHandler;
//class InputsHandler;

//class InputsHandler;



class LogicImplementer {

public:
     LogicImplementer();
     
     void setOutputsHandler(OutputsHandler& outputs);
     //void setInputsHandler(InputsHandler& inputs);
     static void setLogicImplementerInstance(LogicImplementer& core);
     void initialize();
    
     static void levelUpdaterWrapper();
     static void tempUpdaterWrapper();
      
     void levelUpdaterEvent();
     void tempUpdaterEvent();

     void setCurrentInputs(uint8_t inputsByte,int temperature);
     void check();     

private:

    OutputsHandler* outputs_;
    //InputsHandler* inputs_;
    void updateOutputs();
    
    static LogicImplementer* logicImplementerInstance;
   
    MyTimer1 levelUpdater, tempUpdater;
    IOWord word_;
};

#endif
