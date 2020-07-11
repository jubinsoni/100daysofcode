int ledArr[10] = {3,4,5,6,7,8,9,10,12,13}; 
int sizeArr = 10;
int button = 2;
int delayTime = 100;
int delaySelected = 2000;
int pushed;
int selected;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Logs");
  pinMode(button,INPUT_PULLUP);
  for(int i=0;i<sizeArr;i++){
    pinMode(ledArr[i],OUTPUT);
  }
}

void loop() {
  selected = -1;
  for(int i=0;i<sizeArr;i++){
    pushed = digitalRead(button);
    digitalWrite(ledArr[i],HIGH);
    if((pushed == LOW)){
      Serial.print(i);
      Serial.println(" => button pushed");
      selected = ledArr[i];
      break;
    }
    else{
      delay(delayTime);
      digitalWrite(ledArr[i],LOW);
      Serial.print(i);
      Serial.println(" => button released");
    }
  }

  if(selected != -1){
    digitalWrite(selected,HIGH);
    delay(delaySelected);
    digitalWrite(selected,LOW);
  }
}