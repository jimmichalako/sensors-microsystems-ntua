const int ledPin = 13;  // Pin number where the LED is connected
int incomingByte;       // Variable to store incoming serial data

void setup() {
  Serial.begin(9600);           // Start serial communication at 9600 baud
  pinMode(ledPin, OUTPUT);      // Set the LED pin as an output
}

void loop() {
  // Check if any data is available to read from the serial buffer
  if (Serial.available() > 0) {
    incomingByte = Serial.read();  // Read the incoming byte

    // Turn the LED on if the input is 'H' or 'h'
    if (incomingByte == 'H' || incomingByte == 'h') {
      digitalWrite(ledPin, HIGH);
    }
    // Turn the LED off if the input is 'L' or 'l'
    else if (incomingByte == 'L' || incomingByte == 'l') {
      digitalWrite(ledPin, LOW);
    }
    // If any other character is received, print an error message
    else {
      Serial.println("Error!");
    }
  }
}