/*
 * MenuSystem.h
 *
 * Created: 09-12-2021 08:27:58
 *  Author: JensN
 */ 


#ifndef MENUSYSTEM_H_
#define MENUSYSTEM_H_

#include <Arduino.h>
#include "../DisplayOnLC/DisplayOnLC.h"
#include "../KeypadSystem/KeypadSystem.h"


#define PUTMETER A0
#define MenuDelay 100

//Functional prototyping
void MenuSystem(); // Controls the flow of the Menu system.
void MenuScroll(); // Scrolls though the menu items (vary basic).
void MenuChooser(int _pos); // The item to see where you are at.
void MenuItem();
bool GetMode(); // returns the state of "party"

#endif /* MENUSYSTEM_H_ */