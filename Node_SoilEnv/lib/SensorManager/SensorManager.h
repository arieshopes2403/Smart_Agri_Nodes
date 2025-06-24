#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

class SensorManager
{
private:
    // Function to apply Exponential Moving Average (EMA)
    // input: new value sensor reading
    float applyEMA(float input, float& state, bool& initialized, float alpha = 0.15);  

public:

    void begin();
    float getTemperature();
    float getHumidity();
    float getLightLevel();
};
#endif
