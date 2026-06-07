# Smart Sign Language Gloves

An Arduino-based wearable assistive device that translates hand gestures into text and audio feedback using flex sensors. This project was developed as part of the Design Research Project (DRP) course at IIITDM Kurnool.

## 📌 Overview

Communication barriers can create significant challenges for individuals with speech or hearing impairments. The Smart Sign Language Gloves project aims to address this issue by recognizing predefined hand gestures and converting them into readable text displayed on an LCD screen along with audio feedback through a buzzer.

The system uses flex sensors mounted on a glove to detect finger movements. An Arduino Uno processes sensor data in real time and identifies corresponding gestures.

---

## ✨ Features

* Real-time gesture recognition
* LCD-based text output
* Audio feedback using buzzer
* LED status indication
* Portable battery-powered design
* Low-cost assistive communication solution

---

## 🛠 Hardware Components

* Arduino Uno
* 5 Flex Sensors
* 16x2 LCD Display
* Buzzer/Speaker
* LED Indicator
* 3.7V Li-ion Battery
* MT3608 Boost Converter
* Connecting Wires and Resistors
* Glove Base

---

## 💻 Software Used

* Arduino IDE
* Embedded C/C++
* Tinkercad (Circuit Simulation)

---

## 🧠 Working Principle

1. Flex sensors are attached to each finger of the glove.
2. When fingers bend, the resistance of the sensors changes.
3. Arduino reads analog values from the sensors.
4. The values are compared with predefined thresholds.
5. Corresponding gestures are identified.
6. The recognized message is displayed on the LCD.
7. Audio and LED feedback are generated.

---

## 🎯 Supported Gestures

| Gesture Pattern                     | Output    |
| ----------------------------------- | --------- |
| All fingers bent                    | HELLO     |
| Thumb straight, others bent         | YES       |
| Thumb bent, others straight         | NO        |
| Thumb bent, Index & Middle straight | WATER     |
| Thumb, Index & Middle straight      | FOOD      |
| Thumb & Little straight             | HELP      |
| All fingers straight except little  | EMERGENCY |

---


## 📂 Repository Structure

```text
smart-sign-language-gloves/
│
├── README.md
├── LICENSE
├── code/
│   └── smart_sensor_gloves.ino
│
├── images/
│   ├── final_prototype.jpg
│   ├── tinkercad_design.png
│   ├── lcd_testing.jpg
│   └── sensor_calibration.jpg
│
└── docs/
    └── Smart-Sign-Language-Gloves.pdf
```

## 🚀 Future Improvements

* AI-based gesture recognition
* Bluetooth connectivity
* Mobile application integration
* Voice output module
* Multi-language support
* Expanded gesture vocabulary


---
## Developers

This project was developed as part of a DRP course by:

- Himal Tyagi
- Kattunga Jahnavi Sai Parvathi
- Khushi Kumari
- Arya Prasad M P
- Saksham Singh
## 👨‍💻 Author

**Saksham Singh**

B.Tech Computer Science and Engineering
IIITDM Kurnool

---

## 📜 License

This project is licensed under the MIT License.
