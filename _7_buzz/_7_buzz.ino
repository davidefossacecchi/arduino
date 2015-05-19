/*
 * Author Davide Fossacecchi
 * a sketch that uses the map function to get a light signal input 
 * and converting it into a sound
 */
const int buzzPin = 9;
const int varPin = A1;

int potVal = 0;
int nota = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop(){
  potVal = analogRead(varPin);
  Serial.println(potVal);
  nota = map(potVal, 0, 1023, 50, 4000);
  tone(buzzPin, nota, 20);
}
