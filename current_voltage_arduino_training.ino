
//-----TIME VARIABLE--------
int timee = 0;

//-----------START OF VOLTAGE PIN SETUP---------------
const int CurrentSensorPin1 = A2;
const int CurrentSensorPin2 = A3;

// ACS712-30A sensitivity
const float sensitivity = 0.066;   // V/A

float offsetVoltage1 = 2.5;         // Will be calibrated
float offsetVoltage2 = 2.5;         // Will be calibrated

/* Calculate exact values with multimeter:
 * 
 * Vin on adapter = 12.41V
 * Vout on Arduino = 2.42
 * 5V on Arduino = 5.10V
 * 
 * Vin / vOut = factor
 * 12.41 / 2.42 = 5.128
 * 
 */
//-----------END OF VOLTAGE PIN SETUP---------------

//-----------START OF CURRENT PIN SETUP---------------
const int voltageSensorPin1 = A0;          // sensor pin
const int voltageSensorPin2 = A1;          // sensor pin
float vIn;                                // measured voltage (3.3V = max. 16.5V, 5V = max 25V)
float vOut;
float voltageSensorVal1;                   // value on pin A0 (0 - 1023)
float voltageSensorVal2;                   // value on pin A1 (0 - 1023)
const float factor = 5.128;               // reduction factor of the Voltage Sensor shield
const float vCC = 5.00;                   // Arduino input voltage (measurable by voltmeter)
//-----------END OF CURRENT PIN SETUP---------------

void setup() {
  Serial.begin(9600);
  ////----------SETUP is MAINLY for CURRENT SENSOR---------------
  // Calibrate zero current offset
  //Serial.println("Calibrating... Keep load OFF");
  //FORMAT PRINTING
  //Serial.println("time(SECONDS),V1,V2,I1,I2");
  delay(1000);
  
  float sum = 0;
  for (int i = 0; i < 500; i++) {
    int raw = analogRead(CurrentSensorPin1);
    float voltage = raw * (5.0 / 1023.0);
    sum += voltage;
    delay(2);
  }
  offsetVoltage1 = sum / 500.0;

  //Serial.print("Offset Voltage 1: ");
  //Serial.println(offsetVoltage1, 3);

  sum = 0;
  for (int i = 0; i < 500; i++) {
    int raw = analogRead(CurrentSensorPin2);
    float voltage = raw * (5.0 / 1023.0);
    sum += voltage;
    delay(2);
  }
  offsetVoltage2 = sum / 500.0;

  //Serial.print("Offset Voltage 2: ");
  //Serial.println(offsetVoltage2, 3);
}

void loop() {
  //--------TIME COUNTING FOR TRAINING---------
  Serial.print(timee);
  Serial.print(",");
  timee++;
  
  ///------------VOLTAGE MEASURING CODE--------------------
  //-----Voltage Sensor 1----------
  voltageSensorVal1 = analogRead(voltageSensorPin1);    // read the current sensor value (0 - 1023) 
  vOut = (voltageSensorVal1 / 1024) * vCC;             // convert the value to the real voltage on the analog pin
  vIn =  vOut * factor;                               // convert the voltage on the source by multiplying with the factor

  //Serial.print("Voltage 1 = ");             
  Serial.print(vIn);
  Serial.print(",");
  //Serial.println("V");
  //-----Voltage Sensor 2----------
  voltageSensorVal2 = analogRead(voltageSensorPin2);    // read the current sensor value (0 - 1023) 
  vOut = (voltageSensorVal2 / 1024) * vCC;             // convert the value to the real voltage on the analog pin
  vIn =  vOut * factor;                               // convert the voltage on the source by multiplying with the factor

  //Serial.print("Voltage 2 = ");             
  Serial.print(vIn);
  Serial.print(",");
  //Serial.println("V");
  ///--------------END OF VOLTAGE-------------
   //Serial.println("------------------");

   
  //------------CURRENT MEASURING CODE-------------
  //Taking Reading of Current Sensor 1
  float sum = 0;
  
  // Take multiple samples for stability
  for (int i = 0; i < 100; i++) {
    int raw = analogRead(CurrentSensorPin1);
    float voltage = raw * (5.0 / 1023.0);
    sum += voltage;
  }

  float avgVoltage = sum / 100.0;

  // Calculate current
  float current = (avgVoltage - offsetVoltage1) / sensitivity;

  //Serial.print("Current 1 : ");
  Serial.print(current, 3);
  Serial.print(",");
  //Serial.println(" A");

  //delay(500);

  //Taking Reading of Current Sensor 2
  sum = 0;
  // Take multiple samples for stability
  for (int i = 0; i < 100; i++) {
    int raw = analogRead(CurrentSensorPin2);
    float voltage = raw * (5.0 / 1023.0);
    sum += voltage;
  }

  avgVoltage = sum / 100.0;

  // Calculate current
  current = (avgVoltage - offsetVoltage2) / sensitivity;

  //Serial.print("Current 2 : ");
  Serial.print(current, 3);
  Serial.println("");
  //Serial.println(" A");
  //Serial.println("------------------");
  delay(1000);
  //-------------END OF CURRENT---------------
}
