#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "Code.h";

ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";

void handle(){
  server.send(200, "text/html", Code);
}


void setup(){
  Serial.begin(115200);
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
 }
