#include <Arduino.h>
#include <Fireflash.h>
#include <Microdelay.h>

byte const Fireflash::_triggerPin = 3;

void Fireflash::init()
{
    pinMode(Fireflash::_triggerPin, OUTPUT);
}

void Fireflash::fireFlash(byte flashDuration)
{
    if (flashDuration == 1)
    {
        fireFlash1us();
    }
    else if (flashDuration == 2)
    {
        fireFlash2us();
    }
    else if (flashDuration == 3)
    {
        fireFlash3us();
    }
    else
    {
        fireFlashFor(flashDuration);
    }
}

void Fireflash::fireFlash1us(void)
{
    digitalWrite(Fireflash::_triggerPin, HIGH);
    Microdelay::delay1us();
    digitalWrite(Fireflash::_triggerPin, LOW);
    delay(2000);
}

void Fireflash::fireFlash2us(void)
{
    digitalWrite(Fireflash::_triggerPin, HIGH);
    Microdelay::delay2us();
    digitalWrite(Fireflash::_triggerPin, LOW);
    delay(2000);
}

void Fireflash::fireFlash3us(void)
{
    digitalWrite(Fireflash::_triggerPin, HIGH);
    Microdelay::delay3us();
    digitalWrite(Fireflash::_triggerPin, LOW);
    delay(2000);
}

void Fireflash::fireFlashFor(byte flashDuration)
{
    digitalWrite(Fireflash::_triggerPin, HIGH);
    delayMicroseconds(flashDuration);
    digitalWrite(Fireflash::_triggerPin, LOW);
    delay(2000);
}


