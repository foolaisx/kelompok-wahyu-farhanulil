int led = 10;
int button1 = 2;
int button2 = 3;
byte buzz = A3;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(buzz,OUTPUT);
}
void loop(){
  if(digitalRead(button1)==LOW){
    digitalWrite(buzz,HIGH);
    digitalWrite(led,LOW);
    delay(1000);
  }
  if(digitalRead(button2)==LOW){
    digitalWrite(buzz,LOW);
    digitalWrite(led,HIGH);
    delay(1000);
  }
}
