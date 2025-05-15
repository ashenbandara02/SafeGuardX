const int trigPin = 3;
const int echoPin = 2;

const int trigPin2 = 4;
const int echoPin2 = 5;

const int trigPin3 = 7;
const int echoPin3 = 6;

const int trigPin4 = 8;
const int echoPin4 = 9;

const int maxDistance = 5;

// Piezo buzzer configuration
const int piezoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // for sensor2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // for sensor3
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // for sensor4
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  // for the piezo buzzer
  pinMode(piezoPin, OUTPUT);
}

void loop() {

  // Sensor 1

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;

  if (distance > maxDistance || distance <= 0) {
    Serial.println("Wheel 1 Was Removed");
    digitalWrite(piezoPin, HIGH);
  }else{
    Serial.println("Wheel 1 is in place");
    digitalWrite(piezoPin, LOW);
  }

  // Sensor 2

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 * 0.0343 / 2;

  if (distance2 > maxDistance || distance2 <= 0) {
    Serial.println("Wheel 2 Was Removed");
  }else{
    Serial.println("Wheel 2 is in place");
  }

  // Sensor 3

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  long duration3 = pulseIn(echoPin3, HIGH);
  int distance3 = duration3 * 0.0343 / 2;

  if (distance3 > maxDistance || distance3 <= 0) {
    Serial.println("Wheel 3 Was Removed");
  }else{
    Serial.println("Wheel 3 is in place");
  }

  // Sensor 4

  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

  long duration4 = pulseIn(echoPin4, HIGH);
  int distance4 = duration4 * 0.0343 / 2;

  if (distance4 > maxDistance || distance4 <= 0) {
    Serial.println("Wheel 4 Was Removed");
  }else{
    Serial.println("Wheel 4 is in place");
  }

  delay(500);

}
