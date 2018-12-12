#ifndef SOLID_VALUE_H
#define SOLID_VALUE_H

#include "Effect.h"

class SolidValue: public Effect {
  public:
    SolidValue();
    void run(Sign &sign, Data &data);

  private:
    int16_t maxBrake;
};

#endif
