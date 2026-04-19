# ⚡ Electricity Monitoring & Optimization Assistant  
### Data Acquisition & Lightweight Anomaly Detection Prototype for Physical AI

---

## 🧠 Overview  
This project is a **room-level electricity monitoring system** that measures and logs real-time **voltage and current** from two separate circuits (simulating two rooms).

In addition to data collection, the system performs **basic statistical anomaly detection on power consumption**, demonstrating early-stage intelligence without heavy AI models.

---

## 👥 Team  
**Team Name:** *(Add your team name)*  

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

## 🔌 System Architecture  
