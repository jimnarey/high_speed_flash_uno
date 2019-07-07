#include <Arduino.h>

class Settings
{
    public:
        // Flash duration 
        static byte flashDuration;
        static const byte maxFlashDuration = 100;
        static const byte minFlashDuration = 1;
        static const byte durationIncrement = 1;
        
        static bool notMinDuration(void);
        static bool notMaxDuration(void);

    private:
};