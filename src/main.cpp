#include <Arduino.h>
#include <LiquidCrystal.h>
#include <BigCrystal.h>

#include "MotorPassos.h"
#include "MultiMotor.h"
#include "SensorTemperatura.h"
#include "SensorHumidadeSolo.h"
#include "BombaIrrigacao.h"

#define RS 53
#define EN 51
#define D0 49
#define D1 47
#define D2 45
#define D3 43
#define D4 41
#define D5 39
#define D6 37
#define D7 35
#define LCD_WIDTH 16
#define LCD_HEIGHT 2

#define PINO_SENSOR_TEMPERATURA 52
#define PINO_SENSOR_HUMIDADE_SOLO 7
#define PINO_RELE_BOMBA_IRRIGACAO 2

LiquidCrystal display(RS, EN, D0, D1, D2, D3, D4, D5, D6, D7);
BigCrystal displayLcd(&display);

SensorTemperatura sensorTemperatura(PINO_SENSOR_TEMPERATURA, DHT11);
SensorHumidadeSolo sensorHumidadeSolo(PINO_SENSOR_HUMIDADE_SOLO);
BombaIrrigacao bombaIrrigacao(PINO_RELE_BOMBA_IRRIGACAO);

int temperaturaEstufa;
int humidadeEstufa;

void setup() {
    Serial.begin(9600);
    displayLcd.begin(LCD_WIDTH, LCD_HEIGHT);
    sensorTemperatura.init();
    sensorHumidadeSolo.init();
    bombaIrrigacao.init();

    temperaturaEstufa = sensorTemperatura.captarTemperatura();
    humidadeEstufa = sensorTemperatura.captarHumidade();

    delay(500);
}

void loop() {
  displayLcd.print("Temperatura: ");
  displayLcd.print(temperaturaEstufa);
  displayLcd.print("oC");
  displayLcd.setCursor(0, 1);
  displayLcd.print("Humidade: ");
  displayLcd.print(humidadeEstufa);
  displayLcd.print("%");

  temperaturaEstufa = sensorTemperatura.captarTemperatura();
  humidadeEstufa = sensorTemperatura.captarHumidade();
  sensorHumidadeSolo.controlarBombaIrrigacao(bombaIrrigacao);

  delay(3000);
  displayLcd.clear();
}

/*-----------------------------------------------------------------------------------------*/

// #include "MotorPassos.h"
// #include "MultiMotor.h"
// #include "Botao.h"

// #define BOTAO_PIN 12

// #define MOTOR1_PORT1 1
// #define MOTOR1_PORT2 2
// #define MOTOR1_PORT3 3
// #define MOTOR1_PORT4 4

// #define MOTOR2_PORT1 8
// #define MOTOR2_PORT2 7
// #define MOTOR2_PORT3 9
// #define MOTOR2_PORT4 10

// MotorPassos stepper1(MOTOR1_PORT1, MOTOR1_PORT2, MOTOR1_PORT3, MOTOR1_PORT4);
// MotorPassos stepper2(MOTOR2_PORT1, MOTOR2_PORT2, MOTOR2_PORT3, MOTOR2_PORT4);

// MotorPassos motores[] = {stepper1, stepper2};

// MultiMotor motoresEstufa(motores, 2, (360+50), 3);

// Botao botao(BOTAO_PIN);

// void setup() {
//   botao.init();
//   Serial.begin(9600);
// }


// void loop() {

//   stepper1.definirSentidoAntiHorario();
//   stepper2.definirSentidoHorario();
//   motoresEstufa.moverMotoresEmSincronia();

//   Serial.println(botao.pegarEstado());
// }