boolean ison = false;
int difference = 0;
int firstXValue = 0;
int firstYValue = 0;
int refZValue = 0;
int count = 1;
int oldZValue = 0;



void setup()  { 
  // nothing happens in setup 
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  Serial.begin(9600);
  
  firstXValue = analogRead(A3);
  firstYValue = analogRead(A4);
  refZValue = analogRead(A5);
} 

void loop()  { 

  int xValue = analogRead(A3);
  //difference = firstXValue-xValue;
  int yValue = analogRead(A4);
  //difference = firstYValue-yValue;
  int zValue = analogRead(A5);
  
  if (zValue == oldZValue) {
    if (count > 5) {
      refZValue = oldZValue;
      count = 1;
      Serial.println("ref value has changed!"); 
    } else {
      count += 1; 
    }
  } else {
    count = 1;
    oldZValue = zValue; 
  }
  
  difference = refZValue-zValue;


  Serial.print("zvalue difference: ");
  Serial.println(difference);
  //Serial.println("yvalue: ");
  //Serial.print(yValue);
  
  
  /*
  if (xValue == yValue) {
   Serial.println("i am the same"); 
  }*/

  delay(500);    
}
