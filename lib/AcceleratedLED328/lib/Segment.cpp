#include "Segment.h"

Segment::Segment(){}

void Segment::init(
    Pixel p[],
    uint8_t start,
    uint8_t endPlus1,
    uint16_t endPoints[2][2],
    Side _side
    )
{
  length = endPlus1 - start;
  pixels = new Pixel*[length];

  uint8_t j = 0;
  for(uint8_t i=start; i< endPlus1; i++){
    pixels[j] = &p[i];
    pixels[j]->index = j;
    pixels[j]->parent = this;
    j++;
  }

  startPoint = Point(endPoints[0]);
  endPoint = Point(endPoints[1]);

  side = _side;
}

Point Segment::pointForIndex(uint8_t _index){
  uint16_t xA = startPoint.x;
  uint16_t xB = endPoint.x;
  uint16_t x = map(_index, 0, length, xA, xB);

  uint16_t yA = startPoint.y;
  uint16_t yB = endPoint.y;
  uint16_t y = map(_index, 0, length, yA, yB);

  return Point(x, y);
}

Pixel* Segment::pixel(uint8_t index){
  return pixels[index];
}

Pixel* Segment::farPixel(uint8_t index){
  return pixels[length - index - 1];
}

bool Segment::isSide(Side _side){
  _side == side;
}

void Segment::setColor(ColorHSV color){
  for(uint8_t i=0; i<length; i++){
    Pixel *pixel = this->pixel(i);
    pixel->hsv = color;
  }
}
void Segment::setBlack(){
  for(uint8_t i=0; i<length; i++){
    Pixel *pixel = this->pixel(i);
    pixel->setBlack();
  }
}
