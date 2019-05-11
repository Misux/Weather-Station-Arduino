#include <Wire.h>


#include "DHT.h"

#include <LiquidCrystal.h>

#define DHTPIN 2     // what pin the sensor is connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
// for use of another DHT sensor, please see the DHTtester sketch from Adafruit 
// Industries for more information.


DHT dht(DHTPIN, DHTTYPE);

// I am using the following pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Setting up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    
  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    lcd.print("Failed to read from DHT");
  } else {
    lcd.setCursor(0, 0); //set the cursor to column 0, line 0
    lcd.print("Humid.: "); //change the qouted text if you like to display something else
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0, 1); //set the cursor to column 0, line 1
    lcd.print("Temp.: "); //change the qouted text if you like to display something else
    lcd.print(t);
    lcd.print(" C");
  }
}
