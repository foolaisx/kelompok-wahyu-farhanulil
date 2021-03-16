int led = 11;
int i; // untuk looping
void setup(){
  pinMode(led,OUTPUT);
}
void loop(){
  for(i=0; i<=255; i+=5){ // 0 untuk awal mula lampu mati
    analogWrite(led,i);   // 255 untuk akhir loop dimana lampu akan menyala
    delay(100);           // 5 untuk pertambahan nyala lampu semakin besar semakin terang
  }
  for(i=255; i>=0; i-=5){
    analogWrite(led,i);
    delay(100);
  }
}
