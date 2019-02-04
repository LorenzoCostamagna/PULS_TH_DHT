// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11   // DHT 11
#include "max6675.h"
//unsigned long old_millis = 0;
//unsigned long delta = 600;
int minuti = 1;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int pushbutton = 7; // definiamo il pin 7 con il nome pushbutton
int digitalval = 0;
int oldState = 0;
//int analogval = 0; //definiamo valore analogico uguale a 0

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.println(F("DHTxx test!"));
  pinMode(pushbutton , INPUT); //inizializziamo il pin del pulsante come input
  dht.begin();


  Serial.begin(9600);
  // use Arduino pins
  Serial.println("millis, TempDHT, TempThermo");

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(2500);
}

void loop() {



 unsigned long now = millis(); //variabile usata aper gesti


  digitalval = digitalRead(pushbutton); //leggiamo lo stato del pulsante
 
  if (digitalval == HIGH && digitalval != oldState) { //se lo stato del pulsante è 1
    //oldState=digitalval;

    float h = dht.readHumidity();
    float TempThermo = thermocouple.readCelsius();
    float TempDHT = dht.readTemperature();
   // float hic = dht.computeHeatIndex(TempDHT, h);
    Serial.print(millis());
    Serial.print(", ");
    Serial.print(TempDHT);
    Serial.print(", ");
    Serial.println(TempThermo);
    //old_millis = now; //terminato il ciclo pone il valore
    // minuti = minuti + 1; //incrementa il contatore dei minuti
  }
  oldState = digitalval;


  delay(10);
}
