int led = 11; // pin arduino yg tehubung ke led
int pot = A0; // pin arduino yang terhubung ke potensio
int data;
void setup(){
  pinMode(led,OUTPUT);
  pinMode(pot,INPUT); // potensio sebagai inputan
}
void loop(){
  data=analogRead(pot);
  data=data/4; // pembagian data persenan, semakin besar semakin terang led, semakin kecil semakin redup led
  analogWrite(led,data);
}
