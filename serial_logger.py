import serial
import csv
import time

# ===== SETTINGS =====
PORT = 'COM5'        # change if needed
BAUD = 9600         # or 115200 (match your Arduino code)
OUTPUT_FILE = 'data_log.csv'

# ===== CONNECT SERIAL =====
ser = serial.Serial(PORT, BAUD, timeout=1)
time.sleep(2)  # wait for connection

print("Connected to", PORT)

# ===== OPEN CSV FILE =====
with open(OUTPUT_FILE, mode='w', newline='') as file:
    writer = csv.writer(file)

    # Write header
    writer.writerow(["time", "V1", "V2", "I1", "I2"])

    try:
        while True:
            line = ser.readline().decode('utf-8').strip()

            if line:
                print(line)  # show in terminal

                try:
                    # Expecting: time,V1,V2,I1,I2
                    parts = line.split(',')

                    if len(parts) == 5:
                        writer.writerow(parts)
                        file.flush()  # save immediately

                except:
                    print("Skipping invalid line")

    except KeyboardInterrupt:
        print("\nLogging stopped.")

ser.close()