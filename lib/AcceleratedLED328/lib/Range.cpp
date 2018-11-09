#ifndef RANGE_CPP
#define RANGE_CPP

#include "Range.h"

template <class T> Range<T>::Range(){
  max = T(0);
  min = T(0);
}

template <class T> void Range<T>::set(T newMin, T newMax){
  max = newMax;
  min = newMin;
}

template <class T> void Range<T>::update(T newValue){
  if(newValue > max){
    max = newValue;
  }
  if(newValue < min){
    min = newValue;
  }
}

template <class T> T Range<T>::average(){
  return max/T(2) + min/T(2);
}

#endif
