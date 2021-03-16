int led1 = 10;
int led2 = 11;
int led3 = 12;
int pot = A0;
int data, i;
void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(pot,INPUT);
}
void loop(){
  data=analogRead(pot);
  data=data/4;
  analogWrite(led1,data);
  analogWrite(led2,data);
  analogWrite(led3,data);
  for(i=0; i<=data; i+=5){
    analogWrite(led1,data);
    analogWrite(led2,data);
    analogWrite(led3,data);
    delay(10);
  }
  for(i=255; i>=data; i-=5){
    analogWrite(led1,data);
    analogWrite(led2,data);
    analogWrite(led3,data);
    delay(10);
  }
  
}
