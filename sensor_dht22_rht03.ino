#include "DHT.h"

#define DHT22_PIN 5
#define DHTTYPE DHT22

DHT dht(DHT22_PIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("A iniciar leitura do DHT22/RHT03...");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Erro na leitura do DHT22");
  } else {
    Serial.print("Humidade: ");
    Serial.print(h, 1);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t, 1);
    Serial.println(" *C");
  }
  delay(1000);
}
