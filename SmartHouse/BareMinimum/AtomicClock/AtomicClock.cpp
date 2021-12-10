
#include "AtomicClock.h"

extern RTClib myClock;

DateTime ReadClock()// Clock reader
{
	return myClock.now();
}
String GetTimeString(DateTime dt)// Retrieves the time from the atomic clock.
{
	String tempTimeString = "";
	if (dt.hour() < 9)
	{
		tempTimeString += 0;
	}
	tempTimeString += dt.hour() - 1;
	tempTimeString += ":";
	if (dt.minute() < 9)
	{
		tempTimeString += 0;
	}
	tempTimeString += dt.minute();
	tempTimeString += ":";
	if (dt.second() < 9)
	{
		tempTimeString += 0;
	}
	tempTimeString += dt.second();
	return tempTimeString;
}
String GetDataString(DateTime dt)// Retrieves the date from the atomic clock.
{
	String tempDataString = "";
	if (dt.day() < 9)
	{
		tempDataString += 0;
	}
	tempDataString += dt.day();
	tempDataString += "-";
	if (dt.month() < 9)
	{
		tempDataString += 0;
	}
	tempDataString += dt.month();
	tempDataString += "-";
	if (dt.year() < 9)
	{
		tempDataString += 0;
	}
	tempDataString += dt.year();
	return tempDataString;
}
