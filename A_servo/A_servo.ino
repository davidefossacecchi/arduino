/*
 * Author Davide Fossacecchi
 * controls a servo motor by a button that simulates the activation of 
 * a motor neuron
 */
#include <Servo.h>;
const int servoPin = 9;
const int varPin = 10;

boolean contract = false;
int vel = 18; //degrees per tenth of second
int angle = 0;
Servo myServo;

void setup(){
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(angle);
  pinMode(varPin, INPUT);
}

void loop(){
  if (digitalRead(varPin) == HIGH) contract = !contract;
  Serial.println (angle);
  if (contract){
    if(angle < 180) angle += vel;
  }
  else{
    if(angle> 0) angle -= vel;
  }
  myServo.write(angle);
  
}
