#ifndef EFFECTS_H
#define EFFECTS_H

#include "Effect.h"
#include "EffectBlink.h"

#include "NoEffect.h"
//#include "BottomUp.h"
#include "Strobe.h"
#include "Bumps.h"
#include "SolidValue.h"
#include "Sign.h"

const uint8_t UPDATE_DURRATION = 15;

class Effects{
  public:
    Effects();
    void init();
    void run(Data &data);

  private:
    unsigned long lastRun;

    Sign sign;
    Strip leftStrip;
    Strip rightStrip;

    EffectBlink blinkEffect;

    Effect* effect;
        
    //NoEffect noEffect;
    //BottomUp bottomUp;
    SolidValue solidValue;
    Strobe strobe;
    Bumps bumps;

};
#endif
