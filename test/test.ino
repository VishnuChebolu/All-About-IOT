#define PIN1 D3
int pin;
uint8_t  pinnum[] = {D2,D3};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10000);
  String s = "PIN11";

  pin = s. substring(s. length() - 2).toInt();
  Serial.println(pinnum[pin-1]);
  pinMode(pinnum[pin-1], OUTPUT);
  pinMode(PIN1, OUTPUT);
  
}



void loop() {
  digitalWrite(pinnum[pin-1],HIGH);
  delay(1000);
  digitalWrite(PIN1,HIGH);
  delay(1000);
  Serial.println("Not working.");
}
