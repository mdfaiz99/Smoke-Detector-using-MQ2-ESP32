This project is to develop a smoke detection system in office environment, using NodeMCU. The main objective in this experiment is to:
1) Alert office workers if there is smoke detected which possibly due to fire
2) Monitoring and controlling ventilation fan from mobile application in case there is smoke

EQUIPMENTS
1) Personal Computer/Notebook
2) NodeMCU
3) MQ2 smoke sensor
4) DHT11 temperature and humidity sensor
5) 2 x LED (R1 and G1)
6) Buzzer (B1)
7) 2 x Resistor
8) Some jumper cables

Design and implement a smoke detection program using NodeMCU to detect smoke using MQ2 smoke sensor, monitoring and controlling the LED which act as a ventilation fan using Blynk App.
1) In normal situation, the MQ2 and DHT11 which is the main component to detect smoke are always on. R1 is ON, while G1 and B1 are off.
2) When smoke is detected, B1 goes on while R1 and G1 still in the previous state. Worker will get alert notification in their mobile.
3) Worker can control the opening and the closing of the ventilation fan using Blynk app. When the ventilation fan is switch on, G1 will on while R1 will off.
4) After the office is clear from smoke, worker can switch off the ventilation fan which turns R1 on and G1 off. B1 also will go off when no smoke is detected. Finally, everything goes back to normal

Purpose & Requirements Specification
1) Purpose
- A smoke detection system in office environment, using NodeMCU.

2) Behavior
The smoke detection system works in both manual and automatic mode. Manual mode is when the worker controls the on and off the LEDs which act as opening and closing of the ventilation fan using app. Automatic mode is when the system detects the smoke is higher and the buzzer goes on until the smoke is cleared. Other than that, worker will also get alert notification in their mobile if there is smoke detected.

3) System Management Requirement
The system should provide control and monitoring functions through cloudbased server and mobile application.

4) Data Analysis Requirement
The analysis of data that happens in the system is the present of smoke which turns on the buzzer and off when it’s clear.

5) Application Deployment Requirement
The system is only accessible when the NodeMCU is connected to the host (laptop) using Arduino software but it should be accessible remotely as it is easy to monitor and control the system

6) Security Requirement
User authentication is not required.
