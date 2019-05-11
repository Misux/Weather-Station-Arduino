
#include "Wire.h"
#include "Adafruit_BMP085.h"
#include "DHT.h"
Adafruit_BMP085 bmp;
#define DHTPIN 1     // what pin we're connected to


#define DHTTYPE DHT22   // DHT 22  (AM2302)


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  
 bmp.begin();
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");
  }
  
  
  
  Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
 
    Serial.println();
    delay(500);
}


