
#include "DisplayOnLC.h""

extern LiquidCrystal lcd;

void WriteToLiquidCrystal(String _input, int _line, int _position)//What and where something should be written to the Crystal display
{
	lcd.setCursor(_position, _line);
	lcd.print(_input);
}
