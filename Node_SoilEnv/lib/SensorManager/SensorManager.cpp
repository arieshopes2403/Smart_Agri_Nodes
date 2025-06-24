#include "SensorManager.h"
#include <Adafruit_SHT31.h>
#include <BH1750.h>

Adafruit_SHT31 sht30 = Adafruit_SHT31();
BH1750 lightMeter;

float tempState = 0, humState = 0, luxState = 0;
bool tempInit = false, humInit = false, luxInit = false;

void SensorManager::begin() {
    sht30.begin(0x44);
    lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE);
}

float SensorManager::getTemperature() {
    return applyEMA(sht30.readTemperature(), tempState, tempInit);
}

float SensorManager::getHumidity() {
    return applyEMA(sht30.readHumidity(), humState, humInit);
}

float SensorManager::getLightLevel() {
    return applyEMA(lightMeter.readLightLevel(), luxState, luxInit);
}

// Lọc nhiễu dùng EMA
float SensorManager::applyEMA(float input, float& state, bool& initialized, float alpha) {
    if (isnan(input)) return NAN;
    if (!initialized) {
        state = input;
        initialized = true;
    } else {
        state = alpha * input + (1 - alpha) * state;
    }
    return state;
}
