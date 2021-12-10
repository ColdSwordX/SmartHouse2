#ifndef KEYPADSYSTEM_H_
#define KEYPADSYSTEM_H_

#include <Arduino.h>	
#include <Keypad.h>					// The 4 x 4 Keypad library.s

char ReadKeypad();				// Reads from the Keypad.
void keypadStringReset();		// Resets the input string from the keypad.

#endif /* KEYPADSYSTEM_H_ */