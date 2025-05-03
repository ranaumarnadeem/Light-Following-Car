const int ldrPin = 2;  

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(ldrPin) == HIGH) {
    Serial.println("No Light Detected");
  } else {
    Serial.println("Light Detected");
  }

  delay(500);
}
