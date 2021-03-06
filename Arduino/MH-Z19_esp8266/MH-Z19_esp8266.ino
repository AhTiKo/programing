#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial mySerial(9,8); // RX,TX
byte cmd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79}; 
unsigned char response[9];

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}
long t = 0;
void loop() {
  mySerial.write(cmd, 9);
  memset(response, 0, 9);
  mySerial.readBytes(response, 9);
  int i; 
  byte crc = 0;
  for (i = 1; i < 8; i++) crc+=response[i];
  crc = 255 - crc;
  crc++;
 
  if ( !(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc) ) {
    Serial.println("CRC error: " + String(crc) + " / "+ String(response[8]));
  } else {
    unsigned int responseHigh = (unsigned int) response[2];
    unsigned int responseLow = (unsigned int) response[3];
    unsigned int ppm = (256*responseHigh) + responseLow;
    Serial.print(String(t)); Serial.print(","); Serial.print(ppm); Serial.println(";");
    
  }
  delay(10000);
  t += 10;

}
