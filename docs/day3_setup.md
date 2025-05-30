# Day 3 – Soil Sensor Integration and Control Logic Design

## Date
May 9, 2025

---

## Objectives
- Wire and test capacitive soil moisture sensor
- Read analog moisture data using GPIO34
- Establish dry soil baseline for calibration
- Develop pump control logic using moisture threshold and timed activation
- Delay pump upload pending safe wiring

---

## Hardware Used
- Capacitive Soil Moisture Sensor v1.2
- ESP32 Dev Board (30-pin)
- GPIO34 (analog read)
- GPIO4 (relay control pin, currently disconnected)
- 3.3V power supply from ESP32

---

## Test Results
- **Dry soil reading**: ~2590
- Sensor responded consistently to air/dry conditions
- Analog values stable across multiple reads
- Confirmed GPIO34 reads properly on ESP32

---

## Pump Control Logic
Created smart watering loop that:
- Triggers when moisture falls below 2400
- Activates relay for 10 seconds
- Locks out further watering for 30 minutes
- Uses `millis()` for non-blocking timing

### Code Summary:
```cpp
if (moisture < DRY_THRESHOLD && !watering) {
    // Turn pump on
}

if (watering && millis() - pumpStartTime >= WATER_TIME_MS) {
    // Turn pump off
}