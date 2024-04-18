#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11 // DHT 11

// software SPI:
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64

#define OLED_MOSI  11
#define OLED_CLK   13
#define OLED_DC     9
#define OLED_CS    10
#define OLED_RESET  8
#define maxString 21
char target[maxString + 1] = "";
unsigned char i1,i2,c3;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
DHT dht(DHTPIN, DHTTYPE);
void setup(){           
  display.begin(SSD1306_SWITCHCAPVCC);
  display.cp437(true);
  dht.begin();
  Serial.begin(57600);
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // float hic = dht.computeHeatIndex(t, h, false);
  display.clearDisplay(); 
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(utf8rus("Температура: "));
  display.setTextSize(2);
  display.setCursor(10,10);
  display.println(t);
  display.setCursor(0,30);
  display.setTextSize(1);
  display.println(utf8rus("Влажность: "));
  display.setTextSize(2);
  display.setCursor(10,40);
  display.println(h);
  display.setCursor(75,10);
  display.println("\xB0");
  display.setCursor(75,40);
  display.println("%");
  display.display(); 
 
}
