#include <Servo.h>
Servo servo;
const int echoPin1 = 8; 
const int pingPin1 = 9; 
const int echoPin2 = 6; 
const int pingPin2 = 7; 

#define kp 35
#define ki 0.015
#define kd 420

#define setpoint 20

double priError = 0;
double toError = 0;
float precm1=0;
float precm2=0;
int count = 0;

void setup() {
  servo.attach(5);
  pinMode(4, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(count>5)
  {
    servo.write(135);
    delay(1000);
    servo.write(45);
    delay(1000);
    count=0;
  }
  PID();
  delay(50);
}

void PID() {

   float duration1, cm1;
   pinMode(pingPin1, OUTPUT);
   digitalWrite(pingPin1, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin1, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin1, LOW);
   pinMode(echoPin1, INPUT);
   duration1 = pulseIn(echoPin1, HIGH);
   cm1 = microsecondsToCentimeters(duration1);

   float duration2, cm2;
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration2 = pulseIn(echoPin2, HIGH);
   cm2 = microsecondsToCentimeters(duration2);

float error;

  if(cm1<=cm2)
  {
    error=cm1-setpoint;
  }
  else
  {
    error=40-setpoint-cm2;
  }

if(abs(error-priError)>10)
{
  count=count+1;
  return;
}
count=0;
  
  if(error>=-1.5&&error<=1.5)
  {
    servo.write(98);
    digitalWrite(4, LOW);
    Serial.println(error/5);
    return;
  }
Serial.println(error);  
float Pvalue = error * kp;
float Ivalue = toError * ki;
float Dvalue = (error - priError) * kd;

float PIDvalue = Pvalue + Ivalue + Dvalue;
  
priError = error;
toError += error;
int Fvalue = (int)PIDvalue;
int range = 20*(kp+5);
  if (Fvalue < (-1*range))
  {
     Fvalue = 180;
  }
  else if (Fvalue > range) 
  {
     Fvalue = 30;
  }
  else
  {
    Fvalue = map(Fvalue, (-1*range), range, 175, 8);
    servo.write(Fvalue);
  }
  
digitalWrite(4, HIGH); 
    
}


float microsecondsToCentimeters(float microseconds) {
   return microseconds / 29 / 2;
}
