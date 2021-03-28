int led1 = 9;
int led2 = 11;
int led3 = 10;
byte sensor = A2;
int nilai;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop(){
  nilai = analogRead(sensor);
  analogWrite(led1,nilai);
  analogWrite(led3,nilai);
  analogWrite(led2,nilai);
}
