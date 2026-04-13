# Smart Home Automation System (ATmega32)
This project implements a smart home automation system using the ATmega32 microcontroller. It automatically controls lighting, fan speed, and safety alerts based on environmental conditions.
## Features
### Automatic Lighting Control
- Uses LDR sensor to detect light intensity
- Controls RGB LEDs based on brightness levels
### Temperature-Based Fan Control
- Uses LM35 temperature sensor
- Adjusts fan speed using PWM
### Fire Detection System
- Flame sensor detects fire
- Activates buzzer alarm
- Displays "Critical Alert" on LCD
### LCD Display
- Shows temperature, light intensity, and fan status in real-time

## Hardware Components
- ATmega32 Microcontroller
- LM35 Temperature Sensor
- LDR Sensor
- Flame Sensor
- 16x2 LCD
- DC Motor (Fan) + H-Bridge
- LEDs
- Buzzer
- 
## System Architecture
The system follows a layered architecture:
- Application Layer
- Drivers Layer (LCD, ADC, PWM, GPIO, Sensors)

## Functional Overview
### Fan speed increases with temperature:
- 25°C → OFF
- 40°C → 100% speed
### Light intensity controls LEDs:
- Low light → All LEDs ON
- High light → LEDs OFF
### Fire detection:
- Triggers buzzer
- Displays alert on LCD
##Technologies Used
- Embedded C
- ATmega32
- ADC, PWM, GPIO Drivers

## Demo Video 
- [Project Video](https://drive.google.com/file/d/1NMX6GbbQI-UXlhZLIIj_ZxDImHChQ4Bp/view?usp=sharing)  

## License
This project is for educational and non-commercial use.
