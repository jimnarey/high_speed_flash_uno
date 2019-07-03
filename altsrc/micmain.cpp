
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

// int soundDetectedPin = 5; // Use Pin 10 as our Input
// int soundDetectedVal = HIGH; // This is where we record our Sound Measurement
// boolean bAlarm = false;

// unsigned long lastSoundDetectTime; // Record the time that we measured a sound


// int soundAlarmTime = 500; // Number of milli seconds to keep the sound alarm high


// void setup ()
// {
//   Serial.begin(9600);
//   pinMode (soundDetectedPin, INPUT) ; // input from the Sound Detection Module
// }
// void loop ()
// {
//   soundDetectedVal = digitalRead (soundDetectedPin) ; // read the sound alarm time
  
//   if (soundDetectedVal == LOW) // If we hear a sound
//   {
  
//     lastSoundDetectTime = millis(); // record the time of the sound alarm
//     // The following is so you don't scroll on the output screen
//     if (!bAlarm){
//       Serial.println("LOUD, LOUD");
//       bAlarm = true;
//     }
//   }
//   else
//   {
//     if( (millis()-lastSoundDetectTime) > soundAlarmTime  &&  bAlarm){
//       Serial.println("quiet");
//       bAlarm = false;
//     }
//   }
// }
