# NTUA ECE Sensors and Microsystems Technology Course

This repository showcases the laboratory exercises, Arduino source codes, and project reports I completed during the Sensors and Microsystems Technology course at NTUA. Through this coursework, I gained practical experience in sensor characterization, data acquisition, and embedded systems programming using microcontrollers.

## Laboratory Exercises

### Lab 1: Hall Effect Sensor Calibration
*Experimental characterization and calibration of an SS49E Hall magnetic sensor.*

* **Key Tasks:**
  * **Sensor Calibration:** Placed the Hall sensor inside a solenoid and measured its output voltage ($V_{out}$) against varying input currents to the solenoid.
  * **Data Analysis:** Analyzed the relationship between the applied current (I), magnetic field strength (H), magnetic induction (B), and the resulting sensor voltage (V) to generate the sensor's calibration curve and assess magnetic hysteresis.
* **Tech Stack:** Hall Effect Sensors, Sensor Calibration, Data Processing (Excel).

### Lab 2: Magnetic Position and Field Sensors (Fluxgate)
*Study and experimental characterization of fluxgate magnetic sensors.*

* **Key Tasks:**
  * **Field Measurement:** Analyzed the operation of a fluxgate sensor for measuring external magnetic fields. Evaluated the time difference ($\Delta t$) between signal peaks to calculate field strength and generated calibration curves.
  * **Position Measurement:** Investigated how the displacement of the magnetic core affects the output voltage amplitude, correlating sensor output to the physical position of the core.
  * **Data Analysis:** Processed experimental data and created plots for $\Delta t$ vs. DC offset and voltage vs. displacement.
* **Tech Stack:** Fluxgate Sensors, Sensor Analysis, Data Processing (Excel).

### Labs 3 & 4: Arduino and Embedded Applications
*Practical implementation of microcontroller-based systems using Arduino.*

* **Key Tasks:**
  * **Morse Code Emitter:** Programmed the Arduino to control the built-in LED to emit an "SOS" signal in Morse code using precise timing loops.
  * **Serial Communication:** Developed a script to control an LED via serial port input, turning it on with specific characters ('H'/'h') and off with others ('L'/'l'), including error handling for invalid inputs.
  * **Temperature Monitoring (TMP36):** Interfaced a TMP36 analog temperature sensor with the Arduino to read ambient temperature. Implemented logic to control a multi-LED indicator (Green, Orange, Red) based on predefined temperature thresholds.
* **Tech Stack:** C/C++ (Arduino), Microcontrollers, Serial Communication, Analog/Digital I/O.

## Technologies Used

* **Languages:** C/C++ (Arduino)
* **Hardware:** Arduino Microcontrollers, SS49E Hall Sensors, TMP36 Temperature Sensors, Fluxgate Magnetic Sensors, LEDs.
* **Core Concepts:** Embedded Systems, Analog-to-Digital Conversion (ADC), Serial Communication, Sensor Calibration, Magnetic Core Hysteresis, Hall Effect.
* **Environments:** Arduino IDE, Microsoft Excel (Data Analysis), Document Reports (PDF).
