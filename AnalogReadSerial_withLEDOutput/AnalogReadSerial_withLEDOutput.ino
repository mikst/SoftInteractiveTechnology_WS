/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// few new variables decleard here--------
int lightIntensity;
int sensorValue;
// -------------------------------------

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  
  //-----added new-------------------------
  
  // map the sensor input value to light intensity range 0-255
  lightIntensity = map(sensorValue, 0, 1023, 0, 255);
  // make sure that the value does not go out of the range 0-255
  lightIntensity =constrain(lightIntensity, 0,255);
  
  // Output sound using analogWirte function. it outputs PWM
  // analogWrite is only possible with PWM pins (marked ~)
  analogWrite(9,lightIntensity);
  
  //--------------------------------------
  
  delay(1);        // delay in between reads for stability
}
