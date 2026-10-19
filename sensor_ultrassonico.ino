#define trigPin 13
#define echoPin 12
#define ledRed 8
#define ledBlue 7

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

void loop() {
  float duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2.0) / 29.1;

  if (distance >= 200 || distance <= 0) {
    Serial.println("Nada ao alcance!");
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledBlue, LOW);
  } else {
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(ledRed, LOW);
    digitalWrite(ledBlue, HIGH);
  }
  delay(500);
}
