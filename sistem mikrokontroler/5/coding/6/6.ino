int led = 10;
byte sensor = A2;
int nilai;

void setup(){
  pinMode(led,OUTPUT);
}

void loop(){
  nilai = analogRead(sensor);
  for(int i=0; i<=255; i+=5){
      analogWrite(led,i);
      delay(nilai);
    }
    for(int i=255; i>=0; i-=5){
      analogWrite(led,i);
      delay(nilai);
    }
}
