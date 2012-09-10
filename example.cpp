#include <Arduino.h>
#include <ard4-7seglib.h>

//Create segment_disp
segment_disp disp;

void setup()
{
  //Initialise segment pins (1 to 8)
  for (int segPin = 1; segPin <= 8; segPin++)
    pinMode(segPin, OUTPUT);

  //Initialise digit pins (10 to 13)
  for (int digitPin = 10; digitPin <= 13; digitPin++)
    pinMode(digitPin, OUTPUT); 
  
}

void loop()
{ 
  //Display a number
  disp.displayNumber(4539);
}
