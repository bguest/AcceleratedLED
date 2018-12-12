
#include "EffectBlink.h"


EffectBlink::EffectBlink(){
  durration = 500;
  isOn = false;
}

void EffectBlink::run(Sign &sign, Data &data){
  unsigned long currMillis = millis();
  if( currMillis - lastStep < durration ) { return; }
  lastStep = currMillis;

  isOn = !isOn;

  Side blinkerSide;
  if(data.blinker.right){
    blinkerSide = right;
  }else if(data.blinker.right){
    blinkerSide = left;
  }else{
  }

  for(uint8_t i=0; i<SEGMENT_COUNT; i++){
    Segment *segment = sign.segment(i);
    if(segment->isSide(blinkerSide)){
      this->setSegmentColor(segment);
    }
  }
}

void EffectBlink::setSegmentColor(Segment *segment){
  ColorHSV color;
  if(isOn){
    color = ColorHSV(HUE_ORANGE, 0xFF, 0xFF);
  }else{
    color = ColorHSV(0xFF, 0xFF, 0x00);
  }
  segment -> setColor(color);

}
