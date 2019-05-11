#include "Wire.h"
#include "Adafruit_BMP085.h"
//#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 1     
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE); 
Adafruit_BMP085 bmp;
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance
 
void setup() {
  Serial.begin(9600);
  bmp.begin(); 
   dht.begin(); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  //lcd.begin(16, 2);
}
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.println(" *C");  
 
 
 
  
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 Serial.println("-1");
 digitalWrite(LEDPin, HIGH); 
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 Serial.println(distance);
 digitalWrite(LEDPin, LOW); 
 }
 
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");
 
    Serial.println();
    delay(500);
}
