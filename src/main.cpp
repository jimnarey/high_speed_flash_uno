
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

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE); // Just for 0.91”(128*32)
// U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);// for 0.96” and 1.3”

int flashDuration = 100;
int maxFlashDuration = 10000;
int minFlashDuration = 100;
int increment = 100;


int scrollUp = 11;
int scrollDown = 12;
int increaseValuePin = 10;
int decreaseValuePin = 9;
int triggerPin = 3;
int micPin = 13;

// void setup ()
// {
//   Serial.begin(9600);
//   pinMode(scrollUp, INPUT);
//   pinMode(scrollDown, INPUT);
//   pinMode(increaseValuePin, INPUT);
//   pinMode(decreaseValuePin, INPUT);
//   pinMode(micPin, OUTPUT);
//   pinMode(triggerPin, OUTPUT);

//   if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
//     u8g.setColorIndex(255);     // white
//   }
//   else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
//     u8g.setColorIndex(3);         // max intensity
//   }
//   else if ( u8g.getMode() == U8G_MODE_BW ) {
//     u8g.setColorIndex(1);         // pixel on
//   }
//   else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
//     u8g.setHiColorByRGB(255,255,255);
//   }
// }

void writeDisplay(int flashDuration) {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 10);
  u8g.print(flashDuration);
}

bool increaseDuration(void) {
    if(digitalRead(increaseValuePin) == 0) {
        return true;
    } else {
        return false;
    };
}

bool decreaseDuration(void) {
    if(digitalRead(decreaseValuePin) == 0) {
        return true;
    } else {
        return false;
    };
}

bool notMaxDuration(void) {
    if(flashDuration < maxFlashDuration) {
        return true;
    } else {
        return false;
    }
}

bool notMinDuration(void) {
    if(flashDuration > minFlashDuration) {
        return true;
    } else {
        return false;
    }
}

void testFireFlash(int flashDuration) {
    digitalWrite(triggerPin, HIGH);
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // delay(flashDuration);
    digitalWrite(triggerPin, LOW);
    delay(2000);
}

bool scrollUpPressed(void) {
    if(digitalRead(scrollUp) == 0) {
        return true;
    } else {
        return false;
    }
}

bool scrollDownPressed(void) {
    if(digitalRead(scrollUp) == 0) {
        return true;
    } else {
        return false;
    }
}

// void loop ()
// {
//   if(increaseDuration() && notMaxDuration()) {
//       flashDuration += increment;
//   } else if(decreaseDuration() && notMinDuration()) {
//       flashDuration -= increment;
//   }

//   if(scrollUpPressed()) {
//       testFireFlash(flashDuration);
//   }

//     if(scrollDownPressed()) {
//       testFireFlash(flashDuration);
//   }

//   u8g.firstPage();  
//   do {
//     writeDisplay(flashDuration);
//   } while( u8g.nextPage() );

//   delay(50);
// }

void setup()
{
    Serial.begin(9600);
    pinMode(9, INPUT);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
    pinMode(12, INPUT);
}

void loop() 
{
    if(digitalRead(9) == 0) {
        Serial.println('9');
    }

    if(digitalRead(10) == 0) {
        Serial.println('10');
    }
    
    if(digitalRead(11) == 0) {
        Serial.println('11');
    }

    if(digitalRead(12) == 0) {
        Serial.println('12');
    }

    delay(50);
}
