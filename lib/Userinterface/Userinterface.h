#ifndef Userinterface_h
#define Userinterface_h

#include <Arduino.h>

class Screen
{
  public:
    Screen();
};

class Buttons
{
    public:
        Buttons(byte scrollUpPin, byte scrollDownPin, byte increaseValuePin, byte decreaseValuePin);
        void init();
        bool scrollUp(void);
        bool scrollDown(void);
        bool increaseValue(void);
        bool decreaseValue(void);
    private:
        byte _scrollUpPin;
        byte _scrollDownPin;
        byte _increaseValuePin;
        byte _decreaseValuePin;
};

class Userinterface
{
  public:
    Userinterface();
};

#endif