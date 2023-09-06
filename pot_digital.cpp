#include <DFRobot_digitalPot.h>

DFRobot_digitalPot::DFRobot_digitalPot(SPIClass *pSpi = &SPI, uint8_t csPin = 10)
{
  _pSpi = pSpi;
  _csPin = csPin;
}

void DFRobot_digitalPot::begin(void)
{
  pinMode(_csPin, OUTPUT);
  _pSpi->begin();
}

void DFRobot_digitalPot::digitalPotwrite(int cmd, int val)
{
  val = constrain(val, 0, 255);
  digitalWrite(_csPin, LOW);
  _pSpi->transfer(cmd);
  _pSpi->transfer(val);
  digitalWrite(_csPin, HIGH);
}



/*
#include "DFRobot_digitalPot.h"

DFRobot_digitalPot DP(&SPI,10);
/***********************Customized Varialbes********************
//resistance value byte (0 - 255)
//The wiper is reset to the mid-scale position upon power-up, i.e. POT0_Dn = POT1_Dn = 128
int POT0_Dn = 128;
int POT1_Dn = 128;
int BOTH_POT_Dn = 128;

void setup()
{
  DP.begin();
  DP.digitalPotwrite(BOTH_POT_SHUTDOWN, BOTH_POT_Dn);
}

void loop()
{
  //set the resistance of POT0
  DP.digitalPotwrite(POT0_SEL, POT0_Dn);   
           
}
*/