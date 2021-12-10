#include "DisplayOnOLED.h"


extern Adafruit_SSD1306 display;

void WriteToOLED(String _input, int _row, int _col, int size )// What should be written to the OLED display and where.
{
	display.setTextColor(WHITE);
	display.setCursor( _row , _col );
	display.print(_input);
}
