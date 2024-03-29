
/*
    Arduino Nano

                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |       GND/RST2  [ ][ ]              |
         |     MOSI2/SCK2  [ ][ ] [C]A5/SCL[ ] |   C5 
         |        5V/MISO2 [ ][ ] [C]A4/SDA[ ] |   C4 
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                 [B]SCK/13[ ] |   B5
         | [ ]IOREF              [B]MISO/12[ ] |   .
         | [ ]RST                [B]MOSI/11[ ]~|   .
         | [ ]3V3    +---+            [B]10[ ]~|   .
         | [ ]5v    -| A |-            [B]9[ ]~|   .
         | [ ]GND   -| R |-            [B]8[ ] |   B0
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-            [D]7[ ] |   D7
         |          -| I |-            [D]6[ ]~|   .
         | [ ]A0[C] -| N |-            [D]5[ ]~|   .
         | [ ]A1[C] -| O |-            [D]4[ ] |   .
         | [ ]A2[C]  +---+        [D]INT1/3[ ]~|   .
         | [ ]A3[C]               [D]INT0/2[ ] |   .
         | [ ]A4/SDA[C]             [D]TX>1[ ] |   .
         | [ ]A5/SCL[C]             [D]RX<0[ ] |   D0
         |          [Rs] [Sc] [Mi]             |
         |  UNO_R3  [G]  [Mo] [5v] ____________/
          \_______________________/
		  
		  http://busyducks.com/ascii-art-arduinos

*/

#include <Arduino.h>
#include <U8glib.h>
#include <Buttons.h>
#include <Fireflash.h>
#include <Display.h>


byte flashDuration = 10;
const byte maxFlashDuration = 100;
const byte minFlashDuration = 1;
const byte durationIncrement = 1;
const byte micPin = 13;

void setup()
{
    Serial.begin(9600);
    Buttons::init();
    Fireflash::init();
    pinMode(micPin, OUTPUT);
    Display::init();
}

bool notMaxDuration(void)
{
    if (flashDuration < maxFlashDuration)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool notMinDuration(void)
{
    if (flashDuration > minFlashDuration)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void loop()
{
    if (Buttons::increaseValue() && notMaxDuration())
    {
        flashDuration += durationIncrement;
    }
    else if (Buttons::decreaseValue() && notMinDuration())
    {
        flashDuration -= durationIncrement;
    }

    if (Buttons::scrollUp())
    {
        Fireflash::fireFlash(flashDuration);
    }

    if (Buttons::scrollDown())
    {
        Fireflash::fireFlash(flashDuration);
    }

    Display::refreshDisplay(flashDuration);

    delayMicroseconds(50000);
}

