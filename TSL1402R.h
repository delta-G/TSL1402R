//  Class to handle data from TSL1402R linear photodiode array

#ifndef TSL1402R_h
#define TSL1402R_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class TSL1402R
{
  
  // SI, CLK, and SO are digital pins, AO is an analog input pin
  //SPEED is the clock speed in KHz (10-30) defaults to 10
  
  public:
    TSL1402R(byte SI, byte CLK, byte SO, byte AO);
    TSL1402R(byte SI, byte CLK, byte SO, byte AO, int SPEED);
    void readPDA(int *pixel);
  private:
    int _SPEED;  //speed in KHz for clock pin (5-30 i think)
    byte _SI;    //SI1 (pin-2 on TSL1402R)
    byte _CLK;   //CLK (pin-3 on TSL1402R)
    byte _SO;    //SO2 (pin-6 on TSL1402R)
    byte _AO;    //AO1 and AO2 (pin 4 and pin 8 on TSL1402R)
    //int _pixel[256];   //private array for holding reads.  May be useful later.
      
};  

#endif



