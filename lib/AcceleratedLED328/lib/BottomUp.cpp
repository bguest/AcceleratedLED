#include "BottomUp.h"

BottomUp::BottomUp(){
  maxBrake = 0;
}

void BottomUp::run(Strip &strip, Data &data){
  int16_t currBrake = max(0, -data.acceleration.y);
  maxBrake = max(maxBrake, -data.acceleration.y);

  uint8_t brakeDots = map(currBrake, 0, maxBrake, 0, STRIP_LENGTH );

#if false
  Serial.print(currBrake); Serial.print(" ");
  Serial.print(maxBrake); Serial.print(" ");
  Serial.print(brakeDots); Serial.print(" ");
  Serial.print("\n");
#endif

  for(uint8_t i=0; i<strip.stripLength(); i++){
    if( i < brakeDots ){
      Pixel* pixel = strip.farPixel(i);
      pixel->set(HUE_RED, 0xFF, 0xFF);
    }
  }

}
