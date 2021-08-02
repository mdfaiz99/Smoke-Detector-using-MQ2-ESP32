#include "MQ2.h"
#include "DHT.h"
#include "WiFi.h"
#include "WiFiClient.h"
#include "ThingSpeak.h"
#include "BlynkSimpleEsp32.h"
#define BLYNK_PRINT Serial
#define DHTPIN 13
#define DHTTYPE DHT11

// Initialize Blynk app
char auth[] = "";

// Initialize WiFi
char ssid[] = "";
char password[] = "";
unsigned long myChannelId = ;
const char* myWriteAPIKey = "";
const char* myReadAPIKey = "";

// Declare
DHT dht(DHTPIN, DHTTYPE);
const int buzzer = 12;
const int mq2 = 34;
const int red = 33;
const int green = 32;
int s = 0;
boolean state;

BlynkTimer timer;
WiFiClient client;

void setup() {
  Serial.begin(115200);
 
  // Setting
  pinMode(mq2, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(buzzer, LOW);
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  dht.begin();
  
  // Connect WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
  }
  Serial.print("Connected to the WiFi network");
  Serial.println();

  // Connect Blynk
  Blynk.begin(auth, ssid, password);

  // Connect Thingspeak
  ThingSpeak.begin(client);
  timer.setInterval(1000L, sendUptime);
}

// Control LED using Blynk app
BLYNK_WRITE(V4){
  state = param.asInt();
  if (state == 1){
     digitalWrite(red, LOW);
     digitalWrite(green, HIGH);
  }
  else {
     digitalWrite(green, LOW);
     digitalWrite(red, HIGH);
  }
}

void sendUptime(){
  s = analogRead(mq2);
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 

  //Check if any reads failed and exit early to try again
  if(isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
  }

  // Update Thingspeak
  ThingSpeak.writeField(myChannelId, 1, s, myWriteAPIKey);
  ThingSpeak.writeField(myChannelId, 2, t, myWriteAPIKey);
  ThingSpeak.writeField(myChannelId, 3, h, myWriteAPIKey); 

  // Update Blynk app
  Blynk.virtualWrite(V1, s); 
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
  
  //Print out to serial
  Serial.println();
  Serial.print(F("Smoke value: "));
  Serial.print(s);
  Serial.print(F(" ppm | "));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C | "));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%"));
  Serial.println();
  
  if (s > 2400){
    Blynk.notify("Smoke Detected!");
    Serial.print(F("Smoke Detected!"));
    digitalWrite(buzzer, HIGH);
  }

  else{
    digitalWrite(buzzer, LOW);
  }
  
}

void loop() {
  Blynk.run();
  timer.run();
}
