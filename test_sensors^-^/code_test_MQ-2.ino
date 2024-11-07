#define MQ2PIN 4  // Digital pin where the MQ-2 sensor is connected (GPIO 4)

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Initialize the MQ-2 sensor pin as input
  pinMode(MQ2PIN, INPUT);
}

void loop() {
  // Reading the gas value from the MQ-2 sensor (digital output)
  int mq2Value = digitalRead(MQ2PIN);

  // Print the MQ-2 gas value to the serial monitor
  Serial.print("MQ-2 Gas Value: ");
  if (mq2Value == HIGH) {
    Serial.println("Gas detected!");
  } else {
    Serial.println("No gas detected.");
  }

  // Wait a few seconds between measurements.
  delay(2000);
}
