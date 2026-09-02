# 🧠 NeuroBridge: IoT-Driven Assistive Movement & Motor-Intent ML Pipeline

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Python 3.9+](https://img.shields.io/badge/Python-3.9+-3776AB.svg?logo=python&logoColor=white)](https://www.python.org/)
[![Arduino Uno](https://img.shields.io/badge/Hardware-Arduino_Uno-00979C.svg?logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Status](https://img.shields.io/badge/Status-Active_Development-brightgreen.svg)]()

> **NeuroBridge** is an assistive hardware-software framework engineered to aid mobility for paralyzed or motor-impaired individuals. Using an array of IoT sensors interfaced with an **Arduino Uno**, the system captures micro-gestural/physiological telemetry in real time. These sensor streams directly trigger assistive mobility mechanisms while continuously curating labeled datasets to train and optimize machine learning models for motor-intent classification.

---

## 📑 Table of Contents
1. [Key Features](#-key-features)
2. [System Architecture](#-system-architecture)
3. [Hardware & Sensor Stack](#-hardware--sensor-stack)
4. [Dataset Schema & Telemetry Format](#-dataset-schema--telemetry-format)
5. [Machine Learning Pipeline](#-machine-learning-pipeline)
6. [Repository Structure](#-repository-structure)
7. [Installation & Setup](#-installation--setup)
   - [Hardware Setup](#1-hardware-configuration)
   - [Arduino Firmware](#2-arduino-firmware-flash)
   - [Python ML & Data Logger Environment](#3-python-environment-setup)
8. [Usage Guide](#-usage-guide)
9. [Roadmap](#-roadmap)
10. [Contributing & License](#-contributing--license)

---

## 🌟 Key Features

* **Real-Time Assistive Control:** Low-latency sensor signal processing on the edge (Arduino Uno) to trigger assistive actuators (e.g., motorized wheelchair relays, robotic limbs, or alert buzzers).
* **Automated Data Logging:** High-frequency serial ingestion script (via PySerial) recording timestamped multichannel sensor telemetry.
* **ML-Ready Data Pipeline:** Preprocessing modules including signal filtering (Butterworth bandpass, moving average), feature extraction (RMS, Mean Absolute Value, Waveform Length), and dataset formatting.
* **Intent Classification Engine:** Supervised learning models (Random Forest, SVM, 1D-CNN, LSTM) trained to classify user movement intentions from physiological signals.

---

## 🏗️ System Architecture

```text
  +-------------------------------------------------------------+
  |                      1. SENSING LAYER                       |
  |  [EMG / Flex / IMU / Eye-Blink Sensors]                     |
  +------------------------------+------------------------------+
                                 | Analog / Digital Signals
                                 v
  +-------------------------------------------------------------+
  |                     2. HARDWARE / EDGE                      |
  |  [Arduino Uno Microcontroller]                              |
  |   - Signal Acquisition & Noise Thresholding                 |
  |   - Immediate Assistive Actuation (Relays / Motors)         |
  +------------------------------+------------------------------+
                                 | Serial Communication (USB/UART)
                                 v
  +-------------------------------------------------------------+
  |                 3. DATA INGESTION & PIPELINE                |
  |  [Python Serial Data Logger (`serial_logger.py`)]           |
  |   - Structured CSV Ingestion & Quality Checks               |
  +------------------------------+------------------------------+
                                 | Clean Datasets
                                 v
  +-------------------------------------------------------------+
  |                   4. MACHINE LEARNING ENGINE                |
  |  [Feature Extraction & Predictive Models]                   |
  |   - Time/Frequency Domain Feature Extraction                |
  |   - Intent Classification (RF, SVM, LSTM, 1D-CNN)           |
  |   - Adaptive Calibration & Model Evaluation                 |
  +-------------------------------------------------------------+
```

---

## 🔌 Hardware & Sensor Stack

| Component | Purpose / Function | Interface |
| :--- | :--- | :--- |
| **Arduino Uno (ATmega328P)** | Central edge controller & ADC sampling | Serial / USB (Baud: 115200) |
| **EMG Sensor (e.g., MyoWare)** | Detects residual muscle micro-contractions | Analog Pin `A0` |
| **IMU / Gyroscope (MPU6050)** | Head / limb orientation & tilt tracking | I2C (`SDA`/`SCL`) |
| **Flex Sensors / Force (FSR)** | Measures joint bend or finger press intent | Analog Pins `A1`, `A2` |
| **IR / Optical Sensor** | Detects intentional eye blinks or eyebrow twitches | Digital Pin `D2` |
| **Motor Drivers / Relays** | Drives wheelchair actuators or assistive mechanisms | Digital Pins `D8`, `D9` |

---

## 📊 Dataset Schema & Telemetry Format

Sensor streams are logged to CSV format with standardized metadata for training supervised ML models.

### Raw Stream Schema (`dataset/raw/telemetry_raw_*.csv`)

| Column Name | Data Type | Unit / Range | Description |
| :--- | :--- | :--- | :--- |
| `timestamp_ms` | `uint64` | Milliseconds | Relative hardware runtime timestamp |
| `subject_id` | `string` | e.g., `SUBJ_01` | Unique subject identifier |
| `emg_raw` | `int16` | `0` – `1023` (ADC) | Raw surface EMG voltage reading |
| `accel_x`, `accel_y`, `accel_z` | `float32` | `g` (±2g scale) | Accelerometer tri-axial acceleration |
| `gyro_x`, `gyro_y`, `gyro_z` | `float32` | `deg/s` (±250dps) | Gyroscope angular velocity |
| `flex_val` | `int16` | `0` – `1023` | Resistive bend sensor reading |
| `blink_trigger` | `uint8` | `0` or `1` | Binary digital state from optical trigger |
| `target_label` | `int8` | Categorical | Movement class label (Ground Truth) |

### Movement Intent Class Mappings

```json
{
  "0": "REST / NO_INTENT",
  "1": "FORWARD_MOTION",
  "2": "REVERSE_MOTION",
  "3": "TURN_LEFT",
  "4": "TURN_RIGHT",
  "5": "EMERGENCY_STOP"
}
```

---

## 🤖 Machine Learning Pipeline

1. **Preprocessing & Filtering:**
   * 50Hz/60Hz notch filter for powerline hum elimination.
   * 20Hz – 450Hz bandpass filter for EMG noise reduction.
   * Sliding window segmentation (Window size: `250ms`, Overlap: `50%`).
2. **Feature Engineering:**
   * **Time Domain:** Root Mean Square (RMS), Mean Absolute Value (MAV), Zero Crossing (ZC), Slope Sign Changes (SSC), Waveform Length (WL).
   * **Frequency Domain:** Mean Frequency (MNF), Median Frequency (MDF), Power Spectral Density (PSD).
3. **Model Architectures:**
   * **Baseline:** Random Forest Classifier & Support Vector Machine (RBF Kernel).
   * **Deep Learning:** 1D-CNN (temporal feature extraction) & Bi-LSTM (sequential intent forecasting).

---

## 📁 Repository Structure

```text
neurobridge/
├── hardware/
│   ├── firmware/
│   │   └── neurobridge_uno.ino       # Arduino Uno signal capture & actuation code
│   └── schematics/
│       └── circuit_diagram.png       # Pin connection diagram & breadboard layout
├── data_ingestion/
│   ├── serial_logger.py              # PySerial real-time telemetry logger
│   └── config.yaml                   # Serial port, baud rate & streaming configs
├── dataset/
│   ├── raw/                          # Unprocessed streaming CSV files
│   └── processed/                    # Filtered & windowed feature matrices
├── ml_pipeline/
│   ├── preprocessing.py              # Signal filters & sliding window segmenter
│   ├── feature_extraction.py         # Time & frequency domain feature extractors
│   ├── train.py                      # Model training & hyperparameter tuning
│   ├── evaluate.py                   # Confusion matrix, ROC-AUC, F1 metrics
│   └── models/                       # Serialized trained weights (.pkl / .onnx)
├── docs/
│   └── API_REFERENCE.md              # Documentation on communication protocol
├── requirements.txt                  # Python dependencies
├── LICENSE
└── README.md
```

---

## 🚀 Installation & Setup

### 1. Hardware Configuration
1. Connect sensor outputs to Arduino Uno analog (`A0`-`A2`) and digital (`D2`) pins according to the [Hardware Table](#-hardware--sensor-stack).
2. Connect the Arduino Uno to your workstation using a USB-A to USB-B cable.

### 2. Arduino Firmware Flash
1. Open `hardware/firmware/neurobridge_uno.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
2. Select Board: **Arduino Uno** and your active **COM Port** (e.g., `/dev/ttyACM0` or `COM3`).
3. Click **Upload**.

### 3. Python Environment Setup
```bash
# Clone the repository
git clone https://github.com/<your-username>/neurobridge.git
cd neurobridge

# Create and activate virtual environment
python3 -m venv venv
source venv/bin/activate  # On Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements.txt
```

---

## 💻 Usage Guide

### Step 1: Collect & Log Telemetry
Run the serial logger to record real-time sensor streams into a labeled dataset:
```bash
python data_ingestion/serial_logger.py --port COM3 --baud 115200 --subject SUBJ_01 --label 1 --duration 60
```

### Step 2: Preprocess and Extract Features
```bash
python ml_pipeline/preprocessing.py --input dataset/raw/ --output dataset/processed/
```

### Step 3: Train Motor-Intent Model
```bash
python ml_pipeline/train.py --model random_forest --data dataset/processed/features.csv
```

### Step 4: Evaluate Model
```bash
python ml_pipeline/evaluate.py --model-weights ml_pipeline/models/best_rf_model.pkl
```

---

## 🗺️ Roadmap

- [x] Initial Arduino Uno multi-sensor acquisition loop.
- [x] High-speed serial telemetry ingestion script.
- [x] Feature extraction pipeline (Time/Frequency domain).
- [ ] Implement real-time inference bridge on embedded edge devices (Edge Impulse / TinyML).
- [ ] Add wireless telemetry transmission via ESP32 / Bluetooth Low Energy (BLE).
- [ ] Clinical validation trials and adaptive gesture personalization.

---

## 🤝 Contributing & License

Contributions are welcome! Please open an issue or submit a PR following standard open-source conventions.

Distributed under the **MIT License**. See `LICENSE` for more information.

Website Link : https://mind-muscle-bridge.vercel.app/
