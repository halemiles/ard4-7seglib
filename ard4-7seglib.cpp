#include <ard4-7seglib.h>

segment_disp::segment_disp(boolean isShift)
{	
	_isShift = isShift;
}

void segment_disp::displayDigit(int pow, int num)
{
	//Turn the digit on
	digitalWrite(pow, HIGH);
	
	if(_isShift)
	{
		// Get number as byte
		byte digit = decodeAsByte(num);
		
		// Set the latch pin for current digit
		digitalWrite(_latchPin, LOW);
		
		// shiftOut the data
		shiftOut(_dataPin, _clockPin, MSBFIRST, digit); 
		
		// Set the latch pin for next digit
		digitalWrite(_latchPin, HIGH);
	}
	else
	{
		//Get the pin layout for digit
		String digit = String(decodeAsByte(num),BIN);
	
		//Set the segments to HIGH/LOW based on the pin setting
		for(int i=0;i<8;i++)
		{
			if(digit[i] == '0')
			  digitalWrite(i,LOW);
			else
			  digitalWrite(i,HIGH);
		}
		//Clear the display - Only required when we arnt using shift registers
    	clear();
	}
	//Turn the digit off
	digitalWrite(pow, LOW);
	
	
} 

void segment_disp::displayNumber(int number)
{
  	int temp;  
    // determine the digits of the number

	//Get thousand unit
    int thousand = number/1000;
        temp = number%1000;
        if(thousand > 0)
	        displayDigit(_dPins[0],thousand);
	        
	//Get hundred unit
    int hundred = temp/100;
        temp = temp%100;
        if(hundred > 0)
	        displayDigit(_dPins[1],hundred);
	        
	//Get ten unit
    int ten = temp/10 ;
        temp = temp%10;
        if(ten > 0)
	        displayDigit(_dPins[2],ten);
	        
	//Get unit unit
    int unit = temp;
        if(unit > 0)
	        displayDigit(_dPins[3],unit);
} 

String segment_disp::decodeAsString(int num)
{	
	return String(decodeAsByte(num),BIN);
}

byte segment_disp::decodeAsByte(int num)
{
				
	byte reVal[11]={  B10000001,						// 0
					  B11001111,B10010010,B10000110,	// 1,2,3
					  B11001100,B10100100,B10100000,	// 4,5,6
					  B10001111,B10000000,B10000100,	// 7,8,9
					  B11111110};						// -
	
	return reVal[num];
}

void segment_disp::clear()
{
	for(int i=0;i<8;i++)
	{
		  digitalWrite(_sPins[i],HIGH);		
	}
}

void segment_disp::setDigitPins(int d1, int d2, int d3, int d4)
{
	_dPins[0] = d1;
	_dPins[1] = d2;
	_dPins[2] = d3;
	_dPins[3] = d4;
}

void segment_disp::setRegisterPins(int latchP, int clockP, int dataP)
{
	//Pin connected to ST_CP of 74HC595
	_latchPin = latchP;
	//Pin connected to SH_CP of 74HC595
	_clockPin = clockP;
	////Pin connected to DS of 74HC595
	_dataPin = dataP;
}


void segment_disp::setSegPins(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8)
{
	_sPins[0] = p1;
	_sPins[1] = p2;
	_sPins[2] = p3;
	_sPins[3] = p4;
	_sPins[4] = p5;
	_sPins[5] = p6;
	_sPins[6] = p7;
	_sPins[7] = p8;	
}



