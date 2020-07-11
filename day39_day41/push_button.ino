void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Logs");
  pinMode(2,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  //pinMode(11,OUTPUT);
  //pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pushed = digitalRead(2);
  if(pushed == LOW){
    digitalWrite(10,HIGH);
    Serial.println("button pushed");
    //digitalWrite(11,HIGH);
    //digitalWrite(12,HIGH);
  }
  else{
    digitalWrite(10,LOW);
    Serial.println("button released");
    //digitalWrite(12,LOW);
  }
}