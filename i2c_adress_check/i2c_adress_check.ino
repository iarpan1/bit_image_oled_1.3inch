#include <Wire.h>

void setup() {
  Wire.begin();            // Initialize I2C
  Serial.begin(115200);    // Start serial monitor
  while (!Serial);         // Wait for Serial
  Serial.println("I2C Scanner Starting...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning...");

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    } 
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }    
  }
  if (nDevices == 0) Serial.println("No I2C devices found\n");
  else Serial.println("Done scanning\n");

  delay(5000); // Scan every 5 seconds
}
