// Pressure sensor program - Bryan Rutter - K-State Research and Extension Soil Testing Laboratory - 2024

#include <SoftwareSerial.h>
#define RX 0
#define TX 1
SoftwareSerial mySerial(RX, TX);

const int SensorPin = A0;  // Analog input pin 
int sensorValue = 0;       // value read from the sensor
float outputValue = 0;     // value output 
float pressurevalue = 0;   // value of pressure


void setup() {
  // initialize serial communications at 9600 bps:
  mySerial.begin(9600);
  mySerial.print("");
}

void loop() {
  // read the analog input value:
  sensorValue = analogRead(SensorPin);
  // convert the reading to voltage:
  outputValue = sensorValue * (5 / 1023.0);
  // convert from voltage to pressre (kPa):
  pressurevalue = ((outputValue - 2.5) / 0.09);

  // output the results to the Serial Monitor:
  mySerial.println(pressurevalue);

  // wait 1000 milliseconds (1 second) before the next loop. This can be reduced, but must be >=100 ms for the analog-to-digital converter to stabilize after the last reading:
  delay(1000);

}
