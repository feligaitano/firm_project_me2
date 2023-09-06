#include<SPI.h>
#include <MD_AD9833_lib.h>
#include <DDS.h>
//DATA PIN:11, CLOCK PIN:13, FSYNC PIN:10
#define FSYNC 10

#define WAVE_SINE     0x2000


long int frequency = 1000; 
long int frequency_ant = 0;
long int function = 0;
long int function_ant = 0;

void AD9833setup(){
   pinMode(FSYNC, OUTPUT);
   digitalWrite(FSYNC, HIGH);
   SPI.begin();
   delay(50); 
   AD9833reset();
   WriteRegister(B00100000);
}

void AD9833reset(){
   WriteRegister(0x100);
   delay(10);
}

void AD9833setFrequency(long frequency, int Waveform){
   long FreqWord = (frequency * pow(2, 28)) / 25.0E6;
   int MSB = (int)((FreqWord & 0xFFFC000) >> 14);
   int LSB = (int)(FreqWord & 0x3FFF);
   LSB |= 0x4000;
   MSB |= 0x4000; 
   WriteRegister(0x2100);   
   WriteRegister(LSB);
   WriteRegister(MSB);
   WriteRegister(0xC000);
   WriteRegister(Waveform);
}

void WriteRegister(int dat){ 
   SPI.setDataMode(SPI_MODE2);        
   digitalWrite(FSYNC, LOW);
   delayMicroseconds(10); 
   SPI.transfer(dat>>8);
   SPI.transfer(dat&0xFF);
   digitalWrite(FSYNC, HIGH);
   SPI.setDataMode(SPI_MODE0);
}

void setup(){
   Serial.begin(9600);
   AD9833setup();
   actualiza_func();
}

void actualiza_func(){
 
   function = WAVE_SINE;


   if(frequency_ant != frequency ){
      AD9833setFrequency(frequency, function);
   }
   frequency_ant = frequency;
   function_ant = function;
}
void loop(){ 

}