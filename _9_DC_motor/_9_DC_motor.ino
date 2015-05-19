/*
 * Author Davide Fossacecchi
 * controls a 9 volts DC motor by a button. The motor is powered by
 * a 9 Volts battery and turned on and off through a MOSFET
 */
const int motorPin = 9;
const int switchPin = 13;

boolean isOn = false;

void setup(){
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop(){
  if (digitalRead(switchPin) == HIGH){
    if (isOn){
      digitalWrite(motorPin, LOW);
      isOn = false;
    }
    else{
      digitalWrite(motorPin, HIGH);
      isOn = true;
    }
  }
}
