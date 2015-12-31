
#ifndef IOWORD
#define IOWORD

#include <Arduino.h>


class IOWord {

        struct Bits
        {
                unsigned    
                            b0:1,
                            b1:1,
                            b2:1,
                            b3:1, 
                            b4:1,
                            b5:1, 
                            b6:1, 
                            b7:1,
                            b8:1,
                            b9:1,
                            b10:1, 
                            b11:1,
                            b12:1, 
                            b13:1, 
                            b14:1,
                            b15:1;
        };
        
        union WordBits
        {
                Bits bits;
                uint16_t word_;
                uint8_t byte_[2];
        };


public:

        IOWord();
        
        void setBit(int bitNo,bool newState);
        bool getBit(int bitNo);
        bool toggleBit(int bitNo);  //returns new bit state
        uint16_t getWord();
        void setWord(uint16_t value);
        void setLSB(uint8_t newLSB);
        void setMSB(uint8_t newMSB);
        uint8_t getMSB();
        uint8_t getLSB();
        
        
private:
        
        WordBits wb;

        
        
        
};

#endif
