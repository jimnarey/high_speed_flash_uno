#include <Arduino.h>

class Settings
{
    public:
        // Flash duration settings 
        static byte flashDuration;
        static const byte maxFlashDuration = 100;
        static const byte minFlashDuration = 1;
        static const byte durationIncrement = 1;
        
    private:
};