int green_pin = 2;    // Pin for the green LED
int orange_pin = 3;   // Pin for the orange LED
int red_pin = 4;      // Pin for the red LED
int tempPin = A0;     // Analog pin connected to the temperature sensor

void setup() {
  pinMode(green_pin, OUTPUT);    // Set green LED pin as output
  pinMode(orange_pin, OUTPUT);   // Set orange LED pin as output
  pinMode(red_pin, OUTPUT);      // Set red LED pin as output
  Serial.begin(9600);            // Initialize serial communication at 9600 baud rate
}

void loop() {
  int tempValue = analogRead(tempPin);  // Read the analog value from the temperature sensor
  float temp = tempValue * 5000.0 / 1024.0;  // Convert analog value to millivolts
  float temp_C = (temp - 500) / 10;          // Convert millivolts to degrees Celsius

  Serial.println(tempValue);         // Print the raw sensor value
  Serial.print("Temp = ");
  Serial.print(temp_C);               // Print the calculated temperature
  Serial.println("C");

  // Turn on LEDs based on temperature range
  if (temp_C <= 25) {
    digitalWrite(green_pin, HIGH);    // Only green LED ON
    digitalWrite(orange_pin, LOW);
    digitalWrite(red_pin, LOW);
  }
  else if (temp_C > 25 && temp_C <= 35) {
    digitalWrite(green_pin, HIGH);    // Green and Orange LEDs ON
    digitalWrite(orange_pin, HIGH);
    digitalWrite(red_pin, LOW);
  }
  else {
    digitalWrite(green_pin, HIGH);    // All LEDs ON
    digitalWrite(orange_pin, HIGH);
    digitalWrite(red_pin, HIGH);
  }

  delay(1000); // Wait for 1 second before next reading
}
