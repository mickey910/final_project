#include <Servo.h>

Servo myservo;  // 建立一個 servo 物件，最多可建立 12個 servo

int pos = 180;    // 設定 Servo 位置的變數

void setup() {
  myservo.attach(5);  // 將 servo 物件連接到 pin 5
}
void loop() {
  myservo.write(pos);   // 告訴 servo 走到 'pos' 的位置

    delay(15);   // 等待 15ms 讓 servo 走到指定位置
}
