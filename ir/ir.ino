#include <IRremote.hpp>

const int RECV_PIN = 9;   // Pin donde está conectado el receptor IR
const int IR_LED_PIN = 2; // Pin donde está conectado el transmisor IR

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();   // Inicia el receptor
  irsend.begin();        // Inicia el transmisor
  Serial.println("Ready to receive signals from the new remote");
}

void loop() {
  // Captura la señal del control remoto
  if (irrecv.decode(&results)) {
    Serial.print("Received value: ");
    Serial.println(results.value, HEX); // Muestra el valor recibido en HEX

    // Si el código es F609FF00 (el que envía tu nuevo control remoto)
    if (results.value == 0xF609FF00) {
      // Enviar el código 10010 para encender la TV
      irsend.sendNEC(0x10010, 32);  
      Serial.println("Sending power-on signal to TV");
    }

    // Si tienes otros botones en el control, puedes agregar más verificaciones
    // Para ejemplo, puedes usar otro código para apagar la TV
    // Si usas el mismo botón para apagar la TV, puedes hacer un toggle entre encender y apagar.

    irrecv.resume();  // Prepara el receptor para la próxima señal
  }
}
