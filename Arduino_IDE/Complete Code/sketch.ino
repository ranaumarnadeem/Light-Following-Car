// LDR Input Pins
const int LDR_LEFT = 4;
const int LDR_CENTER = 3;
const int LDR_RIGHT = 2;

// Motor Driver Pins
const int ENA = 5;
const int ENB = 6;
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

// Ultrasonic Sensor Pins
const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

// Thresholds
const int LIGHT_THRESHOLD = 600; 
const int OBSTACLE_DISTANCE = 20; 

void setup() {
 
  Serial.begin(9600);


  pinMode(LDR_LEFT, INPUT);
  pinMode(LDR_CENTER, INPUT);
  pinMode(LDR_RIGHT, INPUT);


  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);


  stopMotors();
}

void loop() {
  long distance = getDistance();

  if (distance < OBSTACLE_DISTANCE) {
    // Obstacle detected
    stopMotors();
    delay(500);

    // Try turning left
    turnLeft();
    delay(500);
    if (getDistance() > OBSTACLE_DISTANCE) {
      // Left is clear
      moveForward();
      return;
    }

    // Try turning right
    turnRight();
    delay(500);
    if (getDistance() > OBSTACLE_DISTANCE) {
      // Right is clear
      moveForward();
      return;
    }

    // If still blocked
    stopMotors();
    return;
  }


  int left = analogRead(LDR_LEFT);
  int center = analogRead(LDR_CENTER);
  int right = analogRead(LDR_RIGHT);


  if (left > LIGHT_THRESHOLD && center > LIGHT_THRESHOLD && right > LIGHT_THRESHOLD) {
    stopMotors();
  }
  else if (left > LIGHT_THRESHOLD || (left > LIGHT_THRESHOLD && center > LIGHT_THRESHOLD)) {
    turnLeft();
  }
  else if (right > LIGHT_THRESHOLD || (right > LIGHT_THRESHOLD && center > LIGHT_THRESHOLD)) {
    turnRight();
  }
  else if (center > LIGHT_THRESHOLD && left <= LIGHT_THRESHOLD && right <= LIGHT_THRESHOLD) {
    moveForward();
  }
  else {
    stopMotors();
  }
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void moveForward() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 200);
  analogWrite(ENB, 150);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
