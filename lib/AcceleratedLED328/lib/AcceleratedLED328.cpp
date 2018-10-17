#include "AcceleratedLED328.h"


AcceleratedLED328::AcceleratedLED328(){
}

void AcceleratedLED328::init(){
  effects.init();
  blinkers.init();
  accelerometer.init();
}

void AcceleratedLED328::run(){
  accelerometer.run(data);
  blinkers.run(data);
  effects.run(data);
}
