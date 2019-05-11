#include <Bridge.h>
#include <HttpClient.h>
#include "Wire.h"
#include "Adafruit_BMP085.h"

#include "DHT.h"

#define DHTPIN 4     
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE); 
Adafruit_BMP085 bmp;


int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
  Serial.begin(9600);
   Bridge.begin();
  bmp.begin(); 
   dht.begin(); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);

}
 
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
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
    float pressione=bmp.readPressure();
    Serial.print(pressione);
    Serial.println("Pa");
  
   String indirizzo;
   
  indirizzo="http://192.168.0.103/rilevazioni3.php?Num_rilevazioni=11&temperatura="+String(t);
  indirizzo=indirizzo+"&umidita="+String(h);
  indirizzo=indirizzo+"&pressione="+String(pressione);
  indirizzo=indirizzo+"&distanza="+String(distance);
 Serial.println(indirizzo);
  HttpClient client;
  client.get(indirizzo);
    Serial.println();
    delay(500);
}
}
