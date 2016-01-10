#ifndef INPUTSHANDLER
#define INPUTSHANDLER

#include "SiloSimulator.h"
#include "IOWord.h"
#include <DallasTemperature.h>

class LogicImplementer;


class InputsHandler {

public:

        InputsHandler();
        void setDallasTemperature(DallasTemperature & thermometer);
        
        void setObserver(LogicImplementer & core);

        void check();

        
private:
        

        LogicImplementer* core_;
        DallasTemperature* thermometer_;
       
        
};

#endif
