#ifndef INPUTSHANDLER
#define INPUTSHANDLER

#include "SiloEmulator.h"

class LogicImplementer;


class InputsHandler {

public:

        InputsHandler();
       
        void setObserver(LogicImplementer & core);

        void check();

        
private:
        

        LogicImplementer* core_;
        
};

#endif
