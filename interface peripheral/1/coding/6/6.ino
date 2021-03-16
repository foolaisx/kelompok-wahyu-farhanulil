int led1 = 10;
int led2 = 11;
int led3 = 12;
int pot = A0;
int tombol = 2;
int data,i;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pot,INPUT);
  pinMode(tombol,INPUT);
}
void loop(){
  if(digitalRead(tombol)==LOW){
    data=analogRead(pot);
    data=data/4;
    analogWrite(led1,data);
    analogWrite(led2,data);
    analogWrite(led3,data);
    delay(1000);
    for(i=255; i>=0; i-=5){
      analogWrite(led1,i);
      analogWrite(led2,i);
      analogWrite(led3,i);
      delay(100);
    }
    delay(500);
  }else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
}
