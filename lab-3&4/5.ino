int incomingByte;    // Variable to store incoming serial data
int value;           // Variable to store sensor reading

void setup() {
  pinMode(11, OUTPUT);        // Set pin 11 as an output (for buzzer or LED)
  Serial.begin(9600);         // Start serial communication at 9600 baud
  Serial.println("Please enter A for Analog or D for Digital:");  // Prompt user for input
}

void loop() {
  // Check if data is available in the Serial buffer
  if (Serial.available() > 0) {
    incomingByte = Serial.read();   // Read the incoming byte
    if (incomingByte == 'A') {
      // If 'A' is received, keep running analog mode until new input
      while (Serial.available() == 0) {
        analog();
      }
    }
    else if (incomingByte == 'D') {
      // If 'D' is received, keep running digital mode until new input
      while (Serial.available() == 0) {
        digital();
      }
    }
    else {
      // If an unknown command is received, print an error message
      Serial.println("Unknown command");
    }
  }
}

void analog() {
  value = analogRead(A0);      // Read analog value from sensor (A0)
  Serial.print(value);         // Print raw analog value
  Serial.print("\t");
  
  int analogValue = map(value, 512, 1023, 100, 1000);  // Map value to frequency range for tone
  
  tone(11, analogValue, 20);   // Generate a tone on pin 11 with the mapped frequency for 20 ms
  Serial.println(analogValue); // Print mapped analog value (frequency)
}

void digital() {
  value = analogRead(A0);      // Read analog value from sensor (A0)
  Serial.print(value);         // Print raw analog value
  Serial.print("\t");
  
  boolean digitalValue = map(value, 0, 600, HIGH, LOW);  // Map value to HIGH/LOW digital output
  
  digitalWrite(11, digitalValue); // Set pin 11 HIGH or LOW based on mapped value
  Serial.println(digitalValue);   // Print digital value (1 or 0)
}
