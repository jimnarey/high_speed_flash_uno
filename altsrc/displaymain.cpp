
// /*
//     Arduino Nano

//                                       +-----+
//          +----[PWR]-------------------| USB |--+
//          |                            +-----+  |
//          |         GND/RST2  [ ][ ]            |
//          |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5 
//          |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4 
//          |                             AREF[ ] |
//          |                              GND[ ] |
//          | [ ]N/C                    SCK/13[ ] |   B5
//          | [ ]IOREF                 MISO/12[ ] |   .
//          | [ ]RST                   MOSI/11[ ]~|   .
//          | [ ]3V3    +---+               10[ ]~|   .
//          | [ ]5v    -| A |-               9[ ]~|   .
//          | [ ]GND   -| R |-               8[ ] |   B0
//          | [ ]GND   -| D |-                    |
//          | [ ]Vin   -| U |-               7[ ] |   D7
//          |          -| I |-               6[ ]~|   .
//          | [ ]A0    -| N |-               5[ ]~|   .
//          | [ ]A1    -| O |-               4[ ] |   .
//          | [ ]A2     +---+           INT1/3[ ]~|   .
//          | [ ]A3                     INT0/2[ ] |   .
//          | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
//          | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0
//          |            [ ] [ ] [ ]              |
//          |  UNO_R3    GND MOSI 5V  ____________/
//           \_______________________/
		  
// 		  http://busyducks.com/ascii-art-arduinos

// */

// #include <Arduino.h>
// #include <U8glib.h>

// U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE); // Just for 0.91”(128*32)
// //U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);// for 0.96” and 1.3”

// void writeDisplay(int flashDuration) {
//   u8g.setFont(u8g_font_unifont);
//   u8g.setPrintPos(0, 10);
//   u8g.print(flashDuration);
// }

// void setup(void) {
//   // flip screen, if required
//   // u8g.setRot180();
  

//   // assign default color value
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

// void loop(void) {
//   // picture loop
  // u8g.firstPage();  
  // do {
  //   writeDisplay(flashDuration);
  // } while( u8g.nextPage() );

//   // rebuild the picture after some delay
//   delay(1000);
// }