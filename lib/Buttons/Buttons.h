#include <Arduino.h>

class Buttons
{
    public:
        static void init();
        static bool scrollUp(void);
        static bool scrollDown(void);
        static bool increaseValue(void);
        static bool decreaseValue(void);
    private:
        static const byte _scrollUpPin;
        static const byte _scrollDownPin;
        static const byte _increaseValuePin;
        static const byte _decreaseValuePin;
};
