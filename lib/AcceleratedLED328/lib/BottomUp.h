#ifndef BOTTOM_UP
#define BOTTOM_UP
  
#include "Arduino.h"
#include "Effect.h"

class BottomUp: public Effect {
  public:
    BottomUp();
    void run(Sign &sign, Data &data);

  private:
    int16_t maxBrake;

};

#endif
