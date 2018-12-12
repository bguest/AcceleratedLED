#ifndef SIGN_H
#define SIGN_H

#include "Pixel.h"
#include "Segment.h"
#include "Strip.h"

/**
 * Represents
 */

#define SEGMENT_COUNT 2
#define SEG_0_CNT 10
#define SEG_1_CNT 10

#define STRIP_COUNT 2

const uint8_t SEGMENT_LENGTH[SEGMENT_COUNT] = {
  SEG_0_CNT,
  SEG_1_CNT
};

class Sign{

  public:
    Sign();
    void init();
    void update();

    //Get
    Segment* segment(uint8_t index);

    //Set
    void setColor(ColorHSV color);


  private:
    Pixel pixels[
      SEG_0_CNT +
      SEG_1_CNT
    ];

    Segment segments[SEGMENT_COUNT];
    Strip strips[STRIP_COUNT];
};

#endif
