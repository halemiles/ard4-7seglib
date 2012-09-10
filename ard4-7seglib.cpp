#include <ard4-7seglib.h>

segment_disp::segment_disp()
{
	// Set the segment pins to 1 - 7
	for(int i=1;i<8;i++)
		_sPins[i-1] = i;
		
	// Set the display pins to 10 - 13
	_dPins[0] = 10;
	_dPins[1] = 11;
	_dPins[2] = 12;
	_dPins[3] = 13;
}

void segment_disp::displayDigit(int pow, int num)
{
	//Get the pin layout for digit
	String digit = decodeDigit(num);
	
	//Turn the digit on
	digitalWrite(pow, HIGH);
	
	//Set the segments to HIGH/LOW based on the pin setting
	for(int i=0;i<8;i++)
	{
		if(digit[i] == '1')
		{
		  digitalWrite(i,LOW);
		}
		else
		{
		  digitalWrite(i,HIGH);
		}
	}
	
	//Turn the digit off
	digitalWrite(pow, LOW);
	
	//Clear the display
    clear();
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

String segment_disp::decodeDigit(int num)
{	
	String reVal;
	
	//Get the pin layout based on the number input
	switch(num)
	{
		case 0:
			reVal = "01111110";
			break;
		case 1:
			reVal = "00110000";
			break;
		case 2:
			reVal = "01101101";
			break;
		case 3:
			reVal = "11111001";
			break;
		case 4:
			reVal = "00110011";
			break;
		case 5:
			reVal = "01011011";
			break;
		case 6:
			reVal = "01011111";
			break;
		case 7:
			reVal = "01110000";
			break;
		case 8:
			reVal = "01111111";
			break;
		case 9:
			reVal = "01111011";
			break;
		default:
			reVal = "0000001";
			break;
	}
	return reVal;
}

void segment_disp::clear()
{
	for(int i=1;i<9;i++)
	{
		  digitalWrite(i,HIGH);		
	}
}

void segment_disp::setDigitPins(int d1, int d2, int d3, int d4)
{
	_dPins[0] = d1;
	_dPins[1] = d2;
	_dPins[2] = d3;
	_dPins[3] = d4;
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



