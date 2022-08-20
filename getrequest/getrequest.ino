#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include "Code.h";

const int trigPin = 12;
const int echoPin = 14;
ESP8266WebServer server(80);
const char* ssid = "Bhavani";
const char* passwd = "bhavani1234";

#define SOUND_VELOCITY 0.034


long duration;
float distanceCm;
float distanceInch;


void handle(){
  server.send(200, "text/html", Code);
}

String readDistance(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
   
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculate the distance
    distanceCm = duration * SOUND_VELOCITY/2;
    Serial.print("Distance (cm): ");
    Serial.println(distanceCm);

    return String(distanceCm);
}

void value(){   
   server.send(200, "text/plain", readDistance());
}



void setup(){
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
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
  server.on("/getvalue", value);
  server.begin();
}


void loop(){
  server.handleClient(); 
  delay(1000);
}
