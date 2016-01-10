#include "OutputsHandler.h"




OutputsHandler::OutputsHandler(){
           // Serial.println("OutputsHandler CREATED");
        
}
//--------------------------------
void OutputsHandler::setSerial2ParallelPins(int dataPin,int clockPin,int latchPin, int buzzerPin){
            data=dataPin;      
            clock=clockPin;
            latch=latchPin;
            buzzer=buzzerPin;
}
//--------------------------------

void OutputsHandler::initialize(){
  SPI.begin ();
  sendByte (MAX7219_REG_SCANLIMIT, 1);      // show 4 digits
  sendByte (MAX7219_REG_DECODEMODE, 0xFF);  // use digits (not bit patterns)
  sendByte (MAX7219_REG_DISPLAYTEST, 0);    // no display test
  sendByte (MAX7219_REG_INTENSITY, 7);      // character intensity: range: 0 to 15
  sendByte (MAX7219_REG_SHUTDOWN, 1);       // not in shutdown mode (ie. start it up)
            
    
}
//------------------------
void OutputsHandler::sendByte (const byte reg, const byte data){
  
      digitalWrite (SS, LOW);
      SPI.transfer (reg);
      SPI.transfer (data);
      digitalWrite (SS, HIGH); 
  }  // end of sendByte

//------------------------
void OutputsHandler::setTemperature(int temperature){
  
 
     char buf [3];
     sprintf (buf, "%2i", min (max (temperature, 0), 99));
     
     // send all 2 digits
     for (byte digit = 0; digit < 2; digit++)
       {
       byte c = buf [digit];
       if (c == ' ' )
         c = 0xF;  // code for a blank
       else
         c -= '0';
       sendByte (digit + 1, c);  
       }   

       Serial.print("T=");
       Serial.print(temperature);
       Serial.print("\n");
  } 
/*

//------------------------------

void OutputsHandler::setOutputsHandlerInstance(OutputsHandler & outputs){
    
    OutputsHandler::outputsInstance=&outputs;
    
}
//--------------------------------

void OutputsHandler::updateShiftRegOutputs(){
            digitalWrite(latch, LOW);     //Pulls the chips latch low
            shiftOut(data, clock, MSBFIRST, relaysWord.getMSB()); //Shifts out the 8 bits to the shift register
            shiftOut(data, clock, MSBFIRST, relaysWord.getLSB());
            digitalWrite(latch, HIGH);   
        
}



//-----------------------------
OutputsHandler* OutputsHandler::outputsInstance;

//--------------------
*/
void OutputsHandler::setOutputs(uint16_t _word){
          uint8_t msb,lsb;
          lsb=(_word&0xFF);
          msb=(_word-lsb)>>8;
          //Serial.print("lsb= ");
          //Serial.println(lsb,BIN);
          //Serial.print("msb= ");
          //Serial.println(msb,BIN);

          digitalWrite(latch, LOW);     //Pulls the chips latch low
          shiftOut(data, clock, MSBFIRST, msb); //Shifts out the 8 bits to the shift register
          shiftOut(data, clock, MSBFIRST, lsb);
          digitalWrite(latch, HIGH); 

          #ifdef BUZZERENABLED 
                if((msb&B10000000)!=0)tone(buzzer, 262); //mixer enabled
                else noTone(buzzer);
          #endif
          
          //Serial.println();
        }


//-----------------------------------------

       

