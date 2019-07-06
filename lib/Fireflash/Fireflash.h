#include <Arduino.h>
#include <Microdelay.h>

class Fireflash
{
    public:
        static void init();
        static void fireFlash(byte flashDuration);
        static void fireFlash1us(void);
        static void fireFlash2us(void);
        static void fireFlash3us(void);
        static void fireFlashFor(byte flashDuration); 
    private:
        static const byte _triggerPin;
};
