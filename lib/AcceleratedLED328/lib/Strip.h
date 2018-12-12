#ifndef STRIP_H
#define STRIP_H

#include "Adafruit_DotStar.h"
#include "Segment.h"

const uint8_t STRIP_LENGTH = 10;

class Strip {
  public:
    //Init;
    Strip();
    void init( uint8_t dataPin, uint8_t clkPin,
        uint8_t segmentCount,
        Segment segments[],
        uint8_t segmentIdxs[] );

    //Update
    void update();

  private:
    Adafruit_DotStar strip;
    uint8_t segmentCount;
    Segment** segments;

};
#endif
