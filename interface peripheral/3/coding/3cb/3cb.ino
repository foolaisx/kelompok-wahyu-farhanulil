char buzzer=A5;
char button=A0;
void setup(){
  pinMode(button,INPUT);
  pinMode(buzzer,OUTPUT);
}
void loop(){
  if(digitalRead(button)==HIGH){
    for(int i=0; i<=255; i++){
      digitalWrite(buzzer,i);
      delay(100);
    }
  }
}
