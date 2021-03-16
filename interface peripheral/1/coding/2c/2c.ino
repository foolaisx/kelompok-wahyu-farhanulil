int led1 = 10;
int led2 = 11;
int led3 = 12;
int i, a;
int led[] = {led1, led2, led3};
void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}
void loop(){
  for(i=0; i <=255; i+=5){
    analogWrite(led1,i);
    analogWrite(led2,i);
    analogWrite(led3,i);
    delay(40);
  }
  
  for(i=255; i >=0; i-=5){
    analogWrite(led1,i);
    analogWrite(led2,i);
    analogWrite(led3,i);
    delay(20);
  }

  for(a=0; a<=2; a++){
    for(i=0; i <=255; i+=5){
      analogWrite(led[a],i);
      delay(10);
    }
  
    for(i=255; i >=0; i-=5){
      analogWrite(led[a],i);
      delay(10);
    }
  }
  
}
