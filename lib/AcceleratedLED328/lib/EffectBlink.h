#ifndef EFFECT_BLINK_H
#define EFFECT_BLINK_H

#include "Arduino.h"
#include "Effect.h"

class EffectBlink: public Effect {
  public:
    EffectBlink();
    void run(Sign &sign, Data &data);

  private:
    ColorHSV color;
    bool isOn;
    uint8_t durration;
    unsigned long lastStep;
    void setSegmentColor(Segment *segment);

};

#endif

