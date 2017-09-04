#ifndef __DS18B20__
#define __DS18B20__

#include <OneWire.h>

//---------------------------------------------------------------
// verify DS18S20 chip used in debug runs of calibration
//--------------------------------------------------------
void verifyChip(OneWire &ds, byte* addr);

//Measure temperature with DS18S20 and auxilary functions
//--------------------------------------------------------

float measure_temperature_with_DS18S20(OneWire &ds);

void searchAddr(OneWire &ds, byte *addr);

void startConversion(OneWire &ds, byte* addr);

void readScratchpad(OneWire &ds, byte* addr);

float findTemp(OneWire &ds);

//---------------------------------------------------------------
// Display reading in serial port for calibration
void displaySerialTemp(const float &t);

#endif // __DS18B20__
