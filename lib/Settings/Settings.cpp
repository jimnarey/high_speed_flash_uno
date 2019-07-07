#include <Arduino.h>
#include <Settings.h>

byte Settings::flashDuration = 10;

bool Settings::notMinDuration(void)
{
    if (Settings::flashDuration > Settings::minFlashDuration)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Settings::notMaxDuration(void)
{
    if (Settings::flashDuration < Settings::maxFlashDuration)
    {
        return true;
    }
    else
    {
        return false;
    }
}


