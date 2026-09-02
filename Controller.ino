int emgpin = A0;
int emgValue = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
   emgValue = analogRead(emgpin);
   Serial.println(emgValue);
   delay(100);
}
