#include <Arduino.h>
#include <DHT.h>
// #include <LiquidCrystal_I2C.h>

// #define pinDHT 23
#define tipoDHT DHT22
#define pinVermelho 15
#define pinDHT 18
#define pinAzul 4



DHT dht(pinDHT, tipoDHT);

// LiquidCrystal_I2C lcd (0x27, 20, 4);

unsigned long tempoAnterior = 0;
unsigned long intervalo = 250;

// float tempAnteriorF = 0;
// float umiAnterior = 0;

int intensidade1 = 0;
int intensidade2 = 0;
//int intensidade3 = 0;
//bool passo1 = false;
//bool passo2 = false;
//bool passo3 = false;


void setup()
{

  dht.begin();
  // Serial.println("Teste de DHT22");

  // lcd.init();
  // lcd.backlight();

  pinMode(pinVermelho, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  //pinMode(pinLed3, OUTPUT);
  Serial.begin(115200);
}

void loop()
{

  // exercícios em lcd - 09/10

    float tempC = dht.readTemperature();
  //  float tempF = dht.readTemperature(true);
    float umi = dht.readHumidity();
  //
  unsigned long tempoAtual = millis();
  //
  //  if(tempoAtual - tempoAnterior >= intervalo){
  //
  //
  //    lcd.setCursor(0,0);
  //    lcd.print("Temp em C: ");
  //
  //    if(tempC > tempAnteriorC || tempC < tempAnteriorC){
  //      Serial.print("Temp em C: ");
  //      Serial.println(tempC);
  //      lcd.setCursor(11,0);
  //      lcd.print(tempC);
  //    }
  //
  //
  //    lcd.setCursor(0,1);
  //    lcd.print("Temp em F: ");
  //
  //    if(tempF > tempAnteriorF || tempF < tempAnteriorF){
  //      Serial.print("Temp em F: ");
  //      Serial.println(tempF);
  //      lcd.setCursor(11,1);
  //      lcd.print(tempF);
  //    }
  //
  //
  //
  //    lcd.setCursor(0,2);
  //    lcd.print("Umidade: ");
  //
  //    if(umi > umiAnterior || umi < umiAnterior){
  //      Serial.print("Umidade: ");
  //      Serial.println(umi);
  //      lcd.setCursor(9,2);
  //      lcd.print(umi);
  //    }
  //    Serial.println("------------------------------");
  //    umiAnterior = umi;
  //    tempAnteriorC = tempC;
  //    tempAnteriorF = tempF;
  //
  //    tempoAnterior = tempoAtual;
  //  }
  //
  //
  //

  // led e intensidade 

  //EXERCICIO 1 - 16/10

  //if (tempoAtual - tempoAnterior >= intervalo)
  //{
  //  if (passo1 == false && passo3 == false)
  //  {
  //    intensidade1 += 5;
  //  }
//
  //  if (passo1 == true && passo2 == false)
  //  {
  //    intensidade2 += 5;
  //  }
//
//
  //  if (passo2 == true && passo3 == false)
  //  {
  //    intensidade3 += 5;
  //  }
//
  //  if (passo3 == true)
  //  {
  //    intensidade1 -=5 ;
  //  }
//
  //  if(passo3 == true && passo1 == false){
//
  //    intensidade2 -=5;
//
  //  }
//
  //  if (passo3 == true && passo2 == false)
  //  {
  //    intensidade3 -= 5;
  //  }
  //  
  //  
//
  //  tempoAnterior = tempoAtual;
//
  //  Serial.print("intensidade 1: ");
  //  Serial.println(intensidade1);
  //  Serial.print("intensidade 2: ");
  //  Serial.println(intensidade2);
  //  Serial.print("intensidade 3: ");
  //  Serial.println(intensidade3);
  //  analogWrite(pinLed1, intensidade1);
  //  analogWrite(pinLed2, intensidade2);
  //  analogWrite(pinLed3, intensidade3);
//
  //}
//
  //if (intensidade1 >= 255)
  //{
  //  intensidade1 = 255;
  //  passo1 = true;
  //}
//
  //if (intensidade1 <= 0)
  //{
  //  intensidade1 = 0;
  //  passo1 = false;
  //}
//
//
  //if (intensidade2 >= 255){
  //  intensidade2 = 255;
  //  passo2 = true;
  //}
//
  //if (intensidade2 <= 0){
  //  intensidade2 = 0;
  //  passo2 = false;
  //}
//
  //if (intensidade2 >= 255){
  //  intensidade2 = 255;
  //  passo2 = true;
  //}
//
  //if (intensidade3 <= 0){
  //  intensidade3 = 0;
  //  passo3 = false;
  //}
//
  //
  //if (intensidade3 >= 255){
  //  intensidade3 = 255;
  //  passo3 = true;
  //}


  //EXERCÍCIO 2 - 16/10
  int tempInteira = (int)tempC;
  int umiInteira = (int)umi;

  intensidade1 = map(tempInteira, 23, 27, 0, 255);
  intensidade2 = map(umiInteira, 59, 70, 0, 255);

  intensidade1 = constrain(intensidade1, 0, 255);
  intensidade2 = constrain(intensidade2, 0, 255);

  if (tempoAtual - tempoAnterior >= intervalo){


    analogWrite(pinAzul, intensidade2);
    analogWrite(pinVermelho, intensidade1);
    Serial.println(tempC);
    Serial.println(umi);
    
    tempoAnterior = tempoAtual;


  }
}
