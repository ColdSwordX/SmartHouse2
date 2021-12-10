#include "MenuSystem.h"


int numberOfItems = 4;
String menuItems[] = {"Mode        ","Blinds      ","Temperature ","Alarm       " };
int PWDValue = 0;
int oldValue = 0; 
int MenuChooserCursor = 0; // from 2 to 5
int menuItemChosen = -1;
int menuItemAtIndex = 0; 
bool InMenuItem = false;
//Mode
bool Party = false;

bool GetMode()
{
	return Party;
}

void MenuSystem()
{
	menuItemAtIndex = map(analogRead(PUTMETER),0,1024,0,numberOfItems);
	if (InMenuItem)
	{
		MenuItem();
	}
	else
	{
		menuItemChosen = -1;
		MenuScroll();
	}
}
void MenuScroll()
{
	if (menuItemAtIndex == 0)
	{
		WriteToLiquidCrystal(menuItems[0],0,0);
		WriteToLiquidCrystal(menuItems[1],1,0);
		MenuChooser(0);
	}
	else if (menuItemAtIndex == 1)
	{
		WriteToLiquidCrystal(menuItems[0],0,0);
		WriteToLiquidCrystal(menuItems[1],1,0);
		MenuChooser(1);
	}
	else if (menuItemAtIndex == 2)
	{
		WriteToLiquidCrystal(menuItems[1],0,0);
		WriteToLiquidCrystal(menuItems[2],1,0);
		MenuChooser(1);
	}
	else if (menuItemAtIndex == 3)
	{
		WriteToLiquidCrystal(menuItems[2],0,0);
		WriteToLiquidCrystal(menuItems[3],1,0);
		MenuChooser(1);
	}
}
void MenuChooser(int _pos)
{
	if (_pos == 1)
	{
		WriteToLiquidCrystal(" ",_pos - 1,15);
		WriteToLiquidCrystal("X",_pos,15);
	}
	else
	{
		WriteToLiquidCrystal("X",_pos,15);
		WriteToLiquidCrystal(" ",_pos + 1,15);
	}
	if (ReadKeypad() == '*')
	{
		InMenuItem = true;
	}
}
void MenuItem()
{
	switch (menuItemAtIndex)
	{
		case 0:
			{
				WriteToLiquidCrystal("Change Mode?",0,0);
				WriteToLiquidCrystal(" * to change",1,0);
				char value = ReadKeypad();
				if (value == '*')
				{
					Party = !Party;
					InMenuItem = false;
				}
			}
		break;
		case 1:
			WriteToLiquidCrystal("nothing",0,0);
			WriteToLiquidCrystal("nothing",1,0);
		break;
		case 2:
			WriteToLiquidCrystal("nothing",0,0);
			WriteToLiquidCrystal("nothing",1,0);
		break;
		case 3:
			WriteToLiquidCrystal("nothing",0,0);
			WriteToLiquidCrystal("nothing",1,0);
		break;
	}
	if (ReadKeypad() == '#')
	{
		InMenuItem = false;
	}
}