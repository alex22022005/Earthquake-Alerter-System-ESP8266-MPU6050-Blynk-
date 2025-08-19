# 🌍 Earthquake Alerter System (ESP8266 + MPU6050 + Blynk)

An **IoT-enabled earthquake detection & alert system** built using **ESP8266 (NodeMCU), MPU6050 (Accelerometer + Gyroscope)**, **LCD Display**, and **Blynk Cloud**.  
The system detects unusual **vibrations & rotations** (simulating earthquake detection or intrusion detection) and sends alerts via **Blynk notifications** while triggering buzzer and LED alarms.

---

## 📌 Features
- 📡 **Real-time motion detection** using **MPU6050** accelerometer & gyroscope.  
- 📟 **16x2 LCD Display (I2C)** for instant alerts and system status.  
- 🚨 **Buzzer + LED** alarms on abnormal activity.  
- 📲 **Blynk IoT Integration** → Push notifications & monitoring.  
- 🌐 **WiFi-enabled (ESP8266)** for remote alerts.  

---

## 🛠 Components Used
| Component              | Quantity |
|------------------------|----------|
| ESP8266 NodeMCU        | 1        |
| MPU6050 Sensor         | 1        |
| 16x2 LCD (I2C module)  | 1        |
| Buzzer                 | 1        |
| LED                    | 1        |
| Jumper Wires           | As needed |
| Breadboard             | 1        |
| Power Supply (5V/USB)  | 1        |

---

## 📜 Arduino Code
The project reads MPU6050 sensor values (acceleration + rotation), detects abnormal thresholds, and notifies via Blynk, LCD, buzzer, and LED.  

📂 The full Arduino code is available in [`earthquake_alerter.ino`](https://github.com/alex22022005/Earthquake-Alerter-System-ESP8266-MPU6050-Blynk-.git).  

Key functions:
- Read acceleration & rotation from MPU6050.
- Calculate magnitude values.
- Compare against thresholds.
- Trigger alerts (LCD + Buzzer + LED).
- Send **Blynk log events/notifications**.

---

## 🔌 Pin Configuration
| Component             | ESP8266 Pin |
|----------------------|-------------|
| MPU6050 SDA          | D2          |
| MPU6050 SCL          | D1          |
| LCD I2C (SDA/SCL)    | D2 / D1     |
| Buzzer               | D5          |
| LED                  | D6          |

---

## 🚀 Getting Started
1. Install **Arduino IDE** (with ESP8266 core).  
2. Install the following libraries:  
   - `Wire.h`  
   - `MPU6050.h`  
   - `LiquidCrystal_I2C.h`  
   - `ESP8266WiFi.h`  
   - `BlynkSimpleEsp8266.h`  
3. Open the provided code and replace your WiFi **SSID/Password** and **Blynk Auth Token**:
4. Upload code to ESP8266.  
5. Open Serial Monitor (9600 baud) for raw data.  
6. On significant motion detection →  
- LCD shows **ALERT**  
- LED & Buzzer activate  
- Blynk sends **notifications**  

---

## 📲 Blynk Setup
- Create a new project in Blynk IoT.  
- Add event notification named `buglar`.  
- Grab the **Auth Token** and replace it in the code.  
- Use Virtual Pins (V0, V1, V2 if required for additional sensors).  

---

## 📌 Applications
- 🏠 **Home Security** – Detect unusual vibrations (e.g., intrusion through walls/doors).  
- 🌍 **Earthquake Early Warning Simulation**.  
- 🏗️ **Structural Health Monitoring** (bridge, building vibrations).  

---

## 📄 License
This project is licensed under the **MIT License** – free to use, modify, and distribute.  

---

## ✨ Author
Developed by **Antony Alex**  
🌐 GitHub: [alex22022005](https://github.com/alex22022005)  
🚀 IoT | Embedded Systems | Smart Automation  

---
