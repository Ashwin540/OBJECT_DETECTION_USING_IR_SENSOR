# OBJECT_DETECTION_USING_IR_SENSOR

# IR Sensor with LED and Buzzer using ESP32

This project demonstrates how to use an **IR sensor** with an **ESP32** board to detect the presence of an object. When the IR sensor detects an object (digital LOW signal), an **LED** and a **buzzer** are activated.

## 🛠️ Components Required

- ESP32 development board  
- IR Sensor (Digital output type)  
- LED  
- Buzzer  
- Resistors (e.g., 220Ω for LED)  
- Jumper wires  
- Breadboard  

## ⚡ Circuit Connections

| Component | ESP32 Pin |
|----------|-----------|
| IR Sensor OUT | GPIO 13 |
| LED (+ve)     | GPIO 14 |
| Buzzer (+ve)  | GPIO 27 |
| GNDs of all components | GND |
| VCC (IR, LED, Buzzer) | 3.3V/5V depending on component |

> ⚠️ Use current limiting resistor for LED. Make sure your buzzer and IR sensor are within ESP32’s voltage limits.

## 🧠 Working Principle

- **IR Sensor** gives a **LOW signal (0)** when an object is detected in front of it.
- ESP32 reads the signal from the IR sensor.
- If an object is detected (`val == 0`):
  - LED turns **ON**
  - Buzzer turns **ON**
- Otherwise:
  - LED and Buzzer remain **OFF**

## 💻 Code

```cpp
#define IRPIN 13    // D0 of IR sensor
#define LEDPIN 14   // LED connected to GPIO14
#define buzzer 27   // Buzzer connected to GPIO27

void setup() {
  Serial.begin(115200);
  pinMode(IRPIN, INPUT);     // IR sensor input
  pinMode(LEDPIN, OUTPUT);   // LED output
  pinMode(buzzer, OUTPUT);   // Buzzer output
  delay(1000);
}

void loop() {
  int val = digitalRead(IRPIN);  // Read IR sensor value

  Serial.print("IR Sensor Value: ");
  Serial.println(val);  // 0 = Object detected, 1 = No object

  if (val == 0) {
    digitalWrite(LEDPIN, HIGH); 
    digitalWrite(buzzer, HIGH); 
  } else {
    digitalWrite(LEDPIN, LOW); 
    digitalWrite(buzzer, LOW);  
  }

  delay(100);  // Short delay for stability
}

📸 Output
When the IR sensor detects an object:

LED glows

Buzzer makes sound

When no object is detected:

LED and Buzzer are OFF

✅ Applications
Obstacle detection for robots

Automatic door entry systems

Object counter systems

Made with ❤️ by Ashwin Sampathkumar
