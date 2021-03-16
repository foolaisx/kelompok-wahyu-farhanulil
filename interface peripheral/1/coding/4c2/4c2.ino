int led1 = 10;
int led2 = 11;
int led3 = 12;
int i;
int tombol=2;

void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(tombol,INPUT);
}
void loop(){
  if(digitalRead(tombol)==LOW){
    for(i=0; i<=255; i+=5){
      analogWrite(led1,i);
      analogWrite(led2,i);
      analogWrite(led3,i);
      delay(50);
    }
    for(i=255; i>=0; i-=5){
      analogWrite(led1,i);
      analogWrite(led2,i);
      analogWrite(led3,i);
      delay(50);
    }
  }
}
