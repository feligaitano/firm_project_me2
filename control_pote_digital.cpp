#include <SPI.h>
#define CS_PIN 10
#define ADC_PIN A0
const byte address = 0x11;
void MCP41010_Set(int value){
   digitalWrite(CS_PIN, LOW);
   SPI.transfer(address);
   SPI.transfer(value);
   digitalWrite(CS_PIN, HIGH);
}
void setup(){
   pinMode(CS_PIN, OUTPUT);
   SPI.begin();
}
void loop(){
   MCP41010_Set(map(analogRead(A0),0,1023,0,255));
   delay(100);
}