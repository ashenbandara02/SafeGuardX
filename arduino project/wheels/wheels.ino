const int trigPin = 3;
const int echoPin = 2;

const int trigPin2 = 5;
const int echoPin2 = 4;

const int trigPin3 = 7;
const int echoPin3 = 6;

const int trigPin4 = 8;
const int echoPin4 = 9;

const int maxDistance = 5;

// Piezo buzzer configuration
const int piezoPin = 10;

// Headlight Configuration
/// Headlight 1
const int headLight1 = 11;


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

  // Headlights
  /// Headlight 1
  pinMode(headLight1, INPUT_PULLUP);

}

void sendSMS()
{
  // Funtion To send Sms
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

  if (distance > maxDistance) {
    Serial.println("Wheel 1 Was Removed");
  }else{
    Serial.println("Wheel 1 is in place");
  }

  delay(1000);

  // Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  long duration2 = pulseIn(echoPin2, HIGH);
  int distance2 = duration2 * 0.0343 / 2;

  if (distance2 > maxDistance) {
    Serial.println("Wheel 2 Was Removed");
  }else{
    Serial.println("Wheel 2 is in place");
  }

  // Sensor 3
  delay(1000);

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  long duration3 = pulseIn(echoPin3, HIGH);
  int distance3 = duration3 * 0.0343 / 2;

  if (distance3 > maxDistance) {
    Serial.println("Wheel 3 Was Removed");
  }else{
    Serial.println("Wheel 3 is in place");
  }

  delay(1000);

  //Sensor 4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

  long duration4 = pulseIn(echoPin4, HIGH);
  int distance4 = duration4 * 0.0343 / 2;
  
  Serial.println(distance4);
  if (distance4 > maxDistance) {
    Serial.println("Wheel 4 Was Removed");
  }else{
    Serial.println("Wheel 4 is in place");
  }

  delay(1000);

  /// Headlights 
  // Headlight 1
  int pinState = digitalRead(headLight1);
  
  // Check if the wire is removed (pin reads HIGH)
  if (pinState == HIGH) {
    Serial.println("Headlight 1 Removed");
    digitalWrite(piezoPin, HIGH);
  } else {
    Serial.println("Headlight 1 Present");
    digitalWrite(piezoPin, LOW);
  }


}
