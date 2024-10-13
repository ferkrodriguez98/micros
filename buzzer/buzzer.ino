#include <Arduino.h>

int buzzerPin = 9;     // Pin al que conectamos el buzzer
int buttonPin = 2;     // Pin al que conectamos el botón
int potPin = A0;       // Pin al que conectamos el potenciómetro
bool buzzerOn = false; // Estado del buzzer (encendido o apagado)

void setup()
{
  pinMode(buzzerPin, OUTPUT);       // Configuramos el pin del buzzer como salida
  pinMode(buttonPin, INPUT_PULLUP); // Usamos la resistencia pull-up interna
  pinMode(potPin, INPUT);           // Configuramos el pin del potenciómetro como entrada
}

void loop()
{
  // Si el botón está presionado (lectura baja por el pull-up)
  if (digitalRead(buttonPin) == LOW)
  {
    // Cambiamos el estado del buzzer
    buzzerOn = !buzzerOn;

    // Si el buzzer está encendido, emitimos tono
    if (buzzerOn)
    {
      // Leer el valor del potenciómetro y mapearlo a una frecuencia
      int potValue = analogRead(potPin);
      int frequency = map(potValue, 0, 1023, 500, 2000); // Mapeamos el valor del potenciómetro a una frecuencia entre 500 y 2000 Hz
      tone(buzzerPin, frequency);                        // Emitimos el tono con la frecuencia ajustada por el potenciómetro
    }
    else
    {
      noTone(buzzerPin); // Apagamos el tono
    }

    // Esperamos un poco para evitar el rebote del botón
    delay(300);
  }
}
