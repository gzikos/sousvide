#include <TM1637Display.h>
#include "display.h"

const int CLK1 = 4;
const int CLK2 = 5;
const int DIO  = 6;
const int DELAY = 2000;

const float baseline_temp = 24.0;
const float measured_temp = 65.0;

TM1637Display set_display(CLK1,DIO);
TM1637Display get_display(CLK2,DIO);

void setup()
{
  resetDisplay(set_display);
  resetDisplay(get_display);
 }

void loop()
{
  showTemp(set_display,baseline_temp);
  showTemp(get_display,measured_temp);
  delay(DELAY);
}


