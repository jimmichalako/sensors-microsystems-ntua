void setup() {
  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the built-in LED pin as output
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED ON
  delay(1500);                      // Keep it ON for 1.5 seconds (1500 ms)
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED OFF
  delay(500);                       // Keep it OFF for 0.5 seconds (500 ms)
}