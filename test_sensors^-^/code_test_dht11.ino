#include <DHT.h>

// Define the pin where the DHT sensor is connected
#define DHTPIN 15          // GPIO 15

// Define the DHT sensor type
#define DHTTYPE DHT11     // DHT 11
// #define DHTTYPE DHT22   // DHT 22 (AM2302), if you are using this model, uncomment this line and comment the above line

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize the serial monitor
  Serial.begin(115200);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Reading temperature and humidity values from the DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // For Celsius
  // float temperature = dht.readTemperature(true); // Uncomment this line for Fahrenheit

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
  }

  // Wait a few seconds between measurements.
  delay(2000);
}
