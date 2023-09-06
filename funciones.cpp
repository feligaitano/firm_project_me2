#include <Arduino.h>
void ccif(int frec1, int frec2, float ampli);
void smpte(int frec1, int frec2, float ampli);
void sweep(int frec1, int frec2, float ampli, int salto, int tiempo);



void setup() {
int f,tono1,tono2,tiempo,salto;
float amplitud;
Serial.begin(9600);
}

void loop() {

switch (f)
{
case 1:
ccif(tono1, tono2,amplitud);
    break;
case 2:
smpte(tono1, tono2,amplitud);
    break;
case 3:
sweep(tono1, tono2,amplitud,salto,tiempo);
    break;

}



void ccif(int frec1, int frec2, float ampli);
{
    for (int i = 0; i < DigitalOutputs; i++) {
    digitalWrite(digitalOutputs[i], LOW);
  }
    digitalWrite(frec1, HIGH);
    digitalWrite(frec2 HIGH);
}
void smpte(int frec1, int frec2, float ampli);
{
    for (int i = 0; i < DigitalOutputs; i++) {
    digitalWrite(digitalOutputs[i], LOW);
  }
    digitalWrite(frec1, HIGH);
    digitalWrite(frec2 HIGH);
    while (f=2)
    {
        /* */
    }
    
}
void sweep(int frec1, int frec2, float ampli, int salto, int tiempo);
{
    for (int i = 0; i < DigitalOutputs; i++) {
    digitalWrite(digitalOutputs[i], LOW);
  }

}