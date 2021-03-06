//Stazione Meteo con Arduino 12/2013
//Ivan Scordato e Giovanni Lorenzini

//dichiaro il pin di entrata del sensore di luminosità in una variabile
int pinfotoresistenza = A0;

//includo la libreria del sensore DHT22 di temperatura e umidità e dichiaro a che pin è collegato
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//includo le librerie wire e del sensore di temperatura e pressione BMP085
#include "Wire.h"
#include "Adafruit_BMP085.h"
Adafruit_BMP085 bmp;
//scl--> A5 sda-->A4

//dichiaro in due variabili i pin del sensore ad ultrasuoni HC-SR04 per misurare l'altezza della neve
const int TRIG_PIN = 5;
const int ECHO_PIN = 6;

//includo le librerie della ethernet shield
#include <SPI.h>
#include <Ethernet.h>

//variabili per collegarsi a internet
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

IPAddress ip(192,168,50,100); //indirizzo IP disponibile sulla rete

IPAddress myDns(192,168,1,1); //tuo DNS

char server[] = "www.fabbricaopensource.altervista.org";

EthernetClient client;

unsigned long lastConnectionTime = 0; //l'ultima volta che ti sei connesso al server in millisecondi
boolean lastConnected = false;    
const unsigned long postingInterval = 60L*1000L; //la L è necessaria per usare i numeri di tipo long

//dichiaro la stringa dove scrivo i dati per caricarli sul web
String strURL = "";

void setup()
{
  //inizializzo i sensori sensori
  dht.begin(); //inizializzo il sensore di umidità
  bmp.begin(); //inizializzo il sensore di pressione
  pinMode(TRIG_PIN, OUTPUT); //dichiaro come output il pin trig
  pinMode(ECHO_PIN, INPUT); //dichiaro come input il pin echo

  Serial.begin(9600); //stabilisco una connessione con il pc

  delay(1000); //attendo un secondo

  Ethernet.begin(mac, ip, myDns);

  //invio al pc il mio IP
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());

}

void loop()
{ 

  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected() && lastConnected) {
    Serial.println();
    Serial.println("Disconnessione...");
    client.stop();
  }

  if(!client.connected() && (millis() - lastConnectionTime > postingInterval)) {
    aggiornoDati(); //carico i dati sul server
  }

  lastConnected = client.connected();

}

//calcolo il punto di rugiada
double puntoDiRugiada(double temperatura, double umidita)
{
  double a = 17.271;
  double b = 237.7;
  double temp = (a * temperatura) / (b + temperatura) + log(umidita/100);
  double Td = (b * temp) / (a - temp);
  return Td;
}

void aggiornoDati() //carico i dati sul server
{
  //leggo la luminosità dal pin analogico A0
  int luminosita = map(analogRead(pinfotoresistenza), 0, 1023, 0, 100); //eseguo un procedimento che riduce il range da 0-1023 a 0-100 per esprimere la luminosità in percentuale

  //leggo l'umidità e la scrivo in una variabile
  float umidita = dht.readHumidity();

  //leggo la pressione e la scrivo in una variabile
  float pressione = bmp.readPressure();

  //leggo la temperatura da due sensori, faccio la media e la scrivo in una variabile
  float temperatura = (bmp.readTemperature() + dht.readTemperature());
  temperatura = (temperatura / 2.0);

  //misuro l'altezza della neve
  float neve, durata; //dichiaro la variabile neve e la variabile durata
  float cmPerMicrosecondi = 0.0331 + ( 0.000062 * temperatura); //calcolo i cm/ms del suono in base alla temperatura
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10); //faccio un impulso di dieci microsecondi sul pin trig
  digitalWrite(TRIG_PIN, LOW);
  durata = pulseIn(ECHO_PIN,HIGH); //mi metto in ascolto sul pin eco e calcolo la durata dell'impulso
  neve = (durata*cmPerMicrosecondi/2.0); //calcolo la distanza con la formula durata*(cm/ms)/2, diviso due perchè il suo va, rimbalza contro un oggetto e ritorna, quindi compie due volte il tragitto
  float menoNeve = 200.0 - neve;

  if (client.connect(server, 80))
  {
    Serial.println("Connessione...");

    //creo l'url utilizzando una stringa
    strURL ="GET  /meteo/salva.php?temp=";
    strURL+=temperatura;
    strURL+="&umi=";
    strURL+=umidita;
    strURL+="&pres=";
    strURL+=pressione;
    strURL+="&lum=";
    strURL+=luminosita;
    strURL+="&neve=";
    strURL+=menoNeve;
    strURL+="&rug=";
    strURL+=puntoDiRugiada(temperatura, umidita);
    strURL+=" HTTP/1.1";

    //invio la richiesta al server
    client.println(strURL);
    client.println("Host: www.fabbricaopensource.altervista.org");
    client.println("User-Agent: arduino-ethernet");
    client.println("Connection: close");
    client.println();

    lastConnectionTime = millis();

    delay(1000);
    Serial.println(strURL);
  }
  else
  {
    Serial.println("Errore Connessione");
    Serial.println("Disconnessione...");
    client.stop();
  }
}

