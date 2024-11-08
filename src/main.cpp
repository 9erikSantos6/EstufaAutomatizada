#include <Arduino.h>
#include <Wire.h>
#include <BigCrystal.h>
#include <LiquidCrystal.h>
#include "MotorPassos.h"
#include "MultiMotor.h"
#include "SensorTemperatura.h"
#include "SensorHumidadeSolo.h"
#include "Rele.h"


// (uint8_t rs, uint8_t enable,
//                  uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
//                  uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
#define RS 30
#define EN 31
#define D0 32
#define D1 33
#define D2 34
#define D3 35
#define D4 36
#define D5 37
#define D6 38
#define D7 39
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

LiquidCrystal lcd(RS, EN, D0, D1, D2, D3, D4, D5, D6, D7); 
BigCrystal displayLcd(&lcd);
SensorTemperatura sensorTemperatura(2, DHT11);
SensorHumidadeSolo sensorHumidadeSolo(3);
Rele rele(8);

int temperaturaEstufa;
int humidadeEstufa;

void setup() {
    displayLcd.begin(LCD_WIDTH, LCD_HEIGHT);
    sensorHumidadeSolo.init();
    sensorTemperatura.init();
    sensorHumidadeSolo.init();
    rele.init();
}

void loop() {
  displayLcd.print("Temperatura: ");displayLcd.print(temperaturaEstufa);displayLcd.print("oC");displayLcd.setCursor(0, 1);
  displayLcd.print("Humidade: ");displayLcd.print(humidadeEstufa);displayLcd.print("%");

  temperaturaEstufa = sensorTemperatura.captarTemperatura();
  humidadeEstufa = sensorTemperatura.captarHumidade();

  sensorHumidadeSolo.gerenciarRele(rele);
  delay(2000);
  displayLcd.clear();
}