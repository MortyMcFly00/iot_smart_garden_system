#include <Arduino.h>

#define RELAY_#include <Arduino.h>

#define RELAY_PIN 4

void setup() {
    pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
    digitalWrite(RELAY_PIN, HIGH);
    delay(1000);
    digitalWrite(RELAY_PIN, LOW);
    delay(1000);
}
