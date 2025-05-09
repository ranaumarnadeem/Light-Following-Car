# Arduino_IDE

This repository contains a set of Arduino sketches used for testing and simulating individual components as well as the complete integrated system. The code is tested both on real hardware (Arduino Uno) and simulated on [Wokwi](https://wokwi.com).

## 📁 Folder Structure

- `Ultrasonic_Sensor_Test/`  
  Contains an Arduino sketch for testing an ultrasonic distance sensor (e.g., HC-SR04). It measures distance and prints results via the Serial Monitor.

- `LDRs_Test/`  
  Includes code to test Light Dependent Resistors (LDRs) and read analog light intensity values.

- `Motor_Driver_Test/`  
  Contains a test sketch for controlling 4 motors via an L298N motor driver module. Motors move forward, left, right, and backward for 2 seconds each.

- `Complete_Code/`  
  Holds the fully integrated Arduino sketch combining all components. This is the final version tested on both hardware and in simulation.
  
  - **Wokwi Simulation:**  
    You can simulate the entire setup using the following Wokwi project link:  
    👉 [Open in Wokwi](https://wokwi.com/projects/428279979034983425)

## 🛠 Hardware Used

- Arduino Uno (For simulation purpose)
- L298N Motor Driver
- 4 DC Motors (2 per side, in parallel)
- HC-SR04 Ultrasonic Sensor
- 2x LDRs
- Resistors and jumper wires
- Breadboard (optional)

## ✅ Purpose

-This folder is only meant for testing individual modules before final integration. Useful for prototyping autonomous vehicle logic and basic sensor-controlled robotics rapidly.
- Check other folder for Atmega328P code and details.

---

Feel free to fork or clone this repo and use it as a starter for your own robotics experiments.
