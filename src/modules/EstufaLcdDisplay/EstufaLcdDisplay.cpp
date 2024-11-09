#include <BigCrystal.h>
#include <LiquidCrystal.h>
#include "EstufaLcdDisplay.h"

EstufaLcdDisplay::EstufaLcdDisplay(uint8_t rs, uint8_t enable,
                 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7) 
    : lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7), BigCrystal(&lcd) {}

void EstufaLcdDisplay::mostrarClimaEstufa(int temperaturaEstufa, int humidadeEstufa) {
  this->print("Temperatura: ");
  this->print(temperaturaEstufa);
  this->print("oC");
  this->setCursor(0, 1);
  this->print("Humidade: ");
  this->print(humidadeEstufa);
  this->print("%");
}