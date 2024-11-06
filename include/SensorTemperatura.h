#ifndef __SENSOR_TEMPERATURA_
#define __SENSOR_TEMPERATURA_

#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

class SensorTemperatura {
  private:
    DHT_Unified dht;
    sensor_t sensor;
    sensors_event_t event;
    float delayMS;

  public: 
    SensorTemperatura(uint8_t port, uint8_t dhttype);

    void init();
    float pegarDelay();
    float captarTemperatura();
    float captarHumidade();
    void mostrarInformacoes();
};

#endif