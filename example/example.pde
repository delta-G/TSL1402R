

#include <TSL1402R.h>
#define BUTTON 9  // button trigger in example, not part of class


TSL1402R array(8,7,4,0);


void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  int readout[256];
  byte but_val=0;
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  
  but_val=digitalRead(BUTTON);
  
  if (but_val==HIGH)
    {
      array.readPDA(readout);
      delay(50);
      array.readPDA(readout);
      for (int count=0; count<256; count++)
      {
        Serial.print(readout[count]);
        Serial.print(" , ");
        if (( count % 16)==15)
          Serial.println(" ");
      }
       but_val=0;
      Serial.println(" ");
      Serial.println(" ");   
    }
    
  
}



