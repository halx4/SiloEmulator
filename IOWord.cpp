#include "IOWord.h"


IOWord::IOWord(){
        setWord(0);
                
}
//-------------------------------
void IOWord::setBit(int bitNo,bool newState){
       
        unsigned int newValue;
        if(newState)newValue=1; else newValue=0;
        
        switch(bitNo){
        case 0:
                wb.bits.b0=newValue;
                break;
        case 1:
                wb.bits.b1=newValue;
                break;
        case 2:
                wb.bits.b2=newValue;
                break;
        case 3:
                wb.bits.b3=newValue;
                break;
        case 4:
                wb.bits.b4=newValue;
                break;
        case 5:
                wb.bits.b5=newValue;
                break;
        case 6:
                wb.bits.b6=newValue;
                break;
        case 7:
                wb.bits.b7=newValue;
                break;                  
        case 8:
                wb.bits.b8=newValue;
                break;
        case 9:
                wb.bits.b9=newValue;
                break;
        case 10:
                wb.bits.b10=newValue;
                break;
        case 11:
                wb.bits.b11=newValue;
                break;
        case 12:
                wb.bits.b12=newValue;
                break;
        case 13:
                wb.bits.b13=newValue;
                break;
        case 14:
                wb.bits.b14=newValue;
                break;
        case 15:
                wb.bits.b15=newValue;
                break;                  
        }

}
//-------------------------------
bool IOWord::getBit(int bitNo){

        switch(bitNo){
        case 0:
                return wb.bits.b0;
                break;
        case 1:
                return wb.bits.b1;
                break;
        case 2:
                return wb.bits.b2;
                break;
        case 3:
                return wb.bits.b3;
                break;
        case 4:
                return wb.bits.b4;
                break;
        case 5:
                return wb.bits.b5;
                break;
        case 6:
                return wb.bits.b6;
                break;
        case 7:
                return wb.bits.b7;
                break;   
        case 8:
                return wb.bits.b8;
                break;
        case 9:
                return wb.bits.b9;
                break;
        case 10:
                return wb.bits.b10;
                break;
        case 11:
                return wb.bits.b11;
                break;
        case 12:
                return wb.bits.b12;
                break;
        case 13:
                return wb.bits.b13;
                break;
        case 14:
                return wb.bits.b14;
                break;
        case 15:
                return wb.bits.b15;
                break;   

        }
        


}
//-------------------------------
bool IOWord::toggleBit(int bitNo){
        setBit(bitNo,!getBit(bitNo));  
        return getBit(bitNo);     

}
//-------------------------------
uint16_t IOWord::getWord(){
        return wb.word_;


}
//-------------------------------
void IOWord::setWord(uint16_t value){
        wb.word_=value;
}      
//--------------------------------
void IOWord::setLSB(uint8_t newLSB){
    setWord( (getWord() & 0xFF00)  |  newLSB);
    
    
    
    
    
}
//--------------------------------

uint8_t IOWord::getLSB(){
     
    return wb.byte_[0];

}
//--------------------------------

void IOWord::setMSB(uint8_t newMSB){
    uint16_t newMSB16=(uint16_t)newMSB;
   setWord(  (getWord() & 0x00FF)  |  (newMSB16<<8) );
    
    
    
}
//-------------------------------
uint8_t IOWord::getMSB(){

    return wb.byte_[1];

}
