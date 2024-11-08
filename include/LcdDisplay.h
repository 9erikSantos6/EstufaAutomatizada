#ifndef __LCD_DISPLAY_H_
#define __LCD_DISPLAY_H_

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <BigCrystal.h>

class LcdDisplay : public BigCrystal {
private:
    LiquidCrystal lcd;  // Declare a LiquidCrystal object

public:
    // Constructor
    LcdDisplay(uint8_t rs, uint8_t enable,
               uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
               uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
};

#endif