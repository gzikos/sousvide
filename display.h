#ifndef __DISPLAY__
#define __DISPLAY__

#include  <TM1637Display.h>

void resetDisplay(TM1637Display &display);

void showTemp( TM1637Display &display,float t);

void formatTemp(float t, int &digit_oneT, int &digit_twoT, int &digit_threeT);

void ShowBeef( TM1637Display &display);

void ShowLamb( TM1637Display &display);

void ShowEgg( TM1637Display &display);

void ShowPork( TM1637Display &display);

void ShowFish( TM1637Display &display);

void ShowGreen( TM1637Display &display);

void ShowChicken( TM1637Display &display);

#endif // __DISPLAY__
