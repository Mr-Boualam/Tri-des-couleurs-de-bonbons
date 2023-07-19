#include <Servo.h>
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
Servo m1;
Servo m2;

int frequency = 0;
int color = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  m1.attach(7);
  m2.attach(8);
  Serial.begin(9600);
 

 
}

void loop() {
  // put your main code here, to run repeatedly:
  m1.write(0);
  delay(3000);

  for(int i =0 ;i <= 43; i++) {
  m1.write(i);
  delay(2);  
  }
  delay(3000);

  color = readColor();
  delay(10);
  switch (color) {
    case 1:
    m2.write(0);
    break;
    case 2:
    m2.write(45);
    break;
    case 3:
    m2.write(90);
    break;
    case 0:
    break;
  }
  delay(300);
  
  for(int i =43 ;i <= 140; i++) {
  m1.write(i);
  delay(2);
  }
  delay(3000);

  for(int i =140 ;i >= 0; i--) {
  m1.write(i);
  delay(2);
  }
  color=0;
  
}

int readColor() {

  //setting red 
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(sensorOut, LOW);
  int R = frequency;
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print(" ");
  delay(50);

  //setting green 
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int G = frequency;
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print(" ");
  delay(50);

  //setting blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(sensorOut, LOW);
  int B = frequency;
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.print(" ");
  delay(50);
  
  if(R<35 & R>27 & G<50 & G>45 & B<43 & B>37 ) {
    color = 1; // Red
  }

    if(R<33 & R>30 & G<46 & G>43 & B<38 & B>35) {
   }
    color = 2; // Green 
  
  
  return color;
  
}
