
#include <Ultrasonic.h>
Ultrasonic ultrasonic(2,3);
int distance;
int IN1 = 13;
int IN2 = 12;
int ENA = 11;
int sensor = A0; //光
int mic = A1; //mic
int LED = 4; //警示燈

void setup() {
Serial.begin(9600);
pinMode(ENA,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(sensor,INPUT);
pinMode(mic,INPUT);
pinMode(LED,OUTPUT);
}

void forward() {
analogWrite(ENA,120);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW); 
delay(1000);
}

void sp() {
analogWrite(ENA,0);
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW); 
}

void loop() {
distance = ultrasonic.read(); 
Serial.print("Distance in CM: ");
Serial.println(distance);
delay(500); //每次間格0.5秒
int sensorValue = analogRead(sensor);
Serial.print("sensor");
Serial.println(sensorValue);

if (distance<30){
  digitalWrite(LED,1);
  int sound = analogRead(mic);//聲響
  Serial.print("sound2");
  Serial.println(sound);
  int sensorValue = analogRead(sensor);
  Serial.print("sensor");
  Serial.println(sensorValue);
  if(sensorValue > 950){
  sp();
  digitalWrite(LED,0);  
  }
  if(sound>360){           //??????
    sp();
    digitalWrite(LED,0);
    delay(3000);
  }
}

else{
  digitalWrite(LED,0);
  int sensorValue = analogRead(sensor);
  Serial.print("sensor");
  Serial.println(sensorValue);
  if(sensorValue > 950){   
    distance = ultrasonic.read(); 
    Serial.print("Distance in CM: ");
    Serial.println(distance);
    delay(500); //每次間格0.5秒
    if (distance<30){
      sp();   //馬達停
      delay(2000);
    }
    else{
     forward();  //馬達轉
     delay(1000);
    }
}
}

}
