#include "NoEffect.h"

NoEffect::NoEffect(){
}

void NoEffect::run(Sign &sign, Data &data){
  ColorHSV color = ColorHSV(0xFF, 0xFF, 0x00);
  sign.setColor(color);
}




