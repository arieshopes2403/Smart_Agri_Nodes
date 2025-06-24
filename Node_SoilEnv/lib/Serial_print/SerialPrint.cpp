#include "SerialPrint.h"
#include <Arduino.h>
void SerialPrint::printData(float temp, float humi, float lux) {
    Serial.print("Temperature: ");
    Serial.print(temp, 1);
    Serial.print(" C, Humidity: ");
    Serial.print(humi, 1);
    Serial.print(" %, Light Level: ");
    Serial.print(lux, 0);
    Serial.println(" lx");
    
}