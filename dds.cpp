#include <MD_AD9833.h>
#include <SPI.h>

#define DATA  11      // SPI Data/MOSI pin number.  Meg 2560 uses pin 51
#define CLK   13      // SPI Clock pin number.  Mega 2560 uses pin 52
#define FSYNC 10      // SPI Load/SS pin number.  Mega 2560 uses pin 53

MD_AD9833 AD(FSYNC);  // Hardware SPI
MD_AD9833::mode_t mode;

#define PinTip42C  A0

uint32_t freq_Value1 = 0;  // Frequency value to set
uint32_t freq_Value2 = 0;  // Frequency value2 to set
uint32_t salto = 0;       //salto minimo es de 0,046hz
void SetearModo(void);
void ModoOFF(void);
void SetearFrecuencia(void);

void setup(void)
{
  Serial.begin(9600);   
  
  pinMode(PinTip42C, OUTPUT);
  digitalWrite(PinTip42C, HIGH);   
  
  Serial.println("Iniciando...");
  
  AD.begin();
  SetearModo();
               
   SetearFrecuencia(); 
      
//  ModoOFF();
}

void loop(void)
{
  if(Serial.read())
  {
    freq_Value1 = Serial.parseInt();
    freq_Value2 = Serial.parseInt();
    salto= ;
    for(freq_Value1; freq_Value1<=freq_Value2; freq_Value1+=salto)
    {
      AD.setFrequency(0, freq_Value1);
      
    }
  } 

  delay(500);
}

void SetearModo(void)
{
  mode = MD_AD9833::MODE_SINE; 
  //mode = MD_AD9833::MODE_OFF;
  AD.setMode(mode);
}

void ModoOFF(void)
{
  mode = MD_AD9833::MODE_OFF;
  AD.setMode(mode);
}

void SetearFrecuencia(void)
{  
  if (freq_Value1 != 0) 
  {
    if (freq_Value1 > 12500000) freq_Value1 = 12500000;
    AD.setFrequency(0, freq_Value1);
  }
}