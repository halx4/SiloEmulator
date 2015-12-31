#include "LiquidLevel.h"




LiquidLevel::LiquidLevel(){
        
        LLDec=0;
}
//------------------------------------
uint8_t LiquidLevel::getLLDec(){
        return LLDec;
}
//------------------------------------
uint16_t LiquidLevel::getLLBin(){
        uint16_t LLBin=0;
        for(uint8_t i=0;i<LLDec;i++){
                LLBin=((LLBin<<1)|1);
        }
        return LLBin;
}
//------------------------------------        
void LiquidLevel::LLIncrease(){
        if(LLDec<10)LLDec++;
}
//------------------------------------
void LiquidLevel::LLDecrease(){
        if(LLDec>0)LLDec--;
}
//------------------------------------


