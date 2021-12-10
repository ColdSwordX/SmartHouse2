/*
 * DisplayOnLC.h
 *
 * Created: 09-12-2021 09:23:23
 *  Author: JensN
 */ 


#ifndef DISPLAYONLC_H_
#define DISPLAYONLC_H_

#include <LiquidCrystal.h>			// 2 x 16 display library.
#include <Arduino.h>
void WriteToLiquidCrystal(String input, int col, int row);	// Writing to the LiquidCrystal display.


#endif /* DISPLAYONLC_H_ */