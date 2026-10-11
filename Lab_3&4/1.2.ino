void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Set LED pin as output
}

void loop() {
  morseS();  // Send S (···)
  morseO();  // Send O (---)
  morseS();  // Send S (···)
  delay(3000); // Pause before repeating SOS
}

// Function for Morse "S" (···)
void morseS() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // Dot = 0.5s ON
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);  // Pause between dots = 0.5s OFF
    delay(500);
  }
  delay(1000); // Add 1s more for total pause between letters = 1.5s
}

// Function for Morse "O" (---)
void morseO() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // Dash = 1.5s ON
    delay(1500);
    digitalWrite(LED_BUILTIN, LOW);  // Pause between dashes = 0.5s OFF
    delay(500);
  }
  delay(1000); // Add 1s more for total pause between letters = 1.5s
}