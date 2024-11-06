#include <SensorTemperatura.h>
#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

SensorTemperatura::SensorTemperatura(uint8_t port, uint8_t dhttype) 
  : dht(port, dhttype) {}

void SensorTemperatura::init() {
  this->dht.begin();
  this->dht.temperature().getSensor(&this->sensor);
  this->delayMS = this->sensor.min_delay / 1000;
}

float SensorTemperatura::pegarDelay() {
  return this->delayMS;
}

float SensorTemperatura::captarTemperatura() {
  dht.temperature().getEvent(&this->event);
  if (isnan(event.temperature)) {
    Serial.println(F("Erro ao ler temperatura!"));
    return NAN;
  }
  else {
    return this->event.temperature;
  }
}

float SensorTemperatura::captarHumidade() {
dht.humidity().getEvent(&this->event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Erro ao ler humidade!"));
    return NAN;
  }
  else {
    return this->event.relative_humidity;
  }
}

void SensorTemperatura::mostrarInformacoes() {
  //Detalhes sensor de temperatura
  Serial.println(F("------------------------------------"));
  Serial.println(F("Sensor de Temperatura"));
  Serial.print  (F("Tipo de Sensor: ")); Serial.println(this->sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(this->sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(this->sensor.sensor_id);
  Serial.print  (F("Valor Máximo:   ")); Serial.print(this->sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Valor Minimo:   ")); Serial.print(this->sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolução:  ")); Serial.print(this->sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Detalhes sensor de humidade
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Sensor de Humidade"));
  Serial.print  (F("Tipo de Sensor: ")); Serial.println(this->sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(this->sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(this->sensor.sensor_id);
  Serial.print  (F("Valor Máximo:   ")); Serial.print(this->sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Valor Minimo:   ")); Serial.print(this->sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolução:  ")); Serial.print(this->sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
}


