#include "main.h"

#pragma region varibuls

//Mode
int lastParty = 0;

//DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);	// DHT object

//Door control
volatile boolean doorLocked = false;
bool doorState = false;				// What state the door is in. open = "true".
bool isDoorClosed = false;			// Is the door open or closed, used when the door is open.
unsigned long lastDoorState = 0;	// When were the door opened last.

// Servo control
Servo myservo;						// The Servo Object.

//LiquidCrystal
const int rs = 49, en = 47, d4 = 45, d5 = 43, d6 = 41, d7 = 39;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Open door char
byte customOpenDoor[] = {
	B00000,
	B11111,
	B10001,
	B10001,
	B10001,
	B10001,
	B11111,
	B00000
};
// Closed door char
byte customClosedDoor[] = {
	0b00000,
	0b01111,
	0b01111,
	0b01111,
	0b01101,
	0b01111,
	0b01111,
	0b00000
};

byte customCharSpin1[] = {
	B00000,
	B00001,
	B00010,
	B00100,
	B01000,
	B10000,
	B00000,
	B00000
};
byte customCharSpin2[] = {
	B00000,
	B00000,
	B00000,
	B11111,
	B00000,
	B00000,
	B00000,
	B00000
};
byte customCharSpin3[] = {
	B00000,
	B10000,
	B01000,
	B00100,
	B00010,
	B00001,
	B00000,
	B00000
};
byte customCharSpin4[] = {
	B00000,
	B00100,
	B00100,
	B00100,
	B00100,
	B00100,
	B00000,
	B00000
};

//LED's
int LED_Lock_Level = 0;
int allLEDs[] = {LED12 , LED11 , LED10 , LED9 , LED8 , LED7 , LED6 }; // All LED's

//Scanner
MFRC522 mfrc522(SS_PIN,RST_PIN);
String AprovedCard = "305571a5";
MFRC522::MIFARE_Key key;

//Clock
RTClib myClock;
bool showClock = true;
unsigned long showClockDelay = 0;

//OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


//Blinds
unsigned long lastBlindsMove = 0;
int blindsTarget = 90;
int blindsAt = 90;
unsigned long blindsMover = 0;
int blindsMaxDown = 180;


#pragma endregion 


void setup() 
{
	Serial.begin(9600);
	//LED lights
	for (int i = 0; i < sizeof(allLEDs);i++)
	{
		pinMode(allLEDs[i],OUTPUT);
	}
	//LCD Crystal display.
	lcd.begin(16,2);
	lcd.createChar(0,customOpenDoor);
	lcd.createChar(1,customClosedDoor);
	lcd.createChar(2,customCharSpin1);
	lcd.createChar(3,customCharSpin2);
	lcd.createChar(4,customCharSpin3);
	lcd.createChar(5,customCharSpin4);
	//PutMeter
	pinMode(PUTMETER,INPUT);
	//Servo
	pinMode(ServoControl,OUTPUT);
	myservo.attach(ServoControl);
	//I2C OLED and Clock
	Wire.begin();
	//OLED
	display.begin(SSD1306_SWITCHCAPVCC,0x3C);
	//DHT11 weather control
	dht.begin();
	//RFC scanner
	SPI.begin();
	mfrc522.PCD_Init();
	// Key creation
	for (byte i = 0; i < 6; i++)
	{
		key.keyByte[i] = 0xFF;
	}
	//Button(Interrupt)
	pinMode(BUTTONPIN,INPUT_PULLUP);
	//Interrupt function
	attachInterrupt(digitalPinToInterrupt(BUTTONPIN),ButtonInterrupt,CHANGE);
}

