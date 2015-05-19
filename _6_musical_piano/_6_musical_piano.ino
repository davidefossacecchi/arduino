/*
 * Author Davide Fossacecchi
 * a sketch working with in scale resistances network, tone function
 * and arrays to create a kind of musical piano
 */

const int notes[] = {262, 294, 330, 349};
int keyVal;

void setup(){
}

void loop(){
  keyVal = analogRead(A0);
  
  if (keyVal == 1023) tone(8, notes[0]);
  else if (keyVal >= 990 && keyVal <= 1010) tone(8, notes[1]);
  else if (keyVal >= 505 && keyVal <= 515) tone(8, notes[2]);
  else if (keyVal >= 5 && keyVal <= 10) tone(8, notes[3]);
  else noTone(8);
}
