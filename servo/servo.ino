#include <Servo.h>

Servo miServo;
const int pinJoystickX = A0;
int valorJoystickX = 0;
int anguloServo = 0;

int leerJoystickSuavizado(int pin) {
  int total = 0;
  const int numLecturas = 10; // Número de lecturas para promediar

  // Hacer múltiples lecturas para suavizar el ruido
  for (int i = 0; i < numLecturas; i++) {
    total += analogRead(pin);
    delay(5);  // Pequeña pausa entre lecturas
  }

  return total / numLecturas; // Devolver el promedio
}

void setup() {
  miServo.attach(9);  // Pin del servo
  Serial.begin(9600);
}

void loop() {
  valorJoystickX = leerJoystickSuavizado(pinJoystickX);  // Leer joystick con filtro

  // Añadir zona muerta para evitar movimientos erráticos cerca del centro
  if (valorJoystickX > 512 - 20 && valorJoystickX < 512 + 20) {
    valorJoystickX = 512; // Mantener el valor central
  }
  
  // Mapear valor del joystick (0-1023) a un ángulo de servo (0-180)
  anguloServo = map(valorJoystickX, 0, 1023, 0, 180);
  miServo.write(anguloServo);  // Mover el servo
  
  delay(15);
  Serial.print("Joystick X: ");
  Serial.print(valorJoystickX);
  Serial.print("\tServo: ");
  Serial.println(anguloServo);
  
}
