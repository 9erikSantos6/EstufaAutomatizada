#ifndef __LCD_DISPLAY_H_
#define __LCD_DISPLAY_H_

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <BigCrystal.h>

class EstufaLcdDisplay : public BigCrystal {
  public:
    EstufaLcdDisplay(LiquidCrystal* lcd);
    void mostrarClimaEstufa(int temperaturaEstufa, int humidadeEstufa);
};

#endif
