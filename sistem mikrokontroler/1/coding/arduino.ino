int ledG = 10;
int ledY = 11;
int ledR = 12;
void setup(){
  pinMode(ledG,OUTPUT);
  pinMode(ledY,OUTPUT);
  pinMode(ledR,OUTPUT);
}
void loop(){
  digitalWrite(ledR,HIGH);
  delay(3000);
  digitalWrite(ledR,LOW);
  digitalWrite(ledY,HIGH);
  delay(2000);
  digitalWrite(ledY,LOW);
  digitalWrite(ledG,HIGH);
  delay(3000);
  digitalWrite(ledG,LOW);
}
