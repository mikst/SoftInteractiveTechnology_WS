/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input
  pinMode(pushButton, INPUT);
  
  //-----new part---------------
  // add output pin
  pinMode(9, OUTPUT);
  //----------------------------
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int buttonState = digitalRead(pushButton);
  // print out the state of the button:
  Serial.println(buttonState);
  
  //-----new part---------------
  // note if it is 0 or 1 if you press the button  
  // if button is pressed (in our case 0)
  if(buttonState==0){
    // output 5V (HIGH) from pin 9
    digitalWrite(9,HIGH);
  }
  // otherwise (meaning it is not pressed), output 0V (LOW) from pin 9
  else digitalWrite(9,LOW);
  //----------------------------
  
  delay(1);        // delay in between reads for stability
}



