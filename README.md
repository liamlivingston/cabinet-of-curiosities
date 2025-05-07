# **Cabinet of Curiosities – LED Lighting Controller**

This project controls LED lighting for two cabinets using Arduino Nanos. Each cabinet contains 12 groups of 5 LED segments (60 total), with customizable static or dynamic animations driven by timers and the FastLED library.

---

## **Overview**

* **12 groups** per cabinet

* **5 LED segments per group**

* **60 total LED segments per Arduino Nano (cabinet)**

* Timed animations using internal counters

* Built with the FastLED library

To get organized responses for each group, I used [this google form](https://docs.google.com/forms/d/18G9--uJXi5WSSO_25A2kZsz4Qd7XMMPq6qWhC9l4W7Q/edit) (ask Mr. Tinsley or Mr. Tocci for access)

I used [this google sheet](https://docs.google.com/spreadsheets/d/1jGJj7rgvKHG3yeBdRig2TnL1rXQ8HiCC9kr8fNd_RWE/edit?usp=sharing) to organize group placement and to organize the collected info


---

## **Files**

* `cabinet-of-curiosities-1.ino`: Controls Cabinet 1

* `cabinet-of-curiosities-2.ino`: Controls Cabinet 2

---

## **Setup Instructions**

1. **Download the Code**  
    Clone this repo or download both `.ino` files.

2. **Install Arduino IDE**  
    [Download here](https://www.arduino.cc/en/software)

3. **Install the FastLED Library**

   * In Arduino IDE: **Sketch \> Include Library \> Manage Libraries...**

   * Search for and install **FastLED**

4. **Connect Hardware**

   * Plug each Arduino Nano in via USB-C

5. **Upload Code**

   * Open the `.ino` files

   * Select the appropriate **board** and **port** under **Tools**

   * Upload each file to its respective Nano

---

## **Color Configuration**

Static colors for all segments are defined in:

```
int arr[60][3] = {  
  {R, G, B}, // Segment 0  
  ... 
  {R, G, B}  // Segment 59 
};

* arr[0]–arr[4] \= Group 1

* arr[5]–arr[9] \= Group 2

* …

* arr[55]–arr[59] \= Group 12
```
**Example:** 
```
int arr[60][3] = {  
  {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, {255, 0, 0}, // Group 1 - Red  
  {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, {0, 255, 0}, // Group 2 - Green  
  ...  
};
```
---

## **Timing Mechanism (Animation Control)**

The top of the `loop()` function contains two counters:

```
void loop() {  
  delay(10); // Loop delay ~100Hz  
  t++;       // General-purpose timer  
  if (t == 500) t = 0; // ~5 sec interval

  a++;       // Hue timer  
  if (a == 255) a = 0; // ~2.55 sec hue cycle

  // Animation code follows...  
}
```

### **Customize Animation Speed**

* Change `t == 500` to trigger events more/less frequently

* Modify `delay(10)` to speed up or slow down the loop globally

* For independent animation timers, use `millis()`\-based logic

---

## **Animation Logic: `setRGB()` vs. `setHSV()`**

The code supports two main ways of setting LED colors:

### **`setHSV(hue, sat, val)`**

* Easier to use for **smooth hue sweeps** and rainbow-style effects

* Driven directly by the `a` hue timer in many cases

Example:
```leds[i].setHSV(a, 255, 255); // Color changes smoothly over time```

*   
* **Great for:** animations that need fluid color transitions

### **`setRGB(r, g, b)`**

* Gives full control over the exact color per LED

* Better for **precise, static color patterns** or custom waveforms

* Requires more math and logic for effects like pulsing or gradients

Example:
```leds[i].setRGB(128, 0, 255); // Set LED to a specific purple```

*   
* **Great for:** custom designs, fading patterns, calculated effects

💡 **Tip:** During development, I found it extremely helpful to test animations on the actual LEDs frequently. Visual feedback was key to fine-tuning colors, transitions, and timings.

---

## **Advanced Animations**

Built with FastLED, the controller supports:

* Rainbow loops

* Color shifts

* Group pulsing

* Segment-level animation

* User-defined patterns with per-frame updates

Check the FastLED [examples folder](https://github.com/FastLED/FastLED/tree/master/examples) for inspiration.

---

## **Troubleshooting**

* Verify correct COM port in **Tools \> Port**

* Confirm FastLED is installed correctly

* Check LED power and data line connections

* Make sure the number of LEDs and data pin are correctly set in code

---

## **Support**

Questions? Need help?  
 📧 **liamklivingston@gmail.com**

---

## **Disclaimer**

This README was formatted and cleaned up with the help of AI.
