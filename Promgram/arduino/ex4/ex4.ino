const int BUTTON_PIN = 10;  // 按鍵的接腳
const int BLUE_PIN =  3;   // LED燈的接腳
const int RED_PIN =  2;   // LED燈的接腳
int CDSPin = A0; // 光敏電阻接在A0接腳
int sensor = A1;
int CDSVal = 0; // 設定初始光敏電阻值為0
int buttonState = 0;   // 按鈕的狀態
const byte EA = 6; // 馬達 A 的致能接腳
const byte IA1 = 7; // 馬達 A 的正反轉接腳
const byte IA2 = 8; // 馬達 A 的正反轉接腳
const byte EB = 5; // 馬達 B 的致能接腳
const byte IB1 = 4; // 馬達 B 的正反轉接腳
const byte IB2 = 9; // 馬達 B 的正反轉接腳
const byte speed = 130;
#include "Timer.h" 

Timer t;  //建立Timer物件
int count=0;

void WriteToSerial(){
  Serial.println(count);
  count++;
}
void setup() {
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);   //設定LED的PIN腳為輸出
  pinMode(BUTTON_PIN, INPUT); //設定按鈕的接腳為輸入，因為我們要讀取它的狀態
  Serial.begin(9600);
  t.every(1000,WriteToSerial); // 每1000ms呼叫WriteToSerial
  pinMode(IA1, OUTPUT); // 馬達 A 的正反轉接腳
  pinMode(IA2, OUTPUT); // 馬達 A 的正反轉接腳
  pinMode(IB1, OUTPUT); // 馬達 B 的正反轉接腳
  pinMode(IB2, OUTPUT); // 馬達 B 的正反轉接腳
  analogWrite(EA, 0); // 馬達 A 的 PWM 輸出
  analogWrite(EB, 0); // 馬達 B 的 PWM 輸出; // 先停止馬達
  pinMode(sensor,INPUT);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);  //讀取按鍵的狀態
  Serial.print("buttonState");
  Serial.println(buttonState);
  
  while(buttonState == LOW){          //如果按鍵按了
    
    t.update(); //更新t
    analogWrite(EA, speed); // 馬達 A 的 PWM 輸出
    digitalWrite(IA1, HIGH);
    digitalWrite(IA2, LOW);
    analogWrite(EB, speed); // 馬達 B 的 PWM 輸出
    digitalWrite(IB1, HIGH);
    digitalWrite(IB2, LOW);
    if(count>=5){
      CDSVal = analogRead(CDSPin);
      Serial.print("CDSVal");
      Serial.println(CDSVal);
      int sensorValue = analogRead(sensor);
      Serial.print("sensorValue");
      Serial.println(sensorValue);
      while(CDSVal>850){
        analogWrite(EA, 0); // 馬達 A 的 PWM 輸出
        analogWrite(EB, 0); // 馬達 B 的 PWM 輸出
        digitalWrite(BLUE_PIN,HIGH);
        delay(100); //延遲0.1秒
        digitalWrite(BLUE_PIN,LOW); 
        delay(100); //延遲0.1秒
      }
      while(sensorValue > 300){   //當音量超過一定數值，這個數值依個別情況修改
        digitalWrite(RED_PIN,HIGH);
        delay(100); //延遲0.1秒
        digitalWrite(RED_PIN,LOW); 
        delay(100); //延遲0.1秒
        analogWrite(EA, speed); // 馬達 A 的 PWM 輸出
        digitalWrite(IA1, LOW);
        digitalWrite(IA2, HIGH);
        analogWrite(EB, speed); // 馬達 B 的 PWM 輸出
        digitalWrite(IB1, LOW);
        digitalWrite(IB2, HIGH);
      }
      delay(2000); //每2s讀取一次 
    }   
}
  
}
