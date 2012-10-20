/*
  Library for BMP085 Sensor
*/


#ifndef BMPLib_h				// ensure this library description is only included once
#define BMPLib_h
#define BMP085_ADDRESS 0x77		// I2C address of BMP085

// library interface description
class BMPLib {
  public:
	  //FUNCTIONS WITH VARIABLES USED IN FUNCTIONS AND VARIABLE TYPES

	BMPLib();
    bool begin();		
	short bmp085GetTemperature(unsigned int ut);
	long bmp085GetPressure(unsigned long up);
	char bmp085Read(unsigned char address);
	int bmp085ReadInt(unsigned char address);
	unsigned int bmp085ReadUT();
	unsigned long bmp085ReadUP();


//  private:
    
	unsigned char OSS;  // Oversampling Setting

	// Calibration values
	int ac1;
	int ac2; 
	int ac3; 
	unsigned int ac4;
	unsigned int ac5;
	unsigned int ac6;
	int b1; 
	int b2;
	int mb;
	int mc;
	int md;

	// b5 is calculated in bmp085GetTemperature(...), this variable is also used in bmp085GetPressure(...)
	// so ...Temperature(...) must be called before ...Pressure(...).
	long b5; 



};

#endif

