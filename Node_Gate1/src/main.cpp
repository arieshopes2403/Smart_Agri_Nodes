#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial zigbee(13, 12);  // RX, TX (D7, D6)

String incoming = "";

void setup() {
  Serial.begin(9600);
  zigbee.begin(9600);
  // Serial.println("Zigbee Receiver Ready...");
}

void loop() {
  while (zigbee.available()) {
    char c = zigbee.read();

    if (c == '*') {
      //het goi tin -> xu ly thoi
      Serial.println("Received raw: " + incoming);

      String id = parseString(incoming, "id");

      if (id == "1") {
        float temp = parseValue(incoming, "temp");
        float humi = parseValue(incoming, "humi");
        float light = parseValue(incoming, "light");

        Serial.print("Temp: "); Serial.print(temp);
        Serial.print(" °C | Humi: "); Serial.print(humi);
        Serial.print(" % | Light: "); Serial.println(light);
      } else if (id == "0") {
        Serial.println("Node báo lỗi cảm biến!");
      } else {
        Serial.println("Unknown ID: " + id);
      }

      incoming = "";  // reset buffer 
    } else {
      incoming += c;
    }
  }
}

// -------------------- Helper Functions --------------------

// Lấy giá trị float từ key
float parseValue(const String& data, const String& key) {
  int keyIndex = data.indexOf(key);
  if (keyIndex == -1) return NAN;

  int colonIndex = data.indexOf(":", keyIndex);
  int commaIndex = data.indexOf(",", colonIndex);
  if (commaIndex == -1) commaIndex = data.indexOf("}", colonIndex);

  String valueStr = data.substring(colonIndex + 1, commaIndex);
  valueStr.trim();
  return valueStr.toFloat();
}

// Lấy giá trị chuỗi từ key (dạng "id":"01")
String parseString(const String& data, const String& key) {
  int keyIndex = data.indexOf(key);
  if (keyIndex == -1) return "";

  int quote1 = data.indexOf("\"", keyIndex + key.length() + 2);
  int quote2 = data.indexOf("\"", quote1 + 1);
  return data.substring(quote1 + 1, quote2);
}
