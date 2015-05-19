/* 
 * Author: Davide Fossacecchi
 * a simple schetch playing a little with leds, inputs and delays
 */

int bottone = 0;

int pinBtn = 2;
int pinRed1 = 3;
int pinRed2 = 4;
int pinGreen = 5;

void setup(){
  pinMode(pinBtn, INPUT);
  pinMode(pinRed1, OUTPUT);
  pinMode(pinRed2, OUTPUT);
  pinMode(pinGreen, OUTPUT);
}

void loop(){
  //reads the input pulled up by the button
  bottone = digitalRead(pinBtn);
  
  //if the logical state is low, turn on the green led and off the red ones
  if (bottone == LOW){
    digitalWrite(pinGreen, HIGH);
    digitalWrite(pinRed1, LOW);
    digitalWrite(pinRed2, LOW);
  }
   
  else{
      //if the logical state is high, turn on the red ones in sequence
    digitalWrite(pinGreen, LOW);
    digitalWrite(pinRed2, HIGH);
    delay(250);

    digitalWrite(pinRed2, LOW);
    digitalWrite(pinRed1, HIGH);
    delay(250);
    
    digitalWrite(pinRed1, HIGH);
    digitalWrite(pinRed2, HIGH);
    delay(250);
  }
}