void loop() 
{
	display.clearDisplay(); // Clears the OLED display, This is done to have a clean display.
	
	OpenCloseDoor(); // Controls if the door should be open or closed.
	SetInfomation(); // Set the information of time and weather information on the OLED.
	DoorLocker(); // Locks the door and Closes everything that is open.
	SetBlinds(); // Controls the Blinds in the house according to the Light level.
	MenuSystem(); // The in house menu control system.
	Mode(); // What "mode" the house is on.
	
	display.display(); // displays everything that should be displayed.
}
void OpenCloseDoor()// Door Control
{
	if (CardReader() == AprovedCard && !doorLocked)
	{
		OpenDoor();	
	}
	if (!isDoorClosed)
	{
		CloseDoor();
	}
	if (doorState)
	{
		LED_Lock_Level = 0;
		WriteToOLED("Open",0,0);
	}
	else
	{
		if (!doorLocked)
		{
			LED_Lock_Level = 100;
		}
		WriteToOLED("Closed",0,0);
	}
	if (millis() >= lastDoorState + doorDelay)
	{
		isDoorClosed = false;
		lastDoorState = millis();
	}
}
void OpenDoor()//Opens the door
{
	doorState = true;
	lastDoorState = millis();
}
void CloseDoor()//Closes the door
{	
	if (millis() >= lastDoorState + doorDelay && doorState )
	{
		doorState = false;
		isDoorClosed = true;
	}
}
void MoveServo(int angle)//Moves the Servo(door);
{
	myservo.write(angle);
}
void SetInfomation()//Main loop for the time display and weather display.
{
	analogWrite(LED12,LED_Lock_Level);
	if (millis() >= showClockDelay + 10000)
	{
		showClock = !showClock;
		showClockDelay = millis();
	}
	if (showClock)
	{
		SetTime();
		SetDate();
	}
	else
	{
		SetWeather();
	}
}
void SetWeather()// Writes the weather information on the OLED display.
{
	SetTemprature();
	SetHumid();
}
void SetTime()// Writes the time to the OLED display.
{
	WriteToOLED(GetTimeString(ReadClock()),0,OLED_Line6);
}
void SetDate()// Writes the date on the OLED display.
{
	WriteToOLED(GetDataString(ReadClock()),60,OLED_Line6);
}
void SetTemprature()// Writes the temperature on the OLED display.
{
	WriteToOLED(GetSensorTemp(),0,OLED_Line6);
}
void SetHumid()// Writes the humidity on the OLED display.
{
	WriteToOLED(GetSensorHumid(),60,50);
}
void ButtonInterrupt()// Interrupt Door Lock
{ 
	if (digitalRead(BUTTONPIN) == LOW && !doorState)
	{
		doorLocked = !doorLocked;
	}
}
void DoorLocker()// Locks the door
{
	if (doorLocked)
	{
		WriteToOLED("Locked",0,OLED_Line2);
		LED_Lock_Level = 255;
	}else
	{
		WriteToOLED("      ",0,OLED_Line2);
	}
}
void SetBlinds()// moves the "blinds" according to the Light level
{
	if (!doorLocked && millis() >= lastBlindsMove + blindsDelay)
	{
		blindsTarget = map(analogRead(LIGHTSENSOR),0,1024,0,blindsMaxDown);
		
		lastBlindsMove = millis();
	}
	if (millis() >= blindsMover + blindsDelayMover)
	{
		if (blindsAt < blindsTarget)
		{
			blindsAt++;
		}
		if (blindsAt > blindsTarget)
		{
			blindsAt--;
		}
		if (blindsAt <= blindsMaxDown && blindsAt >= 0)
		{
			MoveServo(blindsAt);
		}
	}
	String disTarget = (String)map(blindsAt,0,blindsMaxDown,0,99);
	WriteToOLED(disTarget,0,OLED_Line3);
}
void Mode()// Changes the "mode" of the house so that different setting of everything in the house.
{
	bool party = GetMode();
	if (party)
	{
		WriteToOLED(" * ! P A R T Y ! * ",0,OLED_Line4);
		if (millis() >= lastParty + lastPartyDelay)
		{
			lastParty = millis();
			analogWrite(LED11,180);
			analogWrite(LED10,180);
			analogWrite(LED9,180);
		}
		else
		{
			analogWrite(LED11,0);
			analogWrite(LED10,0);
			analogWrite(LED9,0);
		}
	}
	else
	{
		WriteToOLED("                   ",0,OLED_Line4);
		analogWrite(LED11,0);
		analogWrite(LED10,0);
		analogWrite(LED9,0);
	}
}
