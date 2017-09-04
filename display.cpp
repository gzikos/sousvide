#include "display.h"

void resetDisplay(TM1637Display &display)
{
  display.setBrightness(0xF);
  uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
  display.setSegments(data);
}

void showTemp( TM1637Display &display,float t)
{
  const uint8_t Letter_C[] = { SEG_A | SEG_F | SEG_E | SEG_D }; // C
  const bool leading_zero = false;
  uint8_t segto;
  int digit_oneT = 0 ,digit_twoT =0 ,digit_threeT = 0;
  
  formatTemp(t, digit_oneT, digit_twoT, digit_threeT);
  
  if (0 != digit_oneT )
  {  
    display.showNumberDec(digit_oneT,leading_zero,1,0);
  }
  else
  {
    display.setSegments(Letter_C,1,3);
  }
  //turn on semicolon 
  segto = 0x80 | display.encodeDigit(digit_twoT);
  display.setSegments(&segto, 1, 1);
  display.showNumberDec(digit_threeT,leading_zero,1,2);
  display.setSegments(Letter_C,1,3);
}

void formatTemp(float t, int &digit_oneT, int &digit_twoT, int &digit_threeT)
{     
  if (t >= 100.0)
  {
     t -=100.0;
  }
  t = 0.005 + t/10.;
  digit_oneT  = (int)t;
  t = (t - digit_oneT)*10.;
  digit_twoT  = (int)t;
  t = (t - digit_twoT)*10;
  digit_threeT = (int)t;
}

//------------------------------------------------------------------------------------------
//  
void ShowBeef( TM1637Display &display)
{
  const uint8_t Letter_B[] = { SEG_F | SEG_E | SEG_D |SEG_G | SEG_C}; // b
  const uint8_t Letter_E[] = { SEG_A | SEG_F | SEG_G |SEG_E | SEG_D}; // E
  const uint8_t Letter_F[] = { SEG_A | SEG_F | SEG_G |SEG_E }; // F
  display.setSegments(Letter_B,1,0);
  display.setSegments(Letter_E,1,1);
  display.setSegments(Letter_E,1,2);
  display.setSegments(Letter_F,1,3);
}

void ShowLamb( TM1637Display &display)
{
  //CHCn
  const uint8_t Letter_L[] = { SEG_F | SEG_E | SEG_D  }; // L
  const uint8_t Letter_A[] = { SEG_F | SEG_E | SEG_A | SEG_G | SEG_C | SEG_B}; // A
  const uint8_t Letter_M[] = { SEG_G | SEG_E | SEG_C };//N
  const uint8_t Letter_B[] = { SEG_F | SEG_E | SEG_D |SEG_G | SEG_C};//b
  
  display.setSegments(Letter_L,1,0);
  display.setSegments(Letter_A,1,1);
  display.setSegments(Letter_M,1,2);
  display.setSegments(Letter_B,1,3);
}

void ShowEgg( TM1637Display &display)
{
  const uint8_t Letter_E[] = { SEG_A | SEG_F | SEG_G |SEG_E | SEG_D}; // E
  const uint8_t Letter_G[] = { SEG_A | SEG_F | SEG_G | SEG_E | SEG_D | SEG_C }; // G 
  const uint8_t Empty[]={};

  display.setSegments(Empty,1,0);
  display.setSegments(Letter_E,1,1);
  display.setSegments(Letter_G,1,2);
  display.setSegments(Letter_G,1,3);
}

void ShowPork( TM1637Display &display)
{
  const uint8_t Letter_P[] = { SEG_A | SEG_F | SEG_B |SEG_G | SEG_E }; // P 
  const uint8_t Letter_O[] = { SEG_E  |SEG_G | SEG_C | SEG_D}; // O
  const uint8_t Letter_R[] = { SEG_E | SEG_G }; // r
  const uint8_t Letter_K[] = { SEG_F | SEG_E | SEG_G | SEG_C}; // k
  display.setSegments(Letter_P,1,0);
  display.setSegments(Letter_O,1,1);
  display.setSegments(Letter_R,1,2);
  display.setSegments(Letter_K,1,3);
}

void ShowFish( TM1637Display &display)
{
  const uint8_t Letter_F[] = { SEG_A | SEG_F | SEG_G | SEG_E }; // F 
  const uint8_t Letter_I[] = { SEG_B | SEG_C }; // I
  const uint8_t Letter_S[] = { SEG_A | SEG_F | SEG_G | SEG_C | SEG_D}; // S
  const uint8_t Letter_H[] = { SEG_F | SEG_E | SEG_G | SEG_C | SEG_B}; // H
  display.setSegments(Letter_F,1,0);
  display.setSegments(Letter_I,1,1);
  display.setSegments(Letter_S,1,2);
  display.setSegments(Letter_H,1,3);
}

void ShowGreen( TM1637Display &display)
{
  const uint8_t Letter_G[] = { SEG_A | SEG_F | SEG_G | SEG_E | SEG_D | SEG_C }; // G 
  const uint8_t Letter_R[] = { SEG_E | SEG_G }; // r
  const uint8_t Letter_E[] = { SEG_A | SEG_F | SEG_G |SEG_E | SEG_D};//E
  
  display.setSegments(Letter_G,1,0);
  display.setSegments(Letter_R,1,1);
  display.setSegments(Letter_E,1,2);
  display.setSegments(Letter_E,1,3);
}

void ShowChicken( TM1637Display &display)
{
  //CHC
  const uint8_t Letter_C[] = { SEG_A | SEG_F | SEG_E | SEG_D  }; // C
  const uint8_t Letter_H[] = { SEG_F | SEG_E | SEG_G | SEG_C | SEG_B}; // H
  const uint8_t Empty[]={};

  display.setSegments(Empty,1,0);
  display.setSegments(Letter_C,1,1);
  display.setSegments(Letter_H,1,2);
  display.setSegments(Letter_C,1,3);
}

