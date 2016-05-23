/*
CSCI 3410 
Homework 4
Objective: Write a Sketch that reads the value presented to A0 and drive an RGB LED through a range of
prescribed colors to correspond to the derived digital numeric value. In addition, capture the actual
numeric value and view the updates live using the Serial Monitor within the Arduino IDE.
*/

int bluePin = 10;
int greenPin = 11;
int potentPin = A0;
int redPin = 9;
int value = 0;

void setup() {
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   
  Serial.begin(9600);
}

void loop() {
  
  value = analogRead(potentPin);
  Serial.println(value);
  
  //red
  if(value >= 950) {
    value = map(value, 950, 1023, 0, 255);
    analogWrite(redPin, value);
    analogWrite(greenPin, 255-value);
    analogWrite(bluePin, 255);
  }
  
  //orange
  else if(value >= 700 && value <=949) {
    value = map(value, 700, 949, 0, 255);
    analogWrite(redPin, value);
    analogWrite(greenPin, 255-value);
    analogWrite(bluePin, 255);
  }
  
  //yellow
  else if(value >= 400 && value <= 699) {
    value = map(value, 400, 699, 0, 255);
    analogWrite(redPin, value);
    analogWrite(greenPin, 255-value);
    analogWrite(bluePin, 255);
  }
  
  //green
  else if(value >= 300 && value <= 399) {
    value = map(value, 300, 399, 0, 255);
    analogWrite(greenPin, value);
    analogWrite(bluePin, 255-value);
    analogWrite(redPin, 255);
  }
  
  //blue
  else {
    value = map(value, 0, 199, 0, 255);
    analogWrite(bluePin, value);
    analogWrite(redPin, 255-value);
    analogWrite(greenPin, 255);
  }
  
  delay(500);
  Serial.println(sensorValue);
  delay(1000);
} 
