#include <Arduino.h>
#include <LiquidCrystal.h>
#include "EstufaLcdDisplay.h"
#include "MotorPassos.h"
#include "MultiMotor.h"
#include "SensorTemperatura.h"
#include "SensorHumidadeSolo.h"
#include "Rele.h"

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

#define PINO_SENSOR_TEMPERATURA 2
#define PINO_SENSOR_HUMIDADE_SOLO 3
#define PINO_RELE 8

LiquidCrystal lcd(RS, EN, D0, D1, D2, D3, D4, D5, D6, D7); 
EstufaLcdDisplay displayLcd(&lcd);
SensorTemperatura sensorTemperatura(PINO_SENSOR_TEMPERATURA, DHT11);
SensorHumidadeSolo sensorHumidadeSolo(PINO_SENSOR_HUMIDADE_SOLO);
Rele rele(PINO_RELE);

int temperaturaEstufa;
int humidadeEstufa;

void setup() {
    displayLcd.begin(LCD_WIDTH, LCD_HEIGHT);
    sensorHumidadeSolo.init();
    sensorTemperatura.init();
    sensorHumidadeSolo.init();
    rele.init();

    temperaturaEstufa = sensorTemperatura.captarTemperatura();
    humidadeEstufa = sensorTemperatura.captarHumidade();
}

void loop() {
  displayLcd.mostrarClimaEstufa(temperaturaEstufa, humidadeEstufa);
  temperaturaEstufa = sensorTemperatura.captarTemperatura();
  humidadeEstufa = sensorTemperatura.captarHumidade();
  sensorHumidadeSolo.gerenciarRele(rele);
  delay(2000);
  displayLcd.clear();
}