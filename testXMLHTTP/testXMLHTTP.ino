#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include "Code.h";


ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";


void handle(){
  server.send(200, "text/html", Code);
}


void led_control(){
   int state1 = server.arg("field1").toInt();
   int state2 = server.arg("field2").toInt();
   int state3 = server.arg("field3").toInt();
   digitalWrite(D0,state1);
   digitalWrite(D1,state2);
   digitalWrite(D2,state3);
   Serial.print("field1 = ");
   Serial.println(state1);
   Serial.print("field2 = ");
   Serial.println(state2);
   Serial.print("field3 = ");
   Serial.println(state3);
   server.send(200, "text/plane");
}

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, passwd);
  pinMode(D0,OUTPUT); 
  pinMode(D1,OUTPUT); 
  pinMode(D2,OUTPUT); 
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());
  server.on("/", handle);
  server.on("/led_set", led_control);
  server.begin();
}


void loop(){
  server.handleClient(); 
  delay(1000);
}
