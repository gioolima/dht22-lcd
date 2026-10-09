#include <Arduino.h>
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define pinDHT 4
#define tipoDHT DHT22

DHT dht(pinDHT, tipoDHT);

LiquidCrystal_I2C lcd (0x27, 20, 4);

void setup() {
  Serial.begin(115200);

  dht.begin();
  Serial.println("Teste de DHT22");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("LCD Iniciado");
}

void loop() {
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  float umi = dht.readHumidity();

  Serial.print("Temp em C: ");
  Serial.println(tempC);
  Serial.print("Temp em F: ");
  Serial.println(tempF);
  Serial.print("Umidade: ");
  Serial.println(umi);
  Serial.println("---------------------------");

  delay(3000);
}
