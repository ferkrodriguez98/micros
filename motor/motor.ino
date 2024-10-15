#include <Stepper.h>

const int stepsPerRevolution = 2048;  // El motor 28BYJ-48 tiene 2048 pasos por revolución
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);  // Pines correctos del motor

const int buttonPin = 2;  // Pin del botón
bool motorState = false;  // Estado del motor (apagado o encendido)
bool lastButtonState = HIGH;  // Estado anterior del botón

void setup() {
  // Inicializar el Monitor Serie
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);  // Usar la resistencia pull-up interna
  myStepper.setSpeed(10);  // Ajustar la velocidad del motor a 10 RPM
  Serial.println("Sistema listo. Presiona el botón para encender/apagar el motor.");
}

void loop() {
  // Leer el estado del botón
  bool buttonState = digitalRead(buttonPin);

  // Detectar si el botón fue presionado (cambio de estado)
  if (buttonState == LOW && lastButtonState == HIGH) {
    motorState = !motorState;  // Cambiar el estado del motor (encendido/apagado)
    
    // Mostrar el estado del motor en el Monitor Serie
    if (motorState) {
      Serial.println("Motor encendido.");
    } else {
      Serial.println("Motor apagado.");
    }
  }

  // Guardar el estado del botón para la siguiente lectura
  lastButtonState = buttonState;

  // Si el motor está encendido, hacerlo girar continuamente
  if (motorState) {
    myStepper.step(stepsPerRevolution);  // Gira una pequeña cantidad de pasos continuamente
  }

  delay(100);  // Pausa pequeña para evitar que el motor gire demasiado rápido
}
