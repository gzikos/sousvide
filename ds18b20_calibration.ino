
//Arduino libraries
#include <TM1637Display.h>
#include <OneWire.h>

//custom libraries
#include "display.h"
#include "ds18b20.h"

// DS18B20 Temperature chip i/o
const int CLK1 = 4;
const int DIO  = 6;
const int THER = 9;
const int DELAY = 2000;

//initialize globals
//display for quick checks
TM1637Display get_display(CLK1,DIO);
const float measured_temp = 65.0;

//thermometer one wire 
OneWire ds(THER);  // on pin9
const boolean verify_chip = false; 


void setup()
{
  Serial.begin(9600);
  resetDisplay(get_display); 
 }

void loop()
{
  if (verify_chip)
  {
    byte ver_addr[8];
    verifyChip(ds, ver_addr);
  }
  float t = measure_temperature_with_DS18S20(ds);
  showTemp(get_display, t);
  displaySerialTemp(t);
  delay(DELAY);
}




