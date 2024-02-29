# STM32F103C8T6 Bluepill Communication Project

## Overview

This repository contains the source code for a project where two STM32F103C8T6 Bluepill microcontrollers communicate with each other using UART. The communication is triggered by external interrupts generated by buttons, and the second microcontroller controls LEDs based on the received data.

## Hardware Setup

- **First Microcontroller**: This microcontroller is configured to send data ('a' or 'b') based on button presses.

  - Button 1 (EXTI0): Sends 'a' when pressed.
  - Button 2 (EXTI1): Sends 'b' when pressed.
  - USART1 (TX on PA9, RX on PA10): Used for communication.

- **Second Microcontroller**: This microcontroller receives data and controls LEDs accordingly.

  - LED (PC13): Always ON.
  - LED (PB0): Controlled based on received data.
  - USART1 (TX on PA9, RX on PA10): Used for communication.

## Project Structure

### First_Microcontroller

This folder contains the source code for the first microcontroller, responsible for sending data based on button presses.

- **main.c**: Configures GPIO, EXTI, USART, and handles button presses to trigger communication.

### Second_Microcontroller

This folder contains the source code for the second microcontroller, responsible for receiving data and controlling LEDs.

- **main.c**: Configures Clock, GPIO, USART, LEDs, and processes received data to control the LEDs.
