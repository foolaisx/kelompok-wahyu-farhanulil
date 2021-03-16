int led = 11; //pin arduino yg terhubung dengan led
int tombol=2; // pin arduino yg tehubung dengan push button

void setup(){
  pinMode(led,OUTPUT);
  pinMode(tombol,INPUT);
}
void loop(){
  if(digitalRead(tombol)==LOW){ //jika tombol ditekan/nilainya menjadi low
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
  }
}
