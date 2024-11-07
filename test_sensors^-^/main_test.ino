#include <DHT.h>

// Define the pins
#define DHTPIN 15          // Pin where the DHT sensor is connected (GPIO 15)
#define MQ2PIN 4           // Digital pin where the MQ-2 sensor is connected (GPIO 4)
#define DUSTPIN 35         // Analog pin where the dust sensor (GP2Y1010AU0F) is connected (GPIO 35)
#define LEDPIN 5           // Digital pin to control the LED of the dust sensor (GPIO 5)

// Define the DHT sensor type
#define DHTTYPE DHT11     // DHT 11
// #define DHTTYPE DHT22   // DHT 22 (AM2302), if you are using this model, uncomment this line and comment the above line

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize the MQ-2 sensor pin as input
  pinMode(MQ2PIN, INPUT);

  // Initialize the LED pin for the dust sensor
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  // Reading temperature and humidity values from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // For Celsius
  // float temperature = dht.readTemperature(true); // Uncomment this line for Fahrenheit

  // Reading the gas value from the MQ-2 sensor (digital output)
  int mq2Value = digitalRead(MQ2PIN);

  // Reading the dust value from the GP2Y1010AU0F sensor (analog output)
  digitalWrite(LEDPIN, LOW);   // Power on the LED
  delayMicroseconds(280);      // Wait 280 microseconds
  int dustValue = analogRead(DUSTPIN); // Read the dust value
  delayMicroseconds(40);       // Wait 40 microseconds
  digitalWrite(LEDPIN, HIGH);  // Turn off the LED
  delayMicroseconds(9680);     // Wait 9680 microseconds

  // Check if any reads failed and exit early (to try again)
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    // Print the values to the serial monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("MQ-2 Gas Value: ");
    if (mq2Value == HIGH) {
      Serial.println("Gas detected!");
    } else {
      Serial.println("No gas detected.");
    }

    Serial.print("Dust Sensor Value: ");
    Serial.println(dustValue);
  }

  // Wait a few seconds between measurements.
  delay(2000);
}
