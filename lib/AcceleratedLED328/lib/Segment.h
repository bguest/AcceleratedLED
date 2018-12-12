#ifndef SEGMENT_H
#define SEGMENT_H

#include "Pixel.h"
#include "Point.h"

typedef enum {
  left, right
} Side;

class Segment {

  public:
    Segment();
    void init(
        Pixel pixels[],
        uint8_t start,
        uint8_t endPlus1,
        uint16_t endPoints[2][2],
        Side side
        );

    //Get
    Pixel* pixel(uint8_t index);
    Pixel* farPixel(uint8_t index);
    Point pointForIndex(uint8_t index);
    uint8_t index;
    uint8_t length;
    bool isSide(Side side);

    //Set
    void setColor(ColorHSV color);
    void setBlack();

  private:
    Point startPoint;
    Point endPoint;
    Pixel **pixels;
    Side side;
};

#endif
