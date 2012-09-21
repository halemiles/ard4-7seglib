/////////////////////////////////////////////////

### Arduino 4 digit 7 segment display library ###

/////////////////////////////////////////////////

A basic library for a 4 digit 7 segment display
for usage with direct pin output from Arduino and 
74HC595 shift registers. 

Currently common cathode displays are supported however 
it can be altered to work with common anode.

Basic usage:

--Connecting display directly to Arduino.
--Create object and define if shift registers are being used.
	
	segment_disp disp(false);
	
	void setup()
	{
		pinMode(2, OUTPUT);
	    pinMode(3, OUTPUT);
	    pinMode(4, OUTPUT);
	    pinMode(5, OUTPUT);
	    
	    for(int i=1;i<9;i++)
	    	pinMode(i, OUTPUT);
	    	
		disp.setDigitPins(2,3,4,5); 
  		disp.setSegmentPins(1,2,3,4,5,6,7,8);
	}
	
	void loop()
	{
		disp.displayNumber(1437);
	}
	
--Connecting display to shift register.
--Create object and define if shift registers are being used.
	
	segment_disp disp(true);
	
	void setup()
	{
		pinMode(10, OUTPUT);
	    pinMode(11, OUTPUT);
	    pinMode(12, OUTPUT);
	    pinMode(13, OUTPUT);
	    
	    pinMode(latchPin, OUTPUT);
  	    pinMode(clockPin, OUTPUT);
  	    pinMode(dataPin, OUTPUT); 
  	    
		disp.setDigitPins(10,11,12,13); 
  		disp.setRegisterPins(latchPin,clockPin,dataPin);
	}
	
	void loop()
	{
		disp.displayNumber(1437);
	}
