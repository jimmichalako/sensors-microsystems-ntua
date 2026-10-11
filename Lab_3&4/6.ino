#include <dht.h>  // Include DHT library for reading temperature and humidity

// Pin definitions
#define trigPin 9        // Trigger pin of ultrasonic sensor
#define echoPin 10       // Echo pin of ultrasonic sensor
#define DHT11_PIN 2      // Data pin for DHT11 sensor
#define BUZZER_PIN 8     // Pin connected to the buzzer

// Variables for sensor measurements
float duration, distance;
float sound_speed;
float temp, hmdt;

// Variables for timing
unsigned long previousMillis = 0;  // Stores the last time sensor data was read
const long interval = 2000;         // Interval between readings (2 seconds)

dht DHT;  // Create DHT sensor object

void setup() {
  pinMode(trigPin, OUTPUT);       // Set trigger pin as output
  pinMode(echoPin, INPUT);         // Set echo pin as input
  pinMode(DHT11_PIN, INPUT);       // DHT11 pin as input (even though DHT library handles it)
  pinMode(BUZZER_PIN, OUTPUT);     // Set buzzer pin as output
  Serial.begin(9600);              // Initialize serial communication at 9600 baud
}

void loop() {
  unsigned long currentMillis = millis();  // Get the current time

  // Only proceed if 2 seconds have passed
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Update last reading time

    // Read temperature and humidity from DHT11 sensor
    int chk = DHT.read11(DHT11_PIN);
    temp = DHT.temperature;
    hmdt = DHT.humidity;

    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the duration of echo pulse
    duration = pulseIn(echoPin, HIGH);

    // Calculate speed of sound based on temperature and humidity
    sound_speed = 331.4 + (0.606 * temp) + (0.0124 + 0.000058 * hmdt) * temp;

    // Calculate distance based on duration and speed of sound
    distance = (duration / 2) * (sound_speed / 10000);  // Convert to centimeters

    // Check if distance is within valid range
    if (distance < 400 && distance > 2) {
      Serial.print(distance);
      Serial.println(" cm");

      // If object is closer than 10 cm, turn on buzzer
      if (distance < 10) {
        digitalWrite(BUZZER_PIN, HIGH);
      } else {
        digitalWrite(BUZZER_PIN, LOW);
      }

    } else {
      Serial.println("Out of range");
      digitalWrite(BUZZER_PIN, LOW);  // Turn off buzzer if out of range
    }

    // Print temperature and humidity
    Serial.print(temp);
    Serial.println(" C");
    Serial.print(hmdt);
    Serial.println(" %");
    Serial.println("===========");
  }
}
