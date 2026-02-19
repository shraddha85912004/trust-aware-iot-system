# Trust-Aware Explainable IoT Decision Engine

## Overview
This project implements a reliability-aware IoT monitoring system using Arduino. 
Instead of static threshold-based alerting, each sensor is assigned a dynamic trust score.

## Features
- Dynamic trust evaluation for sensors
- Weighted decision making
- Explainable alerts on LCD
- Fault tolerance under noisy input

## Hardware Used
- Arduino UNO
- TMP36 Temperature Sensor
- Potentiometer (Gas Simulation)
- LDR
- 16x2 LCD
- LEDs

## Logic
effective_value = sensor_value × trust_score

Trust decreases when:
- Sudden signal spikes occur
- Sensor values fluctuate abnormally

## Output Example
ALERT!
Gas T: 1.00

## Learning Outcome
- Sensor fusion
- Reliability engineering
- Explainable system design
- Embedded decision architecture


