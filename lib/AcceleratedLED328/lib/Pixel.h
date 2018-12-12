#ifndef PIXEL_H
#define PIXEL_H

#include "Arduino.h"
#include "ColorHSV.h"
#include "Pixel.h"
#include "Point.h"

class Segment;

class Pixel{
  public:
    Pixel();
    ColorHSV hsv;
    Segment* parent;
    uint8_t index;

    Point point();
    uint32_t color();
    void setFrom(Pixel* pixel);
    void set(uint16_t h, uint8_t s, uint8_t v);
    void setBlack();
    void setValue(uint8_t v);
    void multiplyValue(uint8_t factor);
};

uint32_t ColorFromHSV(ColorHSV hsv);
#endif
