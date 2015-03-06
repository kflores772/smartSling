boolean ison = false;


void setup()  { 
  // nothing happens in setup 
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  
} 

void loop()  { 

  int xValue = analogRead(A3);
  int yValue = analogRead(A4);
  int zValue = analogRead(A5);


  //Serial.println("xvalue:");
  //Serial.println(xValue);
  //Serial.println("yvalue:");
  Serial.println(yValue);
  
  
  /*
  if (xValue == yValue) {
   Serial.println("i am the same"); 
  }*/

  delay(500);    
}
