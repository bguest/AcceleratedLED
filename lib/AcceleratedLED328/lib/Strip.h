#ifndef STRIP_H
#define STRIP_H

#include "Adafruit_DotStar.h"
#include "Pixel.h"

const uint8_t STRIP_LENGTH = 10;

class Strip {
  public:
    //Init;
    Strip();
    void init(uint8_t dataPin, uint8_t clkPin);

    //Get
    Pixel* pixel(uint8_t index);
    Pixel* farPixel(uint8_t index);
    uint8_t stripLength();

    //Set
    void setColor(ColorHSV color);
    void setBlack();

    //Update
    void update();

  private:
    Adafruit_DotStar strip;
    Pixel pixels[STRIP_LENGTH];

};
#endif
