// -------------------- Arduino Node (Point A) --------------------
#include <Arduino.h>
#include <Wire.h>
#include "SensorManager.h"
#include "DisplayManager.h"
#include "SerialPrint.h"
#include <SoftwareSerial.h>

#define RX 4  
#define TX 3  

SensorManager sensor;
DisplayManager display;
SoftwareSerial zigbeeSerial(RX, TX);  // RX, TX

void setup() {
    Serial.begin(9600);
    zigbeeSerial.begin(9600);
    Wire.begin();
    sensor.begin();
    display.begin();
    Serial.println("Node 01 ready...");
}

void loop() {
    float temp = sensor.getTemperature();
    float humi = sensor.getHumidity();
    float lux  = sensor.getLightLevel();

    String jsonData;

    // SerialPrint::printData(temp, humi, lux);
    // display.show(temp, humi, lux);
    Serial.print("abc----------");
    if (!isnan(temp) && !isnan(humi) && !isnan(lux)) {
        // data ok ne 
        jsonData = "{\"id\":\"1\",\"temp\":" + String(temp, 1) +
                   ",\"humi\":" + String(humi, 1) +
                   ",\"light\":" + String(lux, 0) + "}*";

        Serial.println("Sending data: " + jsonData);
        zigbeeSerial.print(jsonData);
        
    } else {
        // send error
        jsonData = "{\"id\":\"0\"}*";
        Serial.println("Sensor error → Sending: " + jsonData);
        zigbeeSerial.print(jsonData);
    }

    delay(3000);  
}
