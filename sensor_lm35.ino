int temperaturePin = A0;
float soma = 0;
float temp = 0;

float getVoltage(int pin) {
  return (analogRead(pin) * 0.004882814); 
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  soma = 0;
  for (int i = 1; i <= 1000; i++) {
    float temperature = getVoltage(temperaturePin);
    temperature = temperature * 100.0;
    soma += temperature;
  }
  temp = soma / 1000.0; // Calcula a média de 1000 leituras para eliminar ruído

  Serial.print("Temperatura LM35: ");
  Serial.print(temp);
  Serial.println(" *C");

  delay(1000);
}
