/*
File:		BMP_Test
Purpose:	Test program for the Bosch BMP085 Sensor
Author:		Nicholas Braskey - LTRL
Date:		10/19/2012
*/



#define F_CPU 16000000
#define ARDUINO 100
#include "Arduino.h"
#include "Wire.cpp"
#include "BMPLib.cpp"

BMPLib bmp;		// Create instance of BMPLib

/////////////////////////////////////////////////
/////////////////// VARIABLES ///////////////////
/////////////////////////////////////////////////

short temperature;
long pressure;

//////////////////////////////////////////////////
////////////////////// MAIN //////////////////////
//////////////////////////////////////////////////

void setup();
void loop();


/////////////////////////////////////////////////
/////////////////// FUNCTIONS ///////////////////
/////////////////////////////////////////////////

void setup() {
	Serial.begin(9600);
	Wire.begin();
	bmp.begin();
	if (!bmp.begin()) {Serial.println("Could not find a valid BMP085 sensor");}
}

void loop() {
	temperature = bmp.bmp085GetTemperature(bmp.bmp085ReadUT());
	pressure = bmp.bmp085GetPressure(bmp.bmp085ReadUP());
	Serial.print("Temperature: ");
	Serial.print(temperature, DEC);
	Serial.println(" *0.1 deg C");
	Serial.print("Pressure: ");
	Serial.print(pressure, DEC);
	Serial.println(" Pa");
	Serial.println();
	delay(1000);
}