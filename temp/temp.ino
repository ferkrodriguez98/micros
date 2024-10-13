#include <Arduino.h>

const int sensorPin = A0;  // Pin donde está conectado el LM35

void setup() {
  Serial.begin(9600);  // Iniciar la comunicación serie
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // Leer el valor del sensor
  float voltage = sensorValue * (5.0 / 1023.0);  // Convertir el valor a voltaje
  Serial.print("Voltaje leido: ");
  Serial.println(voltage);  // Mostrar el voltaje para verificar
  
  delay(1000);  // Esperar 1 segundo
}
