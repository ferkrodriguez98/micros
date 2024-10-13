#include <Stepper.h>

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // El motor 28BYJ-48 tiene 2048 pasos por revolución
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  // Pines correctos para el motor

const int buttonPin = 2;  // Pin del botón
bool motorState = false;  // Estado del motor (apagado o encendido)
bool lastButtonState = HIGH;  // Estado anterior del botón

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  myStepper.setSpeed(10);  // Ajustar la velocidad a 10 RPM
  Serial.println("Sistema listo. Presiona el botón para encender/apagar el motor.");
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Cambiar el estado del motor cuando el botón se presiona
  if (buttonState == LOW && lastButtonState == HIGH) {
    motorState = !motorState;
    if (motorState) {
      Serial.println("Motor encendido.");
    } else {
      Serial.println("Motor apagado.");
    }
  }

  lastButtonState = buttonState;

  // Si el motor está encendido, girar una vuelta completa
  if (motorState) {
    myStepper.step(stepsPerRevolution);  // Girar una vuelta completa (2048 pasos)
    Serial.println("El motor está girando...");
  }

  delay(100);  // Pausa para evitar lecturas rápidas
}
