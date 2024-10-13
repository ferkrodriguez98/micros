#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("Sistema RFID inicializado");
  Serial.println("Acerque una tarjeta RFID...");
}

void loop() {
  // Verificamos si hay una tarjeta presente
  if (!rfid.PICC_IsNewCardPresent()) {
    // Serial.println("No hay ninguna tarjeta presente");
    return;
  }
  
  // Si hay una tarjeta, intentamos leer su UID
  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println("Error al leer la tarjeta");
    return;
  }

  // Mostramos el UID de la tarjeta en el monitor serie
  Serial.print("UID de la tarjeta: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Detenemos la lectura para la próxima tarjeta
  rfid.PICC_HaltA();
}
