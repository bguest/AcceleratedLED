#ifndef POINT_H
#define POINT_H

#include "Arduino.h"

class Point{

  public:
    Point();
    Point(uint16_t x, uint8_t y);
    Point(uint16_t location[2]);
    uint16_t x;
    uint16_t y;

};

#endif
