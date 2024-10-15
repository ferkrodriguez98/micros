#include <Arduino.h>

#define LED_PIN 4  // El LED flash de la ESP32-CAM está conectado al GPIO 4

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);  // Configura el GPIO 4 como salida
  Serial.println("Control del LED en la ESP32-CAM");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Enciende el LED
  delay(1000);                  // Espera 1 segundo
  digitalWrite(LED_PIN, LOW);   // Apaga el LED
  delay(1000);                  // Espera 1 segundo
}
