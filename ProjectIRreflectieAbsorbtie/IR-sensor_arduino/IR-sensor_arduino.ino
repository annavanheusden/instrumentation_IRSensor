  /*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
boolean startUp = false;
char inCom="";
double ref = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  while(!startUp)
  {
    if(Serial.available()>0)
    {
      inCom = Serial.read();
      
      startUp = true;
      Serial.println(inCom);
    }
  }
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  double sensorValue = analogRead(A0);
  if(Serial.available()>0)
    {
      ref = Serial.readString().toDouble();
    }

  if (ref<sensorValue){
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
    }
    else if(ref>sensorValue){
      digitalWrite(3,LOW);
      digitalWrite(4,HIGH);
    }
    else if(ref==-1){
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
    }
   
  // print out the value you read:
  Serial.println(sensorValue);
  delay(250);        // delay in between reads for stability
}
