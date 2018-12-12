#include "Point.h"

Point::Point(){
  x = 0;
  y = 0;
}

Point::Point(uint16_t _x, uint8_t _y){
  x = _x;
  y = _y;
}

Point::Point(uint16_t location[2]){
  x = location[0];
  y = location[1];
}
