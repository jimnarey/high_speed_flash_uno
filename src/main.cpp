
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
#include <Microdelay.h>
#include <Buttons.h>

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE); // Just for 0.91”(128*32)
// U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);// for 0.96” and 1.3”

byte flashDuration = 10;
const byte maxFlashDuration = 100;
const byte minFlashDuration = 1;
const byte durationIncrement = 1;
const byte triggerPin = 3;
const byte micPin = 13;

void setup()
{
    Serial.begin(9600);
    Buttons::init();
    pinMode(micPin, OUTPUT);
    pinMode(triggerPin, OUTPUT);

    if (u8g.getMode() == U8G_MODE_R3G3B2)
    {
        u8g.setColorIndex(255); // white
    }
    else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
    {
        u8g.setColorIndex(3); // max intensity
    }
    else if (u8g.getMode() == U8G_MODE_BW)
    {
        u8g.setColorIndex(1); // pixel on
    }
    else if (u8g.getMode() == U8G_MODE_HICOLOR)
    {
        u8g.setHiColorByRGB(255, 255, 255);
    }
}

// Display

void writeDisplay(byte flashDuration)
{
    u8g.setFont(u8g_font_unifont);
    u8g.setPrintPos(0, 10);
    u8g.print(flashDuration);
}

// Validate duration input

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

// Fire Flash

void fireFlash1us()
{
    digitalWrite(triggerPin, HIGH);
    Microdelay::delay1us();
    digitalWrite(triggerPin, LOW);
    delay(2000);
}

void fireFlash2us()
{
    digitalWrite(triggerPin, HIGH);
    Microdelay::delay2us();
    digitalWrite(triggerPin, LOW);
    delay(2000);
}

void fireFlash3us()
{
    digitalWrite(triggerPin, HIGH);
    Microdelay::delay3us();
    digitalWrite(triggerPin, LOW);
    delay(2000);
}

void fireFlashFor(byte flashDuration)
{
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(flashDuration);
    digitalWrite(triggerPin, LOW);
    delay(2000);
}

void fireFlash(byte flashDuration)
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
        fireFlash(flashDuration);
    }

    if (Buttons::scrollDown())
    {
        fireFlash(flashDuration);
    }

    u8g.firstPage();
    do
    {
        writeDisplay(flashDuration);
    } 
    while (u8g.nextPage());

    delayMicroseconds(50000);
}

