

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

// #include <Arduino.h>

// void setup()
// {
//     Serial.begin(9600);
//     pinMode(9, INPUT);
//     pinMode(10, INPUT);
//     pinMode(11, INPUT);
//     pinMode(12, INPUT);
// }

// void loop() 
// {
//     if(digitalRead(9) == 0) {
//         Serial.println(9);
//     }

//     if(digitalRead(10) == 0) {
//         Serial.println(10);
//     }
    
//     if(digitalRead(11) == 0) {
//         Serial.println(11);
//     }

//     if(digitalRead(12) == 0) {
//         Serial.println(12);
//     }

//     delay(50);
// }