# 🚗 STM32 Car Parking System

A simple embedded Car Parking System project developed using the STM32F103C8T6 (Bluepill) microcontroller. The system tracks the number of cars entering and exiting a parking lot using IR sensors and displays the count on a TM1637 4-digit 7-segment display.

## 📌 Features

- 🔢 Displays number of available parking slots using a TM1637 display
- 🔍 IR sensors for detecting car entry and exit
- 🧠 Efficient counter logic for parking management
- ⚡ Lightweight and affordable embedded solution

## 🔧 Hardware Components

| Component              | Description                            |
|------------------------|----------------------------------------|
| STM32F103C8T6          | Microcontroller (Bluepill board)       |
| TM1637 Display Module  | 4-digit 7-segment display              |
| IR Sensors x2          | Vehicle detection at entry and exit    |
| External Power Supply  | For STM32 and sensors (typically 5V)   |
| Jumper Wires & Breadboard | For prototyping                      |

## 🔌 Connections Overview

| Device        | STM32 Pin (Example) |
|---------------|---------------------|
| TM1637 CLK    | PA0                 |
| TM1637 DIO    | PA1                 |
| Entry IR      | PA2                 |
| Exit IR       | PA3                 |

> Pin mapping can be adjusted in code or STM32CubeMX configuration.

## 🧠 Working Principle

1. **Entry Detection**:
   - IR sensor detects a car entering.
   - Counter increments.
   - Updated count is shown on TM1637 display.

2. **Exit Detection**:
   - IR sensor detects a car exiting.
   - Counter decrements.
   - Display updates with new available slots.

3. **Boundary Conditions**:
   - Prevents the count from exceeding capacity or dropping below zero.
   - Can easily be configured for any total slot size.

## 📁 Project Structure

CarParkingSystem/
├── CarParkingSystem.uvprojx # Keil project file
├── main.c # Application logic
├── tm1637.c / tm1637.h # TM1637 driver functions
├── delay.c / delay.h # Millisecond delay utilities
├── stm32f10x_it.c # Interrupt handlers
└── README.md # This file
