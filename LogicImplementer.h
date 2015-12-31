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
    
     void setInValve(bool newState);    //true=open=on
     void setOutValve(bool newState);   //false=closed=off
     
     void reqHighLevelSensorOutput();         //true=Liquid Detected
     void reqLowLevelSensorOutput();          //false=iquid Not Detected
     
     void setMixerState(bool newState);   //true=operating
     void setHeaterState(bool newState);  //false=not operating
     
     void reqTemperature();   //in degrees Celsius
     
     static void levelUpdaterWrapper();
     static void tempUpdaterWrapper();
      
     void levelUpdaterEvent();
     void tempUpdaterEvent();
     
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
