# HC-SR04 Ultrasonic Sensor with Raspberry Pi Pico

A step-by-step tutorial and code examples for interfacing an HC-SR04 Ultrasonic Sensor with a Raspberry Pi Pico. This repository contains implementations for both the **Arduino IDE** and the native **Pico C/C++ SDK**, providing a clear path from a quick start to a professional embedded setup.

---

## 📁 Repository Contents

| File | Description |
| :--- | :--- |
| `Pico_HCSR04.ino` | Complete Arduino IDE sketch for the HC-SR04 sensor. |
| `hcsr04_demo.c` | Native Pico C/C++ SDK implementation of the sensor driver. |
| `CMakeLists.txt` | CMake configuration file to build the Pico SDK project. |
| `Pico with Ultrasonic Sensor Setup Tutorial.pdf` | **Full step-by-step tutorial** with wiring diagrams, code explanations, and porting guide. |

---

## 🚀 Quick Start (Arduino IDE)

For a quick test and proof of concept, use the Arduino IDE.

1.  **Wire the Sensor** as shown in the tutorial. **Crucial:** Use a 1kΩ resistor in series with the Echo pin.
2.  Open `Pico_HCSR04.ino` in the Arduino IDE.
3.  Select **Raspberry Pi Pico** as your board.
4.  Upload the code.
5.  Open the Serial Monitor at `115200` baud to see distance readings.

---

## 🔧 Professional Setup (Pico C/C++ SDK)

To integrate the sensor into a larger project using the native SDK:

1.  Create a project folder with the provided `hcsr04_demo.c` and `CMakeLists.txt` files.
2.  Ensure you have the Pico SDK and toolchain set up in your VS Code environment.
3.  Build the project to generate a `hcsr04_demo.uf2` file.
4.  Drag and drop the `.uf2` file onto the RPI-RP2 drive while the Pico is in bootloader mode.

---

## 📚 Documentation & Resources

-   **[Full Tutorial PDF](./Pico%20with%20Ultrasonic%20Sensor%20Setup%20Tutorial.pdf)**: The complete guide, including detailed wiring, code walkthroughs, and porting instructions.
-   **Setup Photo**: [View on GitHub](./IMG_8944.JPG)
-   **Video Demonstration**: [Watch on Google Drive](https://drive.google.com/file/d/1QmKfTkoE7Oyf5a5P5sVUFYssd_u46Xmk/view?usp=sharing)

---

## ⚠️ Important Note

**The 1kΩ resistor between the sensor's Echo pin and the Pico's GPIO is mandatory.** The HC-SR04 Echo pin outputs a 5V signal, while the Raspberry Pi Pico's GPIO pins are only tolerant up to 3.3V. The resistor acts as a simple voltage divider to protect your Pico from potential damage.

---

## 🤝 Contributing

Feel free to fork this project and submit pull requests for any improvements. If you find any issues, please open an ticket in the GitHub issue tracker.

---

## 📄 License

This project is provided for educational purposes. Please refer to the specific licenses of the libraries and tools used.
