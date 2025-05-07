# Day 1 – Smart Garden ESP32 Setup

## Date
May 6, 2025

---

## Objectives
- Set up a stable PlatformIO development environment on Linux
- Mount and secure ESP32 hardware
- Flash blink test to verify USB and GPIO
- Control 3.3V relay using GPIO4
- Begin GitHub repo integration

---

## Hardware Used
- ESP32-WROOM-32 Dev Board (30-pin, CP2102)
- Anker USB-A to USB-C data cable
- 3.3V opto-isolated relay module
- Plastic cutting board base
- Wood standoffs for board clearance
- Linux laptop running Ubuntu 22.04

---

## Setup Process
- Installed VS Code and PlatformIO IDE
- Resolved backend stall with manual `.platformio` reset
- Installed PlatformIO CLI using pip after failed apt attempt
- Mounted board to cutting board, raised on wood blocks
- Verified USB connection at `/dev/ttyUSB0`
- Confirmed board power and boot with onboard LED

---

## Code + Wiring
- GPIO2 used for initial LED blink
- Relay wired to GPIO4, 3.3V, and GND
- Relay toggled every 1 second using test sketch:
  ```cpp
  #include <Arduino.h>
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
