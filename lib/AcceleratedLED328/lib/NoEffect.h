#ifndef NO_EFFECT_H
#define NO_EFFECT_H

#include "Arduino.h"
#include "Effect.h"

class NoEffect: public Effect {
  public:
    NoEffect();
    void run(Sign &sign, Data &data);

  private:

};
#endif
