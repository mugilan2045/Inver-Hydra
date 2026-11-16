# INVER HYDRA – INTELLIGENT DISTILLED WATER REPLENISHMENT FOR BATTERY LONGEVITY

### Project Overview

INVER HYDRA is an IoT-based intelligent system designed to automate the distilled-water refilling process in inverter batteries. The project aims to reduce the manual effort involved in checking and maintaining battery water levels while improving battery maintenance, reliability, and operational efficiency.

Traditional inverter battery maintenance requires users to periodically inspect electrolyte levels and manually refill distilled water. This process can be time-consuming and may lead to underfilling, overfilling, water wastage, and potential battery damage.

To overcome these limitations, INVER HYDRA uses an ESP32 microcontroller integrated with a dual-sensor monitoring mechanism consisting of a float switch and an ultrasonic sensor. The float switch detects the water level inside the battery compartment, while the ultrasonic sensor monitors the availability of distilled water in the supply reservoir.

When the battery water level becomes low and sufficient distilled water is available, the ESP32 activates a peristaltic pump through a relay module. The pump automatically transfers distilled water from the reservoir to the battery compartment. The system also integrates the Blynk IoT platform to provide real-time monitoring and mobile notifications through Wi-Fi connectivity.

## Project Objectives

- Develop an intelligent automatic distilled-water refilling system for inverter batteries.
- Monitor battery water levels using a float switch sensor.
- Monitor distilled-water availability in the reservoir using an ultrasonic sensor.
- Implement dual-sensor verification to improve refilling reliability.
- Control the water refilling process automatically using an ESP32 microcontroller.
- Operate a peristaltic pump through a relay module for controlled water delivery.
- Integrate Blynk IoT for real-time monitoring and mobile notifications.
- Prevent unnecessary pumping, overfilling, and pump dry-running conditions.
- Reduce manual battery maintenance and water wastage.

## Key Features

- **Automatic Water-Level Detection:** Detects low water levels inside the inverter battery compartment using a float switch.
- **Reservoir-Level Monitoring:** Uses an ultrasonic sensor to measure the availability of distilled water in the supply tank.
- **Dual-Sensor Verification:** Checks both the battery water requirement and reservoir water availability before starting the refilling process.
- **Automatic Water Refilling:** Controls a 9V peristaltic pump through a relay module to transfer distilled water.
- **Overfilling Prevention:** Automatically stops the pump when the float switch indicates that the required water level has been reached.
- **Dry-Run Protection:** Prevents pump operation when the reservoir contains insufficient distilled water.
- **IoT-Based Monitoring:** Uses the Blynk platform to display system status and water-level information remotely.
- **Instant Notifications:** Provides mobile alerts for events such as refilling started, low reservoir level, and refilling completed.
- **Expandable Architecture:** Supports future enhancements for multiple-battery monitoring and advanced battery maintenance.

## Input Components and Sensors

| Component | Description |
| --------- | ----------- |
| ESP32 | Main microcontroller for processing sensor inputs and controlling the system |
| Float Switch Sensor | Detects low and high water levels in the battery compartment |
| Ultrasonic Sensor | Measures the water level in the distilled-water reservoir |
| Wi-Fi Connectivity | Enables communication between ESP32 and the Blynk IoT platform |

## Output Components

| Component | Description |
| --------- | ----------- |
| Peristaltic Pump (9V) | Transfers distilled water from the reservoir to the battery compartment |
| Relay Module (5V/9V) | Controls the pump operation based on ESP32 signals |
| Blynk Mobile Application | Displays system information and provides notifications |
| Status Notifications | Reports refilling activity and low reservoir conditions |

## Hardware Requirements

- ESP32 Microcontroller
- Peristaltic Pump (9V)
- Float Switch Sensor
- Ultrasonic Sensor
- Relay Module (5V/9V)
- 9V Battery and Connector
- Distilled Water Reservoir Tank
- Receiver Tank / Battery Compartment
- Connecting Wires and Supporting Hardware

## Software Requirements

- Arduino IDE
- ESP32 Board Package
- Blynk IoT Platform
- Blynk Mobile Application
- Blynk Web Dashboard
- Wi-Fi Network

## Technical Approach

