/*
 * OwnDHT11.h
 *
 * Created: 09-12-2021 08:48:22
 *  Author: JensN
 */ 

#ifndef OWNDHT11_H_
#define OWNDHT11_H_

#include <DHT.h>					// DHT 11 library.
#include <DHT_U.h>					// DHT 11 library.
#include <SPI.h>					// SPI library. (SERIAL PERIPHERAL INTERFACE)

//DHT11 sensor
#define DHTPIN 42
#define DHTTYPE DHT11


String GetSensorTemp();			// Retrieves the temperature from the DT11 sensor.
String GetSensorHumid();		// Retrieves the humidity from the DT11 sensor.



#endif /* OWNDHT11_H_ */