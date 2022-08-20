#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Code.h";

#define PIN1 D0
#define PIN2 D1
#define PIN3 D2
#define PIN4 D3
#define PIN5 D4
#define PIN6 D5
#define PIN7 D6
#define PIN8 D7

ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";

void handle(){
  server.send(200, "text/html", Code);
}


void led_control() 
{
 String act_state = server.arg("state");
 if(act_state == "11")
 {
  digitalWrite(PIN1,HIGH); //LED ON
 }
 else if(act_state == "10")
 {
  digitalWrite(PIN1,LOW); //LED OFF
 }

 if(act_state == "21")
 {
  digitalWrite(PIN2,HIGH); //LED ON
 }
 else if(act_state == "20")
 {
  digitalWrite(PIN2,LOW); //LED OFF
 }
 if(act_state == "31")
 {
  digitalWrite(PIN3,HIGH); //LED ON
 }
 else if(act_state == "30")
 {
  digitalWrite(PIN3,LOW); //LED OFF
 }

 if(act_state == "41")
 {
  digitalWrite(PIN4,HIGH); //LED ON
 }
 else if(act_state == "40")
 {
  digitalWrite(PIN4,LOW); //LED OFF
 }if(act_state == "51")
 {
  digitalWrite(PIN5,HIGH); //LED ON
 }
 else if(act_state == "50")
 {
  digitalWrite(PIN5,LOW); //LED OFF
 }

 if(act_state == "61")
 {
  digitalWrite(PIN6,HIGH); //LED ON
 }
 else if(act_state == "60")
 {
  digitalWrite(PIN6,LOW); //LED OFF
 }if(act_state == "71")
 {
  digitalWrite(PIN7,HIGH); //LED ON
 }
 else if(act_state == "70")
 {
  digitalWrite(PIN7,LOW); //LED OFF
 }

 if(act_state == "81")
 {
  digitalWrite(PIN8,HIGH); //LED ON
 }
 else if(act_state == "80")
 {
  digitalWrite(PIN8,LOW); //LED OFF
 }
 
 server.send(200, "text/plane");
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
  pinMode(PIN8,OUTPUT); 
  
  
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
  server.on("/led_set", led_control);
  server.begin();
  MDNS.addService("http", "tcp", 80);
}

void loop(){
  MDNS.update();
  server.handleClient();
}
