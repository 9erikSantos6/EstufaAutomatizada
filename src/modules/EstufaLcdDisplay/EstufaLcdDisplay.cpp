#include <BigCrystal.h>
#include <LiquidCrystal.h>
#include "EstufaLcdDisplay.h"

EstufaLcdDisplay::EstufaLcdDisplay(LiquidCrystal* lcd) : BigCrystal(lcd) {}

void EstufaLcdDisplay::mostrarClimaEstufa(int temperaturaEstufa, int humidadeEstufa) {
  this->print("Temperatura: ");this->print(temperaturaEstufa);this->print("oC");this->setCursor(0, 1);
  this->print("Humidade: ");this->print(humidadeEstufa);this->print("%");
}