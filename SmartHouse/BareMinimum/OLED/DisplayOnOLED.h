/*
 * DisplayOnOLED.h
 *
 * Created: 09-12-2021 09:29:33
 *  Author: JensN
 */ 


#ifndef DISPLAYONOLED_H_
#define DISPLAYONOLED_H_

#include <Adafruit_SSD1306.h>		// OLED display library.

//OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)

#define OLED_Line1 0
#define OLED_Line2 11
#define OLED_Line3 22
#define OLED_Line4 33
#define OLED_Line5 44
#define OLED_Line6 55

//Functional prototyping
void WriteToOLED(String _input, int _row, int _col, int size = 1 );		// What should be written to the OLED display and where.


#endif /* DISPLAYONOLED_H_ */