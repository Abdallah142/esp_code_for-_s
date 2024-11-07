#define DUSTPIN 35         // Analog pin where the dust sensor (GP2Y1010AU0F) is connected (GPIO 35)
#define LEDPIN 5           // Digital pin to control the LED of the dust sensor (GPIO 5)

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Initialize the LED pin for the dust sensor
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // Reading the dust value from the GP2Y1010AU0F sensor (analog output)
  digitalWrite(LEDPIN, LOW);   // Power on the LED
  delayMicroseconds(280);      // Wait 280 microseconds
  int dustValue = analogRead(DUSTPIN); // Read the dust value
  delayMicroseconds(40);       // Wait 40 microseconds
  digitalWrite(LEDPIN, HIGH);  // Turn off the LED
  delayMicroseconds(9680);     // Wait 9680 microseconds

  // Print the dust value to the serial monitor
  Serial.print("Dust Sensor Value: ");
  Serial.println(dustValue);

  // Wait a few seconds between measurements.
  delay(2000);
}
