#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "Code.h";


ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";

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

  server.on("/", server.send(200, "text/html", Code));
  server.begin();
}

void loop(){
  server.handleClient();
}
