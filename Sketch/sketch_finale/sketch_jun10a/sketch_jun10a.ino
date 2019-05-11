#include "Wire.h"
#include "Adafruit_BMP085.h"
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22  

DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP085 bmp;
void setup() {
  Serial.begin(9600); 
  bmp.begin(); 
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float pressure=bmp.readPressure();


    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(); 
    Serial.print("Pressure = "); 
    Serial.print(pressure); 
    Serial.print(" Pa");
    Serial.println();
   
 delay(500); 
}
