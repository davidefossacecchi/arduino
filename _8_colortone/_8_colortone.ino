/*
 * Author Davide Fossacecchi
 * get three light signals filtered in blue, red and green frequencies
 * mixes them to obtain a tone and uses them to light up an RGB led
 */
const int buzzPin = 11;

const int PinR = 6;
const int PinB = 9;
const int PinG = 10;

const int varPinR = A5;
const int varPinB = A4;
const int varPinG = A3;

int potR = 0;
int potB = 0;
int potG = 0;

int potRref = 0;
int potBref = 0;
int potGref = 0;

int sum = 0;
int sumRef = 0;
int nota = 0;

void setup(){
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  
  pinMode(PinR, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(PinG, OUTPUT);
  
  potRref = analogRead(varPinR);
  potBref = analogRead(varPinB);
  potGref = analogRead(varPinG);
  
  sumRef = sum = (potRref/4) + (potBref/3) + (potGref/2);
  
  Serial.print("Rosso: ");
  Serial.print(potRref);
  Serial.print("\tBlu: ");
  Serial.print(potBref);
  Serial.print("\tVerde: ");
  Serial.println(potGref);
  
}

void loop(){
  potR = analogRead(varPinR);
  potB = analogRead(varPinB);
  potG = analogRead(varPinG);
  
  /*Serial.print("Rosso: ");
  Serial.print(potR);
  Serial.print("\tBlu: ");
  Serial.print(potB);
  Serial.print("\tVerde: ");
  Serial.println(potG);*/
  if ((potR < (potRref - 80)) || (potR > (potRref + 80))) analogWrite(PinR, potR/4);
  else analogWrite(PinR, 0);

  if ((potB < (potBref - 80)) || (potB > (potBref + 80))) analogWrite(PinB, potB/4);
  else analogWrite(PinB, 0);
  
  if ((potG < (potGref - 80)) || (potG > (potGref + 80))) analogWrite(PinG, potG/4);
  else analogWrite(PinG, 0);
  
  //arbitrary mix function
  sum = (potR/4) + (potB/3) + (potG/2);
  
  nota = map(sum, 0, 896, 0, 4000);
  Serial.println(sum);
  tone(buzzPin, nota, 20);
}
