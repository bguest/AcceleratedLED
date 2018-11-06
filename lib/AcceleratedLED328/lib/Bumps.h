#ifndef BUMPS_H
#define BUMPS_H

#include "Arduino.h"
#include "Effect.h"

class Bumps: public Effect {
  public:
    Bumps();
    void run(Strip &strip, Data &data);

  private:
    uint16_t values[STRIP_LENGTH];
};

#endif
