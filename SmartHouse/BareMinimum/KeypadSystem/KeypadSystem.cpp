#include "KeypadSystem.h"

//Keypad
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};
byte rowPins[rows] = {37,36,35,34};
byte colPins[cols] = {33,32,31,30};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );
String keypadString = "";


char ReadKeypad()// Reads from the Keypad
{
	char key  = keypad.getKey();
	if (key != NO_KEY)
	{
		return key;
	}
}
void keypadStringReset()// Resets what is in the global KeypadString
{
	keypadString = "";
}
