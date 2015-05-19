/* 
 * Author: Davide Fossacecchi
 * a sketch that create a termometer displaying the temperature in the console
 * and using a led array as a scale
 */

const int sensorPin = A0;
float baseline = 20.0;

/* that function gets the digital value of a voltage from 0 to 5V
 * and returns the temperature value in celsius
 */
float value2temp(int sensorValue){
  float voltage = sensorValue * (5.0/1024.0);
  float temp = (voltage - .5) * 100.0;
  return temp;
}

void setup(){
  Serial.begin(9600);
  for (int pin = 3; pin < 6; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  
  int sensorValue = analogRead(sensorPin);
  baseline = value2temp(sensorValue);
  digitalWrite(5,HIGH);
}

void loop(){
  int sensorValue = analogRead(sensorPin);
  float temperature = value2temp(sensorValue);
  Serial.print("temperatura: ");
  Serial.println(temperature);
  //compute the leds that have to be turned on
  if (temperature > (baseline + 2.5)){
   digitalWrite(4, HIGH);
   digitalWrite(3, LOW);
  }
  if (temperature > (baseline + 5.0)) digitalWrite(3, HIGH);
  if (temperature  <= (baseline + 2.5)) {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
}
