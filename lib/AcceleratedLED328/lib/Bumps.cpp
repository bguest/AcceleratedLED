#include "Bumps.h"
#include "Range.cpp"

Bumps::Bumps(){
  /*
  for(uint8_t i=0; i<STRIP_LENGTH; i++){
    values[i] = 0;
  }
  currValue.set(INT16_MAX, INT16_MIN);
  maxValue.set(INT16_MAX, INT16_MIN);
  */
}

void Bumps::run(Sign &sign, Data &data){
  /*
  unsigned long currMillis = millis();
  unsigned long STEP_TIME = 40;

  currValue.update(data.acceleration.x);
  maxValue.update(data.acceleration.x);

  if(currMillis - lastStep > STEP_TIME){
    lastStep = currMillis;

    //int16_t maxAdd = 600;
    //uint16_t value = map(currValue.average(), maxValue.min, maxValue.max, -maxAdd, maxAdd );
    uint16_t maxMultiply = 30000;
    uint16_t value = map(currValue.average(), maxValue.min, maxValue.max, 1, maxMultiply );

    currValue.set(INT16_MAX, INT16_MIN);

    this -> pushValue(value);
  }

  for(uint8_t i=0; i< strip.stripLength(); i++){
    Pixel* pixel = strip.farPixel(i);
    //pixel->hsv.hue += values[i];
    pixel->multiplyValue( values[i] >> 8 );
  }
  */

}

void Bumps::pushValue(uint16_t value){
  /*
  for(int8_t i= STRIP_LENGTH-2; i>=0; i--){
    values[i+1] = values[i];
  }
  values[0] = value;
  */
}
