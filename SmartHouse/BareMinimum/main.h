/*
 * SmartHouse.h
 *
 * Created: 06-12-2021 13:43:45
 *  Author: JensN
 */ 


#ifndef SMARTHOUSE_H_
#define SMARTHOUSE_H_

#include <Arduino.h>					// Main Library
#include <Wire.h>						// I2C library. (INTER-INTEGRATED CIRCUIT)
#include <Servo.h>						// Servo library.
#include <TimerOne.h>					// Timer & interrupt library.
#include "DHT11/OwnDHT11.h"				// DHT11 controls
#include "DisplayOnLC/DisplayOnLC.h"	// LiqudCrystal controls
#include "OLED/DisplayOnOLED.h"			// OLED controls
#include "RFScanner/RFScanner.h"		// Radio frequency scanner controls
#include "AtomicClock/AtomicClock.h"	// Atomic Clock frequency controls
#include "MenuSystem/MenuSystem.h"		// The in house menuSystem
#include "KeypadSystem/KeypadSystem.h"	//Keypad controls.
//Door Control
#define  BUTTONPIN 19
#define doorStateOpen 179			// What angle the door should be in when open.
#define doorStateClosed 1			// What angle the door should be in when closed.
#define doorDelay 5000				// How long the door should stay open. 10 seconds.

//Servo Control
#define ServoControl 44				// Pin number of the Servo.

//LED's
#define LED12 12	//Red	LED
#define LED11 11	//Green LED
#define LED10 10	//Green LED
#define LED9 9		//Green LED
#define LED8 8		//Blue	LED
#define LED7 7		//Green LED
#define LED6 6		//Red	LED

//Party
#define lastPartyDelay 200

//LightSensor
#define LIGHTSENSOR A1
#define blindsDelay 5000
#define blindsDelayMover 100

//Functional prototyping
void OpenCloseDoor();		// Door Control.
void MoveServo(int angle);	// Servo Control.
void OpenDoor();			// Open the door.
void CloseDoor();			// Close the door.
void SetInfomation();		// Main loop for the time display and weather display.
void SetWeather();			// Writes the weather information on the OLED display.
void SetTime();				// Writes the Time on the OLED display.
void SetDate();				// Writes the Date on the OLED display.
void SetTemprature();		// Writes the temperature on the OLED display.
void SetHumid();			// Writes the humidity on the OLED display.
void ButtonInterrupt();		// Interrupt.
void DoorLocker();			// Locks door and set alarm.					
void SetBlinds();			// Defines where the blinds should be based on the amount of light coming in.
void Mode();				// Changes based on what mode the house is in.

#endif /* SMARTHOUSE_H_ */