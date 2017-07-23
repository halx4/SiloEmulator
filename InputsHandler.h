#ifndef INPUTSHANDLER
#define INPUTSHANDLER

#include "SiloEmulator.h"
#include "IOWord.h"

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
