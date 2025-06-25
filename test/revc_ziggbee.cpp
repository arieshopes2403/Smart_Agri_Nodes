#include <SoftwareSerial.h>

// D6 = GPIO12 (RX), D7 = GPIO13 (TX)
SoftwareSerial zigbeeSerial(13, 12); // RX, TX

void setup() {
  Serial.begin(115200); // Dùng để debug trên máy tính
  zigbeeSerial.begin(9600); // UART cho CC2530

  Serial.println("ESP8266 sẵn sàng nhận dữ liệu ZigBee...");
}

void loop() {
  if (zigbeeSerial.available()) {
    String msg = zigbeeSerial.readStringUntil('\n');
    Serial.print("Dữ liệu nhận được: ");
    Serial.println(msg);
  }
}