#ifndef ard4-7seglib_h
#define ard4-7seglib_h
// Just in case we are included twice

#include <Arduino.h>

class segment_disp
{
	public:
		//// Constructors	
			//For shift registers		
		segment_disp(boolean); // Copy constructor		
		
		//// Digit functions
		void displayDigit(int,int); // Display individual digits on a specific display
		void displayNumber(int); // Display multiple or single numbers		
		String decodeAsString(int); // Convert digit to individual pins		
		byte decodeAsByte(int);
		
		//// Generic display functions
		void clear(); // Clear display
				
		//// Pin functions
		void setDigitPins(int,int,int,int); // Sets the digit pin layout		
		void setSegPins(int,int,int,int,int,int,int,int); //Sets the segment pin layout
		
		//// Shift register functions
		void setRegisterPins(int,int,int); // Sets shift register pin layout
		
	private:
		int _dPins[4]; // Digit pins
		int _sPins[8]; // Segment pins
		boolean _isShift; // Is using shift register?		
		int _latchPin; //Pin connected to ST_CP of 74HC595		
		int _clockPin; //Pin connected to SH_CP of 74HC595		
		int _dataPin; //Pin connected to DS of 74HC595
};

#endif



