#ifndef LIQUID_LEVEL
#define LIQUID_LEVEL

#include "SiloSimulator.h"


class LiquidLevel {

public:

        LiquidLevel();
        
        uint8_t getLLDec();
        uint16_t getLLBin();
        void LLIncrease();
        void LLDecrease();
        
        
private:
        byte LLDec;
      
};

#endif
