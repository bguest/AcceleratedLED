#include "Strip.h"

Strip::Strip(){

}

void Strip::init(
    uint8_t dataPin, uint8_t clkPin,
    uint8_t segCount,
    Segment segs[],
    uint8_t segIdxs[])
{

  segments = new Segment*[segmentCount];
  segmentCount = segCount;

  uint8_t stripLength = 0;
  for(uint8_t i=0; i<segmentCount; i++){
    uint8_t idx = segIdxs[i];
    Segment* currSeg = &segs[idx];
    segments[i] = currSeg;
    stripLength += currSeg->length;
  }

  strip = Adafruit_DotStar(stripLength, dataPin, clkPin, DOTSTAR_RGB);
  strip.begin();
  strip.show();
}


void Strip::update(){

  // Set rest of string
  uint8_t i=0;
  for(uint8_t segNum = 0; segNum<segmentCount; segNum++){
    Segment* currSeg = segments[segNum];
    for(uint8_t pixNum = 0; pixNum<currSeg->length; pixNum++){
      Pixel* pixel = currSeg->pixel(pixNum);
      strip.setPixelColor(i, pixel->color() );
      i++;
    }
  }
  strip.show();
}
