// Basic Bluetooth sketch HC-06_01
// Connect the Hc-06 module and communicate using the serial monitor
//
// The HC-06 defaults to AT mode when first powered on.
// The default baud rate is 9600
// The Hc-06 requires all AT commands to be in uppercase. NL+CR should not be added to the command string
//
// Connect the HC-06 TX to the Spresense RX on pin 0.
// Connect the HC-06 RX to the Spresense TX on pin 1.
//

void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");

  // HC-06 default serial speed is 9600
  // If you changed baud rate by using AT command, please edit below.
  Serial2.begin(9600);
}

void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }

}
