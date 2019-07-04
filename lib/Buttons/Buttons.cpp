#include <Arduino.h>
#include <Buttons.h>


// Buttons::Buttons(byte scrollUpPin, byte scrollDownPin, byte increaseValuePin, byte decreaseValuePin)
// Buttons::Buttons()
// {
    // _scrollUpPin = scrollUpPin;
    // _scrollDownPin = scrollDownPin;
    // _increaseValuePin = increaseValuePin;
    // _decreaseValuePin = decreaseValuePin;
    // pinMode(_scrollUpPin, INPUT);
    // pinMode(_scrollDownPin, INPUT);
    // pinMode(_increaseValuePin, INPUT);
    // pinMode(_decreaseValuePin, INPUT);
// }

byte const Buttons::_scrollUpPin = 11;
byte const Buttons::_scrollDownPin = 9;
byte const Buttons::_increaseValuePin = 10;
byte const Buttons::_decreaseValuePin = 12;

void Buttons::init()
{
    pinMode(_scrollUpPin, INPUT);
    pinMode(_scrollDownPin, INPUT);
    pinMode(_increaseValuePin, INPUT);
    pinMode(_decreaseValuePin, INPUT);
}

bool Buttons::increaseValue(void)
{
    if (digitalRead(_increaseValuePin) == 0)
    {
        return true;
    }
    else
    {
        return false;
    };
}

bool Buttons::decreaseValue(void)
{
    if (digitalRead(_decreaseValuePin) == 0)
    {
        return true;
    }
    else
    {
        return false;
    };
}

bool Buttons::scrollUp(void)
{
    if (digitalRead(_scrollUpPin) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Buttons::scrollDown(void)
{
    if (digitalRead(_scrollDownPin) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}