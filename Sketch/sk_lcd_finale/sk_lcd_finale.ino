#include <Wire.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //definisce i pin dell'LCD
int led = 13,i=2;
unsigned long SendTime = 0;
unsigned long S=0;
bool LED=true;
void setup() { 
  lcd.begin(16, 2);
  lcd.print("Stazione Meteo!");
  pinMode(led, OUTPUT); //lampeggio led della scheda oppure un led collegato al pin 13
  lcd.setCursor(0, 1);
  lcd.print("T: : :");
}
void blink_led() { //sottoprogramma per la gestione del led
  if (millis() > SendTime + 1000) {
    SendTime = millis();
    if (LED==true) {
      LED=false;
      digitalWrite(led, HIGH); 
    }
    else {
      LED=true;
      digitalWrite(led, LOW);
    }
  } 
}
 
void hms() { //converte il valore numerico di time in h m s
              //sottoprogramma per la gestione del timer

  unsigned long int t=millis()/1000;
  unsigned short int h,m,s;
  if (t >= 3600) { //stampa ore 
    h=millis()/3600000;
    if (h<10) {
      lcd.setCursor(3,1);
      lcd.print(h);
      lcd.setCursor(2,1); 
      lcd.print("0");
    }
    else {
      lcd.setCursor(2,1);
      lcd.print(h);
    }
  }
  else {
    h=0;
    lcd.setCursor(2,1);
    lcd.print("00");
  }
  if (t >= 60) { //stampa minuti
    m=millis()/60000-h*60;
    if (m<10) {
      lcd.setCursor(6,1);
      lcd.print(m);
      lcd.setCursor(5,1); 
      lcd.print("0");
    }
    else {
      lcd.setCursor(5,1);
      lcd.print(m);
    } 
  }
  else {
    m=0;
    lcd.setCursor(5,1);
    lcd.print("00");
  }

  if (t>0) { //stampa secondi
    s=millis()/1000-m*60-h*3600;
    if (s<10) {
      lcd.setCursor(9,1);
      lcd.print(s);
      lcd.setCursor(8,1); 
      lcd.print("0");
    }
    else {
      lcd.setCursor(8,1);
      lcd.print(s); 
    }
  } 
  else {
    s=0;
    lcd.setCursor(8,1);
    lcd.print("00");
  } 
}
 
void puntini() {  //sottoprogramma per la gestione dello scorrimento dei puntini
  if (millis()> S + 249) {
    S = millis();
    if (i>4) { 
      i=1; 
      lcd.setCursor(10+i,1); // lcd.setCursor(17-i,1); puntini al rovescio
      lcd.print(" "); 
    }
    lcd.setCursor(11+i,1); // lcd.setCursor(16-i,1);
    lcd.print("."); 
    lcd.setCursor(10+i,1); // lcd.setCursor(17-i,1);
    lcd.print(" ");
    i++;
  }
}
void loop() { //programma principale
  puntini();  //richiamo le varie funzioni precedenti
  blink_led(); 
  hms();
}
