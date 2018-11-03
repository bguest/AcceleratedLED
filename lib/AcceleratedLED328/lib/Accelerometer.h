#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include <ADXL362.h>
#include "Data.h"

//#define PRINT_ACCELEROMETER
const uint8_t AVERAGE_SIZE = 50;
const uint8_t CHANNEL_COUNT = 4; //X,Y,Z,T

class Accelerometer {
  public:
    Accelerometer();
    void init();
    void run(Data &data);

  private:
    unsigned long lastRun;

    ADXL362 accelerometer;
    int16_t measurements[CHANNEL_COUNT][AVERAGE_SIZE];
    int32_t sums[CHANNEL_COUNT];
    uint8_t currIdx;
};

#endif
