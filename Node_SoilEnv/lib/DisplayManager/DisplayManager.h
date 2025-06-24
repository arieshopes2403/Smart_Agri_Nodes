#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H
#include <Adafruit_SSD1306.h>

class DisplayManager
{
private:
    Adafruit_SSD1306 display;
public:
    void begin();
    void show(float temperature, float humidity, float lux);
};
#endif
