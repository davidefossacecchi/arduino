/*
 * Author Davide Fossacecchi
 * a sketch working with Pulse Width Modulation
 */
const int RPinR = A0;
const int GPinR = A1;
const int BPinR = A2;

const int RPinW = 11;
const int GPinW = 9;
const int BPinW = 10;

int RedValue = 0;
int GreenValue = 0;
int BlueValue = 0;

void setup(){
  Serial.begin(9600);
  pinMode(RPinW, OUTPUT);
  pinMode(GPinW, OUTPUT);
  pinMode(BPinW, OUTPUT);
}

void loop(){
  // gets the analog value on three color filtered photoresistors
  RedValue = analogRead(RPinR);
  GreenValue = analogRead(GPinR);
  BlueValue = analogRead(BPinR);
  
  /* uses those values to modulate the pulse width on three pins, dividing
   * the analog read value by 4 cause its maximum is 1024 but the PWM is 255
   */
  analogWrite(RPinW, RedValue/4);
  analogWrite(GPinW, GreenValue/4);
  analogWrite(BPinW, BlueValue/4);
}
