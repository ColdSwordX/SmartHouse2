#include "OwnDHT11.h"

extern DHT_Unified dht;

String GetSensorTemp()// Retrieves the temperature from the DT11 sensor.
{
	sensors_event_t event;
	String temprature = "";
	dht.temperature().getEvent(&event);
	if (isnan(event.temperature))
	{
		temprature += -999;
	}
	else
	{
		temprature += String(event.temperature);
	}
	temprature += " C";
	return temprature;
}
String GetSensorHumid()// Retrieves the humidity from the DT11 sensor.
{
	sensors_event_t event;
	String humid = "";
	dht.humidity().getEvent(&event);
	if (isnan(event.temperature))
	{
		humid += -999;
	}
	else
	{
		humid += String(event.relative_humidity);
	}
	humid += " %";
	return humid;
}
