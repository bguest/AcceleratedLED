#include "Accelerometer.h"

/*
 * Connect SCLK, MISO, MOSI, and CSB of ADXL362 to
 * SCLK, MISO, MOSI, and DP 10 of Arduino
 */

Accelerometer::Accelerometer(){
  currIdx = 0;
  for(uint8_t i=0; i<CHANNEL_COUNT; i++ ){
    sums[i]=0;
  }
  lastRun = 0;
}

void Accelerometer::init(){
  accelerometer.begin(10);
  accelerometer.beginMeasure();
  accelerometer.setRange(ADXL362_2G);
  accelerometer.setODR(ADXL362_RATE_400);
}

void Accelerometer::run(Data &data){
  unsigned long currMillis = millis();

  uint8_t updateDurration = 5;
  if(currMillis - lastRun < updateDurration){
    return;
  }

  lastRun = currMillis;

  int16_t newValues[4];

  //accelerometer.readXYZTData(
      //data.acceleration.x,
      //data.acceleration.y,
      //data.acceleration.z,
      //data.temperature);

  accelerometer.readXYZTData(
      newValues[0], // X
      newValues[1], // Y
      newValues[2], // Z
      newValues[3]); // T

  for(uint8_t i=0; i < CHANNEL_COUNT ; i++){
    sums[i] -= measurements[i][currIdx];
    measurements[i][currIdx] = newValues[i];
    sums[i] += measurements[i][currIdx];
  }
  currIdx++;
  currIdx = currIdx % AVERAGE_SIZE;

  data.acceleration.x = sums[0] / AVERAGE_SIZE;
  data.acceleration.y = sums[1] / AVERAGE_SIZE;
  data.acceleration.z = sums[2] / AVERAGE_SIZE;
  data.temperature = sums[3] / AVERAGE_SIZE;


#ifdef PRINT_ACCELEROMETER
  Serial.print(data.acceleration.x); Serial.print(" ");
  Serial.print(data.acceleration.y); Serial.print(" ");
  Serial.print(data.acceleration.z); Serial.print(" ");
  Serial.print(data.temperature); Serial.print(" ");
  Serial.print("\n");
#endif

}
