#include <DHT.h> 
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2 
#define DHTTYPE DHT22

#define I2C_ADDR 0x27 
#define BACKLIGHT_PIN 3
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(0x27,20,4);
DHT dht(DHTPIN, DHTTYPE);

void setup(){
  lcd.init();
  lcd.init();
  lcd.backlight();
  dht.begin();
  Serial.begin(57600);

  lcd.setCursor(0, 0);
  lcd.print("Hudim.:");
  lcd.setCursor(0, 1);
  lcd.print("Temp.:");
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.setCursor(11, 0);
  lcd.print(h);
  lcd.setCursor(11, 1);
  lcd.print(t);
}
