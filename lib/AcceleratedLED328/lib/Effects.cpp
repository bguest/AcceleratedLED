#include "Effects.h"
#include "Pixel.h"

Effects::Effects(){
  lastRun = 0;
}

void Effects::init(){
  sign.init();

  effect = &solidValue;
}

void Effects::run(Data &data){
  unsigned long currMillis = millis();

  if(currMillis - lastRun < UPDATE_DURRATION){ return; }
  lastRun = currMillis;

  if(data.blinker.right || data.blinker.right){
    blinkEffect.run(sign, data);
  }
}

