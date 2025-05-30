#include <Arduino.h>

#define SOIL_PIN 34 // GPI034 (AOUT from sensor)
#define RELAY_PIN 4 // Pump relay pin
#define DRY_THRESHOLD 2400 // Moisture value below this triggers pump.
#define WATERING_TIME_MS 20000 // Pump runtime = 20 seconds
#define COOLDOWN_MS 1800000

bool watering = false;
unsigned long pumpStartTime = 0;
unsigned long lastCheckTime = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Soil Sensor Starting...");
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensures pump is off when started.
  Serial.println("Smart Garden Control Initialized");

  lastCheckTime = millis() - COOLDOWN_MS;

}

void loop() {
  unsigned long currentTime = millis(); // Wait for cooldown period before watering again.
  int moisture = analogRead(SOIL_PIN);
  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  if (!watering && currentTime - lastCheckTime >= COOLDOWN_MS) {
    if (moisture > DRY_THRESHOLD) {
      Serial.println("Soil dry. Starting watering cycle...");
      digitalWrite(RELAY_PIN, HIGH);
      pumpStartTime = currentTime;
      watering = true;
    }
    else {
      Serial.println("Soil is moist. No watering needed.");
      lastCheckTime = currentTime;
    }
  }

  if (watering && currentTime - pumpStartTime >= WATERING_TIME_MS) {
    Serial.println("Watering complete. Stopping pump.");
    digitalWrite(RELAY_PIN, LOW);
    watering = false;
    lastCheckTime = currentTime;
  }
  delay(500);
}
