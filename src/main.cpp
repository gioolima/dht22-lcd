#include <Arduino.h>
//#include <DHT.h>
//#include <LiquidCrystal_I2C.h>

//#define pinDHT 23
//#define tipoDHT DHT22
#define pinLed 2

//DHT dht(pinDHT, tipoDHT);

//LiquidCrystal_I2C lcd (0x27, 20, 4);

//unsigned long tempoAnterior = 0;
//unsigned long intervalo = 3000;

//float tempAnteriorF = 0;
//float tempAnteriorC = 0;
//float umiAnterior = 0;

int intensidade = 0;
bool passo = false;

void setup() {

  //dht.begin();
  //Serial.println("Teste de DHT22");

  //lcd.init();
  //lcd.backlight();

  pinMode(pinLed, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  
//exercícios em lcd

//  float tempC = dht.readTemperature();
//  float tempF = dht.readTemperature(true);
//  float umi = dht.readHumidity();
//
//  unsigned long tempoAtual = millis();
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

  analogWrite(pinLed, intensidade);


  

  if(passo == false){
    intensidade += 5;
    delay(250);
  }
  
  
  if(intensidade >= 260){
    passo = true;
  }

  if(intensidade == 0){
    passo = false;
  }

  if(passo == true){
    intensidade -= 5;
    delay(250);
  }


  Serial.println(intensidade);
}
