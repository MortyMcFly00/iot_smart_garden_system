# Day 4 – Full System Test and Pump Activation

## Date
May 10, 2025

---

## Objectives
- Run full closed-loop test of smart garden MVP system
- Verify soil moisture readings trigger relay at correct threshold
- Confirm 120V AC pump activation via relay and pressure loop
- Observe system behavior for timing accuracy and stability
- Begin planning permanent enclosure and serial input controls

---

## Actions Taken
- Moisture threshold logic confirmed working (>2400 triggers pump)
- Full pump test executed: relay toggled, pump activated for 20 seconds
- Increased watering time from 10s to 20s to compensate for hose layout:
  - Half-inch tubing feeds into diverter
  - Two 1/4" lines split from diverter, requiring initial pressure buildup
- Verified safe relay activation with GPIO4 disconnected during boot
- Identified minor leak at diverter—will address in enclosure phase

---

## System Behavior
- Startup messages displayed correctly:
  - “Soil Sensor Starting...”
  - “Smart Garden Control Initialized”
- Moisture readings streamed live to serial monitor
- System transitioned to watering mode as expected
- Pump shut off automatically after watering duration

---

## Planned Improvements
- Design and build full enclosure to house:
  - ESP32
  - Breadboard
  - All 3 relays (moisture, grow light, humidifier)
- Add serial-based control input to replace manual board reset
- Implement “start” trigger via serial monitor as interim controller
- Replace diverter or reseal fittings to eliminate water leak

---

## Next Steps (Day 5)
- Build enclosure mockup and mounting layout
- Wire second and third relay (grow light + humidifier placeholders)
- Design serial command parser (e.g. `start`, `status`, `reset`)
- Prepare for handheld controller integration