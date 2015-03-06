int greenLedPin = 6;    // LED connected to digital pin 9
int redLedPin = 5;
boolean isStretched = false;

void setup()  { 
  // nothing happens in setup 
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  pinMode(A5,INPUT_PULLUP);
  Serial.begin(9600);
} 

void loop()  { 

  int sensorValue = analogRead(A5);
  Serial.println(sensorValue);
  
  if(sensorValue>575)
  {
    if(!isStretched)
    {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW); 
      isStretched = true;  // sets the LED on
    }
  }
  else  // waits for a second
  {
    digitalWrite(greenLedPin, HIGH);
    if (isStretched)
    {
      digitalWrite(redLedPin, LOW);
      isStretched = false;
    }
  }    // sets the LED off
  
  delay(500);    
}
