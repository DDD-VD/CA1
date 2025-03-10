# Automatic Trash Can with Smart Lid Control 🗑️

A smart trash can project that automatically opens its lid when you approach it. Built with Arduino, this project combines IR sensing technology, servo motor control, and an LCD display to create a touchless waste disposal solution.

## Project Overview 📋

This project aims to create a hygienic and convenient trash can that:
- Opens automatically when you approach
- Shows real-time status on an LCD display
- Tracks usage statistics
- Saves power through efficient operation
- Provides a touchless experience

## Features ✨

### Core Functionality
- **Touchless Operation**: Opens automatically when hand is detected
- **Smart Display**: Shows current status and usage counter
- **Automatic Closing**: Closes after 2 seconds of no detection
- **Power Efficient**: Uses sleep mode when inactive
- **Usage Tracking**: Counts number of lid openings

### Technical Features
- IR sensor-based proximity detection
- Smooth servo motor control
- Two-line LCD display
- Power-saving sleep mode
- Battery-powered operation

## Hardware Components 🛠️

### Required Components
1. **Arduino Uno**
   - Main microcontroller
   - Handles all sensor inputs and outputs
   - Manages power consumption

2. **IR Proximity Sensor**
   - Detects hand presence
   - Provides reliable proximity sensing
   - Low power consumption

3. **Servo Motor**
   - Controls lid movement
   - Precise angle control
   - Smooth operation

4. **RGB LCD Display (16x2)**
   - Shows current status
   - Displays usage counter
   - I2C communication

5. **Power Supply**
   - Battery pack
   - Efficient power management
   - Long battery life

### Optional Components
- Breadboard for prototyping
- Jumper wires for connections
- Enclosure for protection

Arduino Uno Connections:

IR Sensor:
- VCC → Pin 8 (Power control)
- GND → GND
- OUT → Pin 4 (Signal input)

Servo Motor:
- VCC → 5V
- GND → GND
- Signal → Pin 7 (PWM control)

LCD Display:
- VCC → 5V
- GND → GND
- SDA → A4 (I2C Data)
- SCL → A5 (I2C Clock)
```

## Software Requirements 💻

### Required Libraries
```cpp
#include "LowPower.h"    // Power management
#include <Servo.h>       // Servo control
#include <rgb_lcd.h>     // LCD display
```

### Code Configuration
```cpp
#define cap_time 2      // Time before auto-close (seconds)
#define open_angle 10   // Lid open angle
#define close_angle 155 // Lid closed angle
```

## Installation Guide 📥

1. **Hardware Setup**
   - Connect components according to wiring diagram
   - Ensure all connections are secure
   - Check power supply connections

2. **Software Setup**
   - Install Arduino IDE
   - Install required libraries
   - Upload code to Arduino
   - Test functionality

## Operation Guide 📝

1. **Initial State**
   - Device starts in closed position
   - Display shows "Closed"
   - Counter at zero

2. **Normal Operation**
   - Place hand near IR sensor
   - Lid opens automatically
   - Display shows "Open"
   - Counter increases
   - Lid closes after 2 seconds

3. **Power Management**
   - Device enters sleep mode when inactive
   - Wakes up to check sensor
   - Optimizes battery life

## Troubleshooting 🔍

### Common Issues
1. **Lid Not Responding**
   - Check IR sensor connections
   - Verify power supply
   - Ensure servo is properly connected

2. **Display Issues**
   - Check I2C connections
   - Verify LCD address
   - Check power connections

3. **Power Problems**
   - Verify battery voltage
   - Check for shorts
   - Ensure proper power management

## Future Improvements 🔮

### Planned Features
- WiFi connectivity
- Mobile app integration
- Cloud data storage
- Advanced analytics
- Voice feedback
- Gesture controls

### Potential Enhancements
- Solar power option
- Multiple lid positions
- Customizable settings
- Remote monitoring
- Maintenance alerts

## Technical Specifications 📊

### Performance
- Response time: < 0.5 seconds
- Battery life: ~6 months
- Operating temperature: 0-40°C
- Detection range: 5-30cm

### Power Consumption
- Active mode: ~100mA
- Sleep mode: ~1mA
- Operating voltage: 5V

## Contributing 🤝

Feel free to contribute to this project:
1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## Project Status 📈

- [x] Basic functionality
- [x] Power management
- [x] Usage counter
- [ ] WiFi connectivity
- [ ] Mobile app integration
- [ ] Cloud data storage
