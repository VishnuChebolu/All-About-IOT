#include <ESP8266WiFi.h>
#include <ESP8266Webhook.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <ThingSpeak.h>
#include "Code.h";

#define PIN1 D0
#define PIN2 D1
#define PIN3 D2
#define PIN4 D3
#define PIN5 D4
#define PIN6 D5
#define PIN7 D6

#define EVENT "SwitchedOn" 


ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";

unsigned long channel =1526741;

WiFiClient  client;

void handle(){
  server.send(200, "text/html", Code);
}



void setup(){
  Serial.begin(115200);

  pinMode(PIN1,OUTPUT); 
  pinMode(PIN2,OUTPUT); 
  pinMode(PIN3,OUTPUT); 
  pinMode(PIN4,OUTPUT); 
  pinMode(PIN5,OUTPUT); 
  pinMode(PIN6,OUTPUT);
  pinMode(PIN7,OUTPUT); 

  
  
  WiFi.begin(ssid, passwd);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());

  
  if (!MDNS.begin("esp8266")) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }

  Serial.println("mDNS responder started");

  server.on("/", handle);
  server.begin();
  MDNS.addService("http", "tcp", 80);

  ThingSpeak.begin(client);
}

void loop(){
  MDNS.update();
  server.handleClient();
  int led_1 = ThingSpeak.readFloatField(channel, 1);
  int led_2 = ThingSpeak.readFloatField(channel, 2);
  int led_3 = ThingSpeak.readFloatField(channel, 3);
  int led_4 = ThingSpeak.readFloatField(channel, 4);
  int led_5 = ThingSpeak.readFloatField(channel, 5);
  int led_6 = ThingSpeak.readFloatField(channel, 6);
  int led_7 = ThingSpeak.readFloatField(channel, 7);
 
 
  if(led_1 == 1){
    digitalWrite(PIN1, HIGH);
    Serial.println("D1 is On..!");
  }
  else if(led_1 == 0){
    digitalWrite(PIN1, LOW);
    Serial.println("D1 is Off..!");
  }
 
  if(led_2 == 1){
    digitalWrite(PIN2, HIGH);
    Serial.println("D2 is On..!");
  }
  else if(led_2 == 0){
    digitalWrite(PIN2, LOW);
    Serial.println("D2 is Off..!");
  }

  if(led_3 == 1){
    digitalWrite(PIN3, HIGH);
    Serial.println("D3 is On..!");
  }
  else if(led_3 == 0){
    digitalWrite(PIN3, LOW);
    Serial.println("D3 is Off..!");
  }

  if(led_4 == 1){
    digitalWrite(PIN4, HIGH);
    Serial.println("D4 is On..!");
  }
  else if(led_4 == 0){
    digitalWrite(PIN4, LOW);
    Serial.println("D4 is Off..!");
  }

  if(led_5 == 1){
    digitalWrite(PIN5, HIGH);
    Serial.println("D5 is On..!");
  }
  else if(led_5 == 0){
    digitalWrite(PIN5, LOW);
    Serial.println("D5 is Off..!");
  }

  if(led_6 == 1){
    digitalWrite(PIN6, HIGH);
    Serial.println("D6 is On..!");
  }
  else if(led_6 == 0){
    digitalWrite(PIN6, LOW);
    Serial.println("D6 is Off..!");
  }

  if(led_7 == 1){
    digitalWrite(PIN7, HIGH);
    Serial.println("D7 is On..!");
  }
  else if(led_7 == 0){
    digitalWrite(PIN7, LOW);
    Serial.println("D7 is Off..!");
  }
  Serial.println(WiFi.localIP());
  delay(1000);
}
