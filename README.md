This project is to develop a smoke detection system in office environment, using NodeMCU. The main objective in this experiment is to:
• Alert office workers if there is smoke detected which possibly due to fire
• Monitoring and controlling ventilation fan from mobile application in case there is smoke

EQUIPMENTS
• Personal Computer/Notebook
• NodeMCU
• MQ2 smoke sensor
• DHT11 temperature and humidity sensor
• 2 x LED (R1 and G1)
• Buzzer (B1)
• 2 x Resistor
• Some jumper cables

Design and implement a smoke detection program using NodeMCU to detect smoke using MQ2 smoke sensor, monitoring and controlling the LED which act as a ventilation fan using Blynk App.
• In normal situation, the MQ2 and DHT11 which is the main component to detect smoke are always on. R1 is ON, while G1 and B1 are off.
• When smoke is detected, B1 goes on while R1 and G1 still in the previous state. Worker will get alert notification in their mobile.
• Worker can control the opening and the closing of the ventilation fan using Blynk app. When the ventilation fan is switch on, G1 will on while R1 will off.
• After the office is clear from smoke, worker can switch off the ventilation fan which turns R1 on and G1 off. B1 also will go off when no smoke is detected. Finally, everything goes back to normal

Purpose & Requirements Specification
i. Purpose
A smoke detection system in office environment, using NodeMCU.

ii. Behavior
The smoke detection system works in both manual and automatic mode. Manual mode is when the worker controls the on and off the LEDs which act as opening and closing of the ventilation fan using app. Automatic mode is when the system detects the smoke is higher and the buzzer goes on until the smoke is cleared. Other than that, worker will also get alert notification in their mobile if there is smoke detected.

iii. System Management Requirement
The system should provide control and monitoring functions through cloudbased server and mobile application.

iv. Data Analysis Requirement
The analysis of data that happens in the system is the present of smoke which turns on the buzzer and off when it’s clear.

v. Application Deployment Requirement
The system is only accessible when the NodeMCU is connected to the host (laptop) using Arduino software but it should be accessible remotely as it is easy to monitor and control the system

vi. Security Requirement
User authentication is not required.
