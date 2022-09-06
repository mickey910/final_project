int mic = A1; //mic
void setup() {
  Serial.begin(9600);
  pinMode(mic,INPUT);

}

void loop() {
 int sound = analogRead(mic);//聲響
  Serial.println(sound);
  delay(100);

}
