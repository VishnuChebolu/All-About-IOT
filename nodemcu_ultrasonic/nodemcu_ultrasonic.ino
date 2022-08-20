#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const int trigPin = 12;
const int echoPin = 14;
const char* ssid = "Bhavani";
const char* password = "bhavani1234";

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("..");
 
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Clears the trigPin
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
  

    WiFiClient client;
    HTTPClient http;  //Declare an object of class HTTPClient
    String url = "http://localhost:4444?id=nodemcu1&value="+String(distanceCm);
    Serial.println(url);
    http.begin(client,url);  //Specify request destination
    int httpCode = http.GET();                                  //Send the request
    String payload = http.getString();   //Get the request response payload
    Serial.println(payload);             //Print the response payload
    http.end();   //Close connection
 
  
 
  delay(30000); 
}
