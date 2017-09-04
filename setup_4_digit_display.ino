#include <TM1637Display.h>
#include "display.h"

const int CLK = 4;
const int DIO  = 6;
const int DELAY = 2000;

const float baseline_temp = 24.0;

TM1637Display set_display(CLK,DIO);

void setup()
{
  resetDisplay(set_display);
 }

void loop()
{
  showTemp(set_display,baseline_temp);
  delay(DELAY);
}


