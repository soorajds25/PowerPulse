# ⚡ Electricity Monitoring & Optimization Assistant  
### Data Acquisition & Lightweight Anomaly Detection Prototype for Physical AI

---

## 🧠 Overview  
This project is a **room-level electricity monitoring system** that measures and logs real-time **voltage and current** from two separate circuits (simulating two rooms).

In addition to data collection, the system performs **basic statistical anomaly detection on power consumption**, demonstrating early-stage intelligence without heavy AI models.

---

## 👥 Team  
**Team Name:** *PowerPulse*  

**Members:**  
- Sooraj D S  
- Sreeraj R S  

📧 **Contact:** soorajjds@gmail.com  
🔗 **GitHub:** https://github.com/soorajds25  

---

## 🚀 Problem  
Electricity usage is typically not monitored at a **granular (room-level)** scale, making it difficult to:

- Detect abnormal consumption  
- Identify faulty appliances  
- Optimize energy usage  

Additionally, there is **no readily available real-world dataset** for building AI-based systems in this domain.

---

## 💡 Solution  
A **dual-circuit monitoring system** that:

- Measures voltage and current from two circuits  
- Computes real-time **power consumption (P = V × I)**  
- Logs data into a CSV dataset  
- Detects anomalies using statistical methods  
- Enables comparison between circuits  

---

## 🧩 Features  
- Dual-circuit monitoring (2 rooms simulation)  
- Real-time voltage, current, and power calculation  
- Continuous CSV data logging  
- Statistical anomaly detection (Z-score)  
- Dataset generation for ML use  

---

## 🛠️ Hardware (BOM)

| Component | Quantity | Purpose |
|----------|---------|--------|
| Arduino Uno | 1 | Controller |
| ACS712 Current Sensor | 2 | Current measurement |
| Voltage Sensor Module | 2 | Voltage measurement |
| Breadboard | 2 | Prototyping |
| DIP Switch | 1 | Load control |
| Motor | 1 | Load testing |
| LED | 1 | Load testing |
| 12V 5A Power Supply | 1 | Power source |
| Buck Converter | 1 | Voltage regulation |
| Jumper Wires | Multiple | Connections |

---

## ⚙️ Tech Stack  

**Languages:**  
- C++ (Arduino)  
- Python  

**Libraries:**  
- PySerial  
- CSV  
- NumPy / Matplotlib (for analysis)

**AI Approach:**  
- Lightweight statistical anomaly detection (Z-score)  
- Future: TinyML / Edge AI on ESP32  

---

## 🧪 How It Works  

1. Two circuits simulate two rooms  
2. Each circuit uses:
   - Voltage sensor  
   - Current sensor  
3. Arduino reads analog values  
4. Data is sent via serial in format:
   Time,V1,V2,I1,I2

5. Python script:
   - Logs data into CSV  
   - Computes power:
     ```
     P1 = V1 × I1
     P2 = V2 × I2
     ```
   - Performs anomaly detection  

---

## 📊 Anomaly Detection (Core Addition)

### Method Used: Z-Score Based Detection  

Formula:
Z = (X - μ) / σ


Where:
- X = current value  
- μ = mean  
- σ = standard deviation  

### Rule:
- If |Z| > 2 → **Anomaly**  
- Else → **Normal**

---

## 📊 Results  

### Power vs Time Graph
<img width="567" height="455" alt="output" src="https://github.com/user-attachments/assets/6d83d63a-511e-4273-9b08-d03a40292b2e" />

- Channel 1 shows stable behavior with occasional spikes  
- Channel 2 shows frequent ON/OFF transitions
 
**Detected Anomalies:**
- Channel 1: 4 anomalies  
- Channel 2: 73 anomalies  

---

## 🔍 Interpretation  

**Channel 1:**
- Mostly stable  
- Occasional spikes  
- Represents normal behavior with rare anomalies  

**Channel 2:**
- Frequent ON/OFF switching  
- Sudden drops to zero  
- High number of anomalies (expected behavior)  

---

## ⚡ What Counts as Anomaly  

- Sudden current spikes (e.g., motor activation)  
- Sudden drops to zero (switch OFF)  
- Irregular fluctuations  

---

## 🧠 Why This Approach (Instead of Heavy AI)

- Dataset size is small  
- Limited features (Voltage, Current)  
- Real-time constraints on microcontroller  

✔ Implemented **lightweight edge intelligence** instead of complex AI  

> “A statistical anomaly detection system inspired by ML principles, optimized for embedded deployment.”

---

## 🔮 Future Work  

- Implement ML-based anomaly detection (TinyML)  
- Deploy detection on ESP32 (Edge AI)  
- Add real-time alerts  
- Build dashboard visualization  

---

## 🎬 Demo  

🔗 https://youtu.be/AyIpIBVJ50A?si=k9gJisHb_scpT2YA  
<img width="1280" height="960" alt="PowerPulse" src="https://github.com/user-attachments/assets/5dea58d1-f775-419f-b6bd-61aa501e6eda" />

---

## 📦 Setup  

### Hardware  
- Connect sensors to Arduino (A0–A3)  
- Connect loads via DIP switch  
- Use 12V power supply  

### Software  
```bash
pip install pyserial numpy matplotlib

---
