#ifndef Microdelay_h
#define Microdelay_h

#include <Arduino.h>

class Microdelay
{
  public:
    Microdelay();
    static void delay1us();
    static void delay2us();
    static void delay3us();
};

#endif
