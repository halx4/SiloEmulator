#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "LogicImplementer.h"

class Dispatcher {

public:
    void setMethodsContainer(LogicImplementer& core_);
    
       
    void check();  

private:
    

    LogicImplementer* core;   
};
#endif
