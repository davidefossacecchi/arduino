/*
 * Author Davide Fossacecchi
 * a sketch working with Pulse Width Modulation to obtain a glowing
 * effect meant to be used to realize a fantastic clown nose. Three
 * colors of an RGB led are mixed using three cosine function out of 
 * 120° of phase
 */

const int PinR = 11;
const int PinB = 10;
const int PinG = 9;

const int T = 3; //period in seconds

const float phaseR = 0;
const float phaseB = 2*PI/3;
const float phaseG = 4*PI/3;

double t=0;

int potR;
int potB;
int potG;

float valR;
float valB;
float valG;

void setup(){
  Serial.begin(9600);
  pinMode(PinR, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(PinG, OUTPUT);
}

void loop(){
  valR = cos(2*(PI/T)*t + phaseR);
  valB = cos(2*(PI/T)*t + phaseB);
  valG = cos(2*(PI/T)*t + phaseG);
  
  potR = round(valR*127 + 127);
  potB = round(valB*127 + 127);
  potG = round(valG*127 + 127);
  
  Serial.print("Rosso: ");
  Serial.print(potR);
  Serial.print("\tBlu: ");
  Serial.print(potB);
  Serial.print("\tVerde: ");
  Serial.print(potG);
  Serial.print("\tt: ");
  Serial.println(t);
  
  analogWrite(PinR, potR);
  analogWrite(PinB, potB);
  analogWrite(PinG, potG);
  t += 0.016;
  delay(16);
  
}
