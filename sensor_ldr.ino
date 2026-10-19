int portaled = 10;
int portaLDR = A0;

void setup() {
  Serial.begin(9600);
  pinMode(portaled, OUTPUT);
}

void loop() {
  int estado = analogRead(portaLDR);
  Serial.print("Valor lido no LDR: ");
  Serial.println(estado);

  if (estado > 800) {
    digitalWrite(portaled, HIGH);
  } else {
    digitalWrite(portaled, LOW);
  }
  delay(500);
}
