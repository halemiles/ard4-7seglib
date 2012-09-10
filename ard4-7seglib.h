#ifndef ard4-7seglib_h
#define ard4-7seglib_h
// Just in case we are included twice

#include <Arduino.h>

class segment_disp
{
	public:
		//// Constructors
		segment_disp(); // Copy constructor
		
		//// Digit functions
		void displayDigit(int,int); // Display individual digits on a specific display
		void displayNumber(int); // Display multiple or single numbers
		String decodeDigit(int); // Convert digit to individual pins
		
		//// Generic display functions
		void clear(); // Clear display
				
		//// Digit pin functions
		void setDigitPins(int,int,int,int); // Sets the digit pin layout
		
		//// Segment pin functions
		void setSegPins(int,int,int,int,int,int,int,int);
		
	private:
		int _dPins[4]; // Digit pins
		int _sPins[8]; // Segment pins
};

#endif



