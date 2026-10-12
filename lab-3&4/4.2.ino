int pin = A0;         // Input pin for the Hall sensor
int led = 3;          // Output pin for the LED
int vcc = 5000;       // Supply voltage for the Hall sensor in millivolts (mV)

int value;            // Variable to store the analog reading (0-1023)
int voltage;          // Variable to store the voltage value in mV
int field;            // Variable to store the magnetic field value in millitesla (mT)

void setup() {
  pinMode(led, OUTPUT);    // Set the LED pin as an output
  Serial.begin(9600);      // Start serial communication at 9600 baud
}

void loop() {
  value = analogRead(pin); // Read the analog value from the Hall sensor
  
  // Convert the analog value to voltage (in mV)
  voltage = value * (vcc / 1024.0); 
  
  // Calculate the magnetic field strength in millitesla (mT)
  field = map(voltage, 1000, 4000, -100, 100); 
  
  field--; // Apply a correction by decreasing the field value by 1 mT

  // Check if the magnetic field is greater than +5 mT or less than -5 mT
  if (field > 5 || field < -5) {
    digitalWrite(led, HIGH); // Turn on the LED if the magnetic field is strong
  }
  else {
    digitalWrite(led, LOW);  // Turn off the LED if the magnetic field is weak
  }

  // Print the sensor reading, voltage, and magnetic field to the Serial Monitor
  Serial.print("Value: ");
  Serial.print(value);       // Print the raw analog value (0-1023)
  Serial.print("\t");
  Serial.print(voltage);     // Print the voltage in millivolts
  Serial.println(" mV");
  Serial.print("Magnetic Field: ");
  Serial.print(field);       // Print the calculated magnetic field value
  Serial.println(" mT");
  Serial.println("=========================="); // Separator line for readability
  
  delay(1000); // Wait 1 second before taking the next reading
}
