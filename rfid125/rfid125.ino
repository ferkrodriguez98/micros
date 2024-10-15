#include <SoftwareSerial.h>

// Configurar pines para la comunicación con el RDM6300
SoftwareSerial rdm6300(9, 3); // RX en el pin 2 (para recibir datos del RDM6300), TX no se usa

void setup() {
  // Iniciar la comunicación serial para el monitor serial
  Serial.begin(9600);
  // Iniciar la comunicación con el RDM6300 a 9600 baudios
  rdm6300.begin(9600);
  Serial.println("Esperando tarjeta...");
}

void loop() {
  // Verificar si hay datos disponibles desde el RDM6300
  if (rdm6300.available() > 0) {
    Serial.println("Tarjeta detectada.");
    String tagID = "";
    while (rdm6300.available() > 0) {
      char c = (char)rdm6300.read();
      tagID += c;
    }

    Serial.print("ID de la tarjeta: ");
    Serial.println(tagID);
    delay(1000);  // Pausa para evitar lecturas repetitivas
  }
}
