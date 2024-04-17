#include <Servo.h>

#define trig 7
#define echo 8

long duration;
int distance;

Servo moteur;
void setup() {
  Serial.begin(9600);
  while(!Serial);
  moteur.attach(3);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  for(int i=15;i<=150;i++){
    moteur.write(i);
    delay(30);
    distance=calculDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println(".");
    
  }
  
  for(int i=150;i>15;i--){
    moteur.write(i);
    delay(30);

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.println
    (".");
  }

}


int calculDistance(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  return distance;
}
