#include "SolidValue.h"

SolidValue::SolidValue(){
  maxBrake = 0;
}

void SolidValue::run(Strip &strip, Data &data){
  int16_t currBrake = max(0, -data.acceleration.y);
  maxBrake = max(maxBrake, -data.acceleration.y);

  uint8_t brakeValue = map(currBrake, 0, maxBrake, 0xFF/4, 0xFF);

  strip.setColor(ColorHSV(HUE_RED, 0xFF, brakeValue));
}