1. **System Design:** Develop an automatic distilled-water refilling architecture using an ESP32 microcontroller, sensors, relay, and peristaltic pump.
2. **Sensor Integration:** Connect the float switch to detect the water level in the battery compartment and the ultrasonic sensor to monitor the reservoir.
3. **Data Acquisition:** Continuously read the sensor inputs and determine whether the battery requires refilling.
4. **Dual-Sensor Verification:** Verify that the battery water level is low and that sufficient distilled water is available in the reservoir.
5. **Pump Control:** Activate the relay module to operate the peristaltic pump when both conditions are satisfied.
6. **Automatic Stopping:** Continue monitoring the float switch and stop the pump when the required water level is reached.
7. **Low Reservoir Protection:** Stop the refilling operation and generate an alert when insufficient water is detected in the reservoir.
8. **IoT Integration:** Connect the ESP32 to the Blynk platform through Wi-Fi to transmit system status and sensor information.
9. **Mobile Notifications:** Send notifications to the user when refilling starts, the reservoir water level is low, or refilling is completed.
10. **System Testing:** Test the prototype under different water-level conditions to evaluate sensor response, pump operation, and remote monitoring.

## System Working Principle

The system operates through the following sequence:

1. The ESP32 reads the float switch sensor installed in the inverter battery compartment.
2. If the float switch indicates that the water level is sufficient, the pump remains OFF.
3. If the water level is low, the ESP32 reads the ultrasonic sensor to check the distilled-water reservoir.
4. If sufficient water is available, the ESP32 activates the relay module.
5. The relay switches ON the peristaltic pump, transferring distilled water into the battery compartment.
6. The system continuously monitors the float switch during refilling.
7. When the float switch indicates that the required water level has been reached, the ESP32 switches OFF the pump.
8. If the reservoir water level is insufficient, the pump remains OFF and a low-reservoir notification is sent through Blynk.

## Novelty of the Proposed System

- Combines float switch detection and ultrasonic sensing to verify both the battery's water requirement and the availability of distilled water.
- Uses a dual-sensor verification approach to reduce unnecessary pump activation and improve operational reliability.
- Integrates automatic water refilling with IoT-based remote monitoring and mobile notifications.
- Uses a controlled peristaltic pump for precise distilled-water transfer.
- Includes reservoir-level checking to prevent pump dry-running.
- Provides a modular design that can be extended for multiple inverter batteries.

## Results and Performance

The INVER HYDRA prototype was tested under controlled operating conditions to evaluate its automatic refilling and monitoring capabilities.

### System Testing

- The float switch detected low water levels in the inverter battery compartment.
- The ultrasonic sensor verified the availability of distilled water in the reservoir.
- The ESP32 processed sensor information and controlled the relay module.
- The peristaltic pump transferred distilled water when the required conditions were satisfied.
- The pump automatically stopped when the float switch indicated that the battery water level was full.
- The system prevented pump operation when insufficient water was available in the reservoir.

### Performance Observations

- The project report states that the response time between water-level detection and pump activation was typically around 1–2 seconds.
- The dual-sensor mechanism helped avoid unnecessary pump operation.
- The peristaltic pump provided controlled water delivery.
- The Blynk application displayed sensor information and system status.
- Mobile notifications were generated for important refilling events.

### IoT Monitoring

The ESP32 communicates with the Blynk IoT platform through Wi-Fi. The platform provides remote monitoring through its mobile application and web dashboard.

The system supports notifications for:
- Refilling started.
- Low reservoir water level.
- Refilling completed.

## Technologies Used

**Embedded Hardware**
- ESP32 Microcontroller
- Float Switch Sensor
- Ultrasonic Sensor
- Relay Module
- 9V Peristaltic Pump

**Programming and Development**
- Arduino IDE
- ESP32 Board Package

**IoT and Communication**
- Blynk IoT Platform
- Blynk Mobile Application
- Blynk Web Dashboard
- Wi-Fi Communication

**System Components**
- Distilled Water Reservoir
- Battery Compartment / Receiver Tank
- 9V Battery and Connector

## Application Workflow

1. The user installs the system with the distilled-water reservoir and inverter battery compartment.
2. The ESP32 continuously monitors the float switch and ultrasonic sensor.
3. The float switch identifies whether the battery requires distilled water.
4. The ultrasonic sensor checks whether sufficient water is available in the reservoir.
5. The ESP32 processes both sensor readings.
6. The relay module activates the peristaltic pump when refilling conditions are satisfied.
7. The pump transfers distilled water until the required water level is reached.
8. The ESP32 switches OFF the pump after refilling.
9. The Blynk platform updates the system status and sends notifications to the user.

**Project Guide:** Dr. M. Palanivelan

**Institution:** Rajalakshmi Engineering College

## Acknowledgement

INVER HYDRA was developed as an application of embedded systems and Internet of Things (IoT) technologies to improve inverter battery maintenance. By combining ESP32-based control, dual-sensor water-level monitoring, automatic distilled-water refilling, and Blynk-based remote communication, the project aims to provide a convenient and intelligent solution for battery water management.
