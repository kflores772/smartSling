int stretchInput = A0; // the stretch value increases as it is stretched
int stretchRef = 0;
int stretchCount = 0;
int stretchCur = 0;
int stretchPrev = 0;
int stretchThreshold = 0; 
int MENS = 13;
boolean isStretched = false;

int xAxis = A3;
int yAxis = A4;
int zAxis = A5;
int xRef = 0;
int yRef = 0;
int zRef = 0;
int xValue = 0;
int yValue = 0;
int zValue = 0;
int xValueOld = 0;
int yValueOld = 0;
int zValueOld = 0;
int zCount = 0;
int difference = 0;
boolean isMoving = false;

void setup()  { 
  // nothing happens in setup 
  pinMode(MENS, OUTPUT);
  pinMode(stretchInput,INPUT_PULLUP);
  stretchRef = analogRead(stretchInput);
  digitalWrite(MENS, LOW); //op amp input default to low
  
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);
  pinMode(zAxis, INPUT);
  xRef = analogRead(xAxis);
  yRef = analogRead(yAxis);
  zRef = analogRead(zAxis);
  Serial.begin(9600);
} 

void loop()  {
  checkMovement();
  
  if (isMoving == false) {
    calcStretchThreshold();
    stretchCur = analogRead(stretchInput);
    Serial.print("Ref value: ");
    Serial.print(stretchRef);
    Serial.print(" current stretch: ");
    Serial.print(stretchCur);
    Serial.println(" ");
    
    normalizeStretchRef();
    
    if (stretchCur>stretchThreshold) {
      if (!isStretched) {
        Serial.println("The stretch sensor has passed its threshold");
        digitalWrite(MENS, HIGH);
        //digitalWrite(greenLedPin, LOW); 
        isStretched = true;  // sets the LED on
      }
    } else {
      //digitalWrite(greenLedPin, HIGH);
      if (isStretched) {
        digitalWrite(MENS, LOW);
        isStretched = false;
      }
    }    // sets the LED off
    
    stretchPrev = stretchCur;
  }
  delay(500);    
}

void checkMovement() {
  xValue = analogRead(xAxis);
  yValue = analogRead(yAxis);
  zValue = analogRead(zAxis);
  
  if (zValue == zValueOld) {
    if (zCount > 5) {
      zRef = zValueOld;
      zCount = 1;
      Serial.println("ref value has changed!"); 
    } else {
      zCount += 1; 
    }
  } else {
    zCount = 1;
    zValueOld = zValue; 
  }
  
  difference = zRef-zValue;

  Serial.print("zvalue difference: ");
  Serial.println(difference);
  
  if (difference>=100) {
    isMoving = true;
    digitalWrite(MENS, LOW);
  } else {
    isMoving = false;
  }
}
/*
 * This function calculates the stretchThreshold
 */
void calcStretchThreshold () {
  stretchThreshold = stretchRef + 10;
}

/*
 * This function compares the current stretch value with the previous value.
 * If the values are the same and do not equal the reference value then increase
 * the count. If the count equals or exeeds the variable 'run' then make
 * that value the new reference.
 */
void normalizeStretchRef () {
  int run = 7; // the amount of times the prev and cur strech value can equal.
  
  if (!isStretched) {
    if (stretchCur != stretchRef) {
      if (stretchCur == stretchPrev) {
        if (stretchCount >= run) {
          stretchRef = stretchCur;
          Serial.println("REFERENCE STRETCH CHANGED");
          stretchCount = 1;
        } else {
          stretchCount = stretchCount + 1; 
        }
      } else {
        stretchCount = 1;
      }
    }
  }
}

