//  Class TSL1402R member functions

#include "TSL1402R.h"


TSL1402R::TSL1402R(byte SI, byte CLK, byte SO, byte AO, int SPEED)
{
  _SI=SI;
  _CLK=CLK;
  _SO=SO;
  _AO=AO;
  _SPEED=SPEED;
  
}

TSL1402R::TSL1402R(byte SI, byte CLK, byte SO, byte AO)
{
  _SI=SI;
  _CLK=CLK;
  _SO=SO;
  _AO=AO;
  _SPEED=10;

}

void TSL1402R::readPDA(int *pixel)
{
  pinMode(_SI, OUTPUT);
  pinMode(_CLK, OUTPUT);
  pinMode(_SO, INPUT);
  digitalWrite(_CLK, LOW);
  digitalWrite(_SI, LOW);
  
  int del = (1000/_SPEED);
  unsigned long time;
  //byte SO_val=0;
  
  delayMicroseconds(del);
  digitalWrite (_SI, HIGH);
  delayMicroseconds(del/4);
  
  for (int count=0; count<256; count++)
  {
    digitalWrite(_CLK, HIGH);
    time=micros();
    while (micros()-time < (del/4)){
      delayMicroseconds(4);
    }
    
    pixel[count] = analogRead(_AO);
    if (count==1)
      digitalWrite(_SI, LOW);
    while (micros()-time < (del/2)){
      delayMicroseconds(4);
    }
    digitalWrite(_CLK, LOW);
    while (micros()-time < (del)){
      delayMicroseconds(4);
    }
  }
  //SO_val=digitalRead(SO);
  //if (SO_val==LOW)
  //    Serial.println("SO failed to go high!!!");
  digitalWrite(_CLK, HIGH);
  delayMicroseconds(del/2);
  digitalWrite(_CLK, LOW);
  //SO_val=digitalRead(SO);
  //if (SO_val==HIGH)
      //Serial.println("SO failed to return LOW!!!");
}

