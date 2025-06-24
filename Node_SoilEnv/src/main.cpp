// -------------------- Arduino Node (Point A) --------------------
#include <Arduino.h>
#include <Wire.h>
#include "SensorManager.h"
#include "DisplayManager.h"
#include "SerialPrint.h"
#include <SoftwareSerial.h>

#define RX 3  
#define TX 2  

SensorManager sensor;
DisplayManager display;
SoftwareSerial zigbeeSerial(RX, TX);  // RX, TX

void setup() {
    Serial.begin(9600);
    zigbeeSerial.begin(9600);
    Wire.begin();
    sensor.begin();
    display.begin();
    // Serial.println("Node 01 ready...");
}

void loop() {
    float temp = sensor.getTemperature();
    float humi = sensor.getHumidity();
    float lux  = sensor.getLightLevel();

    String jsonData;

    SerialPrint::printData(temp, humi, lux);
    display.show(temp, humi, lux);
    Serial.print("abc----------");
    // if (!isnan(temp) && !isnan(humi) && !isnan(lux)) {
    //     // data ok ne 
    //     jsonData = "{\"id\":\"01\",\"temp\":" + String(temp, 1) +
    //                ",\"humi\":" + String(humi, 1) +
    //                ",\"light\":" + String(lux, 0) + "}*";

    //     Serial.println("Sending data: " + jsonData);
    //     zigbeeSerial.print(jsonData);
        
    // } else {
    //     // send error
    //     jsonData = "{\"id\":\"0\"}*";
    //     Serial.println("Sensor error → Sending: " + jsonData);
    //     zigbeeSerial.print(jsonData);
    // }

    // String data_send = "hello ESP8266 nhe";
    // zigbeeSerial.println(data_send);

    // String json_Data ="{\"a"}";

    delay(3000);  
}
