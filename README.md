# RGBLighting
This repository contains lighting functionality in a room through the use of Individually addresible RGB Leds

## How to Install
Clone this repository. Load the files into the microcontroller

## Hardware
- Arduino
- Adafruit Circuit Playground
- Adafruit Gemma M0
- Individually addressible RGB Led lights

## Project Idea
The goal of this project is be able to control multi-funcitonal RGB Led lights quickly and easily. The entire setup process should take under 10 minutes.
The lights are controlled by a single button. This minimizes the hardware complexity and makes it easy to prototype in a breadboard. The single button will serve as the controll for the lights

### Physical Interface
- 1 buttons
  - Press once and hold 
     - The mode will change one by one in intervals of 1-2 secconds. When the button is released, the mode is set.
  - Press twice and hold
    - Double-click the button the minimum brightness to maximum brightness in steps. The button must be continously held down to cycle through the modes.
  - Press 3 times and hold
    - This will immediately turn the entire stip off
- 1 state indicator LED 
  -  This tells LED mirrors the button presses so that you know the arduino is reading your input 

### Light Modes and Functionality
- RGB Rainbow
- RGB Pallettes (many)
- Twinkle
- Fire
- Night Light
- Party Light
- Mood Light
