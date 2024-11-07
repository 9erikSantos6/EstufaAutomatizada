#include <Arduino.h>
#include <Wire.h>
#include <BigCrystal.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(30, 31, 32, 33, 34, 35, 36, 37, 38, 39); 
BigCrystal bigCrystal(&lcd);

int temperaturaSimulada = 0;
int humidadeSimulada = 50;

void setup() {
    bigCrystal.begin(16, 2);
  }

void loop() {
  bigCrystal.print("Temperatura: ");bigCrystal.print(temperaturaSimulada);bigCrystal.print("oC");bigCrystal.setCursor(0, 1);
  bigCrystal.print("Humidade: ");bigCrystal.print(humidadeSimulada);bigCrystal.print("%");

  temperaturaSimulada += 1;
  delay(2000);
  bigCrystal.clear();
}