#include "Effects.h"
#include "Pixel.h"

Effects::Effects(){
  lastRun = 0;
}

#define L_DATA 6
#define L_CLK 7

#define R_DATA 4
#define R_CLK 5

void Effects::init(){
  leftStrip.init(L_DATA, L_CLK);
  rightStrip.init(R_DATA, R_CLK);

  effect = &solidValue;
}

void Effects::run(Data &data){
  unsigned long currMillis = millis();
  if(currMillis - lastRun > UPDATE_DURRATION){
    lastRun = currMillis;

    this->blinkerOrEffect(leftStrip, data, data.blinker.left);
    this->blinkerOrEffect(rightStrip, data, data.blinker.right);
  }
}

bool Effects::blinkerOrEffect(Strip &strip, Data &data, bool blink){
  if(blink){
    strobe.run(strip, data);
  }else{
      strip.setBlack();
      effect->run(strip, data);
      bumps.run(strip, data);
  }
  strip.update();
}
