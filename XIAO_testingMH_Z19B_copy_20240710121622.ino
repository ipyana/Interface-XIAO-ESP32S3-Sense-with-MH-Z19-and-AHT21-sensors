#include <HardwareSerial.h>
#include <MHZ19.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

#define RX_PIN D10  // Was 8 before
#define TX_PIN D9  // Was 9 before

HardwareSerial MySerial1(1);  // Use UART1

MHZ19 myMHZ19;  // Constructor for library

unsigned long getDataTimer = 0;

void setup() {
  Serial.begin(115200);  // Initialize the built-in serial port for debugging
  delay(2000);  // Wait for serial to initialize
  Serial.println("Starting MH-Z19B CO2 Sensor Test");

  MySerial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // Initialize UART1
  myMHZ19.begin(MySerial1);  // *Serial(Stream) reference must be passed to library begin().
  myMHZ19.autoCalibration(true);  // Turn auto calibration ON

  Serial.println("Setup complete. Waiting for sensor data...");

  //Checking AHT Sensor
    if (! aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1) delay(10);
  }
}

void loop() {
  if (millis() - getDataTimer >= 5000) {
    int CO2 = myMHZ19.getCO2();  
    if (CO2 > 0) {
      Serial.print("CO2: ");
      Serial.print(CO2);
      Serial.println("ppm");
    } else {
      Serial.println("Failed to read from MH-Z19B sensor!");
    } 

      sensors_event_t humidity, temp;
      aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
      Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
      Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

      Serial.println();
    
    // delay(5000); 
   getDataTimer = millis();
 }
}