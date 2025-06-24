#include "DisplayManager.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

void DisplayManager::begin() {
    display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("OLED ready");
    display.display();
}

void DisplayManager::show(float temp, float humi, float lux) {
    display.clearDisplay();
    display.setCursor(0, 0);

    if (!isnan(temp) && !isnan(humi)) {
        display.print("Nhiet do : "); display.print(temp, 1); display.println(" C");
        display.print("Do am   : ");  display.print(humi, 1); display.println(" %");
    } else display.println("SHT30 ERROR");

    if (!isnan(lux)) {
        display.print("Anh sang: "); display.print(lux, 0); display.println(" lx");
    } else display.println("BH1750 ERROR");

    display.display();
}
