/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// few new variables decleard here--------
int thisPitch;
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
  
  // map the sensor input value to a pich range 120 to 1500
  thisPitch = map(sensorValue, 0, 1023, 120, 1500);
  
  // Output sound using tone function
  // first number is the pin number, second, pitch, third duration
  tone(9, thisPitch, 10);
  //--------------------------------------
  
  delay(1);        // delay in between reads for stability
}
