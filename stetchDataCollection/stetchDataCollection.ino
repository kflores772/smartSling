
boolean isStretched = false;
int startingValue;
int difference;

void setup()  { 
  // nothing happens in setup 

  pinMode(A0,INPUT_PULLUP);
  Serial.begin(9600);
  startingValue = analogRead(A0);
} 

void loop()  { 

  int sensorValue = analogRead(A0);
  difference = startingValue - sensorValue;
  Serial.print("Starting value: ");
  Serial.print(startingValue);
  Serial.print(" , Sensor value: ");
  Serial.print(sensorValue);
  Serial.print(" , Difference: ");
  Serial.print(difference);
  Serial.println("");
  
  /*if(sensorValue>575)
  {
    if(!isStretched)
    { 
      isStretched = true;
    }
  }
  else  // waits for a second
  {
    if (isStretched)
    {
      isStretched = false;
    }
  }*/  
  
  delay(500);    
}
