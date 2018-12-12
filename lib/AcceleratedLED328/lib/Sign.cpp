#include "Sign.h"

Sign::Sign(){}

void Sign::init(){

  /**
   * Setup Segments
   */
  uint16_t xyLocations[SEGMENT_COUNT][2][2] = {
    {{0,0}, {0,1}},
    {{0,1}, {1,1}}
  };

  Side sides[SEGMENT_COUNT] = {
    left, right
  };

  uint8_t start = 0;
  uint8_t endPlus1;

  for(uint8_t i=0; i<SEGMENT_COUNT; i++){
    endPlus1 = start + SEGMENT_LENGTH[i];
    segments[i].init(pixels, start, endPlus1, xyLocations[i], sides[i]);
    segments[i].index = i;
    start = endPlus1;
  }

  /**
   * Setup Strips
   */
  uint8_t dataClkPins[STRIP_COUNT][2]={
    {6,7},
    {4,5}
  };

  uint8_t stripSegmentCounts[STRIP_COUNT] = {
    1,
    1
  };

  uint8_t stripSegmentIdxs[STRIP_COUNT][1] = {
    {0},
    {1}
  };
  
  for(uint8_t i=0; i<STRIP_COUNT; i++){
    uint8_t dataPin = dataClkPins[i][0];
    uint8_t clkPin = dataClkPins[i][1];

    strips[i].init( dataPin, clkPin,
        stripSegmentCounts[i],
        segments,
        stripSegmentIdxs[i]);
  }

}

Segment* Sign::segment(uint8_t index){
  return &segments[index];
}

void Sign::setColor(ColorHSV color){
  for(uint8_t i=0; i<SEGMENT_COUNT; i++){
    Segment *segment = this->segment(i);
    segment->setColor( color );
  }
}

void Sign::update(){
  for(uint8_t i=0; i<STRIP_COUNT; i++){
    strips[i].update();
  }
}

