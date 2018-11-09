#ifndef RANGE_H
#define RANGE_H

template <class T> class Range {

  public:
    Range();
    void set(T min, T max);
    void update(T newValue);
    T average();
    T min;
    T max;
};

#endif
