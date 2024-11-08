#include "LcdDisplay.h"

// Constructor implementation
LcdDisplay::LcdDisplay(uint8_t rs, uint8_t enable,
                        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
                        uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
    : lcd(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7),  // Initialize LiquidCrystal object
      BigCrystal(&lcd) {  // Pass the LiquidCrystal object to BigCrystal
    // Any additional initialization can be done here
}