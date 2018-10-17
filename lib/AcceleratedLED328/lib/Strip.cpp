#include "Strip.h"

Strip::Strip(){

}

void Strip::init(uint8_t dataPin, uint8_t clkPin){
  strip = Adafruit_WS2801(STRIP_LENGTH, dataPin, clkPin);
  strip.begin();
  strip.show();
}

Pixel* Strip::pixel(uint8_t index){
  return &pixels[index];
}

Pixel* Strip::farPixel(uint8_t index){
  return &pixels[STRIP_LENGTH - index - 1];
}

uint8_t Strip::stripLength(){
  return STRIP_LENGTH;
}

void Strip::setColor(ColorHSV color){
  for(uint8_t i=0; i<this->stripLength(); i++){
    Pixel *pixel = this->pixel(i);
    pixel->hsv = color;
  }
}
void Strip::setBlack(){
  for(uint8_t i=0; i<this->stripLength(); i++){
    Pixel *pixel = this->pixel(i);
    pixel->setBlack();
  }
}

void Strip::update(){

  // Set rest of string
  for(uint8_t idx = 0; idx<STRIP_LENGTH; idx++){
    Pixel* pixel = this->pixel(idx);
    strip.setPixelColor(idx, pixel->color());
  }
  strip.show();
}
