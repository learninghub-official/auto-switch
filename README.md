# Smart Charging Switch: Solve Laptop Overheating & Overcharging!

This project addresses the common issues of laptop overheating and overcharging, especially for users who run their machines for extended hours. The solution involves a smart charging switch built using an ESP8266, a relay module, and Firebase Realtime Database. 

The project is divided into two parts:
1. **Part 1**: Extract battery percentage using Python and send data to Firebase.
2. **Part 2**: Control the relay using ESP8266 based on real-time battery data.

---

## Features
- **Smart Charging**: Automatically starts charging when the battery drops below 20% and stops at 100%.
- **Overheating Prevention**: Avoids prolonged charging that can lead to overheating.
- **Wireless Communication**: Uses Firebase for seamless data exchange between the laptop and ESP8266.

---

## Getting Started

### Prerequisites
1. Install Python (version 3.7 or later).
2. Install Arduino IDE for ESP8266 programming.
3. Set up Firebase Realtime Database in your Google Cloud Console.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/learninghub-official/auto-switch.git
   cd auto-switch
   ```

2. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```

3. Configure Firebase:
   - Download your Firebase project’s JSON credentials.
   - Place the JSON file in the project directory.
   - Update the file path and database URL in `python_script.py`.

4. Flash the ESP8266:
   - Open `auto_switch.ino` in Arduino IDE.
   - Update the Wi-Fi credentials, Firebase Host, and Auth key.
   - Select **NodeMCU 0.9** as the board, choose the correct COM port, and upload the code.

---

## File Structure
```plaintext
/
├── battery_extract.py         # Python script to extract battery percentage and send data to Firebase
├── auto_switch.ino         # Arduino code to control the relay based on Firebase data
├── requirements.txt         # Python dependencies
├── README.md                # Project documentation
└── autoswitch-b5b8c-firebase-adminsdk.json # Firebase JSON credentials (not included in the repository)
```

---

## Usage
1. Run the Python script:
   ```bash
   python battery_extract.py
   ```
   This script reads the battery percentage and sends data to Firebase every 30 seconds.

2. Monitor the ESP8266:
   - View real-time data in the Arduino Serial Monitor.
   - Check the relay status as it turns ON/OFF based on the battery percentage.

---

## Demo
### Video Links:
- [Part 1: Python Script & Firebase Setup](https://youtu.be/b0y9wyNzUFk)
- [Part 2: ESP8266 Integration & Relay Control](coming soon)

---

## Contributors
- **Your Name** - [GitHub Profile](https://github.com/learninghub-official)

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
