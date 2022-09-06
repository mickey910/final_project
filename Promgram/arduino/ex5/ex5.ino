#include <Servo.h>
Servo myservo; 
#include <Ultrasonic.h>
Ultrasonic ultrasonic(2,3);
int distance;
int IN1 = 13;
int IN2 = 12;
int ENA = 11;
int IN3 = 8;
int IN4 = 9;
int ENB = 10;
int sensor = A0; //光
int mic = A1; //mic
int LED = 4; //警示燈
int rpos = 180;
int lpos = 0;
int pos = 90;

void setup() {
myservo.attach(5);  // 將 servo 物件連接到 pin 5
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
analogWrite(ENB,120);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);  

}

void sp() {
analogWrite(ENA,0);
analogWrite(ENB,0);
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);  
}

void loop() {
distance = ultrasonic.read(); //不加參數就是輸出CM，可用read(INC)輸出英寸
Serial.print("Distance in CM: ");
Serial.println(distance);
delay(500); //每次間格0.5秒

if (distance<30){
  digitalWrite(LED,1);
  forward();
  int sound = analogRead(mic);//聲響
  Serial.println(sound);
  int sensorValue = analogRead(sensor);//光
  Serial.println(sensorValue);
  if(sound>350){           //??????
    myservo.write(lpos);    // 告訴 servo 走到 'lpos' 的位置
    delay(1000);        // 等待 15ms 讓 servo 走到指定位置
  }
  if(sensorValue > 850){   //當光敏電阻給的值大於基準值。這個基準值依個別情況修改 ???????
    myservo.write(rpos);    // 告訴 servo 走到 'rpos' 的位置
    delay(1000);        // 等待 15ms 讓 servo 走到指定位置
  }
}

else{
  sp();
  digitalWrite(LED,0);
   myservo.write(pos);    // 告訴 servo 走到 'rpos' 的位置
    delay(1000);        // 等待 15ms 讓 servo 走到指定位置
}


}
