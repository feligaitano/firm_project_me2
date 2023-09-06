#include <Arduino.h>
// Definición de los pines digitales y analógicos
const int DigitalOutputs = 16;
const int Resistors = 7;
const int AnalogInputs = 7;

int digitalOutputs[DigitalOutputs] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0, A1, A2, A3};
int resistors[Resistors] = {A4, A5, A6, A7, A8, A9, A10};
int analogInputs[AnalogInputs] = {A11, A12, A13, A14, A15, A16, A17};

void setup() {
  // Configurar pines digitales como salidas
  for (int i = 0; i < DigitalOutputs; i++) {
    pinMode(digitalOutputs[i], OUTPUT);
  }

  // Configurar pines analógicos como entradas
  for (int i = 0; i < Resistors; i++) {
    pinMode(resistors[i], OUTPUT);
  }

  // Configurar pines analógicos como entradas
  for (int i = 0; i < AnalogInputs; i++) {
    pinMode(analogInputs[i], INPUT);
  }
}

void loop() {
  // Tu código para controlar las salidas digitales y leer las entradas analógicas
  // Aquí puedes asignar nombres o letras a cada salida y entrada según sea necesario
}
