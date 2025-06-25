#include <SoftwareSerial.h>

// RX = 3, TX = 4
SoftwareSerial zigbeeSerial(4, 3); // RX, TX

void setup() {
  Serial.begin(9600); // Debug ra máy tính
  zigbeeSerial.begin(9600); // Giao tiếp với CC2530

  Serial.println("Arduino sẵn sàng gửi dữ liệu qua ZigBee...");
}

void loop() {
  const char* message = "Hello from Arduino via ZigBee!";
  zigbeeSerial.println(message);
  Serial.println("Đã gửi: Hello from Arduino via ZigBee!");
  delay(2000);
}