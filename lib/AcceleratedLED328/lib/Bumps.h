#ifndef BUMPS_H
#define BUMPS_H

#include "Arduino.h"
#include "Effect.h"
#include "Range.h"

class Bumps: public Effect {
  public:
    Bumps();
    void run(Sign &sign, Data &data);

  private:
    Range<int16_t> maxValue;
    Range<int16_t> currValue;

    unsigned long lastStep;

    void pushValue(uint16_t value);
    //uint16_t values[STRIP_LENGTH];
};

#endif
