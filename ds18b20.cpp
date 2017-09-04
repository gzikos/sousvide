#include "ds18b20.h"

//---------------------------------------------------------------

// verify DS18S20 chip used in debug runs of calibration
//--------------------------------------------------------
void verifyChip(OneWire &ds, byte* addr)
{
  ds.reset_search();
  if ( !ds.search(addr)) {
      Serial.print("No more addresses.\n");
      ds.reset_search();
      return;
  }

  Serial.print("R=");
  for( byte i = 0; i < 8; i++) {
    Serial.print(addr[i], HEX);
    Serial.print(" ");
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.print("CRC is not valid!\n");
      return;
  }

  if ( addr[0] == 0x10) {
      Serial.print("Device is a DS18S20 family device.\n");
  }
  else if ( addr[0] == 0x28) {
      Serial.print("Device is a DS18B20 family device.\n");
  }
  else {
      Serial.print("Device family is not recognized: 0x");
      Serial.println(addr[0],HEX);
      return;
  }
}

//---------------------------------------------------------------



//Measure temperature with DS18S20 and auxilary functions
//--------------------------------------------------------

float measure_temperature_with_DS18S20(OneWire &ds)
{
  byte addr[8];
  searchAddr(ds, addr);
  startConversion(ds, addr);
  readScratchpad(ds, addr);
  
  return findTemp(ds);
}

void searchAddr(OneWire &ds,byte *addr)
{
  ds.reset_search();
  if ( !ds.search(addr)) {
      Serial.print("No more addresses.\n");
      ds.reset_search();
      return;
  }
}

void startConversion(OneWire &ds, byte* addr)
{
 ds.reset();
 ds.select(addr);
 ds.write(0x44,1);         // start conversion, with parasite power on at the end
}

void readScratchpad(OneWire &ds, byte* addr)
{
  ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad
}

float findTemp(OneWire &ds)
{
  byte i;
  byte data[12];  
  int TReading,SignBit;
  
  for ( i = 0; i < 9; i++) 
  {           // we need 9 bytes
    data[i] = ds.read();
  }
  
  TReading = (data[1] << 8) |  data[0];
  SignBit = TReading & 0x8000;  // test most sig bit
  if (SignBit) // negative
  {
  TReading = (TReading ^ 0xffff) + 1; // 2's comp
  }
  return (float)TReading/16.0; 
}

//---------------------------------------------------------------

void displaySerialTemp(const float &t)
{
  Serial.println(t);
}
