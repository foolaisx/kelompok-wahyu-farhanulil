char buzzer=A5;
int a=10;
int b=9; 
int c=8;
int d=7;
int e=6;
int f=5;
int g=4;

void setup(){
  for(int a=10; a>=4; a--){
    pinMode(a,OUTPUT);
  }
  pinMode(buzzer,OUTPUT);
}
void loop(){
  for(int i=9; i>=0; i--){
    segment(i);
    delay(1000);
  }
}
void segment(int angka){
  if(angka==0){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
  }if(angka==1){
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  }
  if(angka==2){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }if(angka==3){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,LOW); 
    digitalWrite(f,LOW); 
    digitalWrite(g,HIGH);
  }if(angka==4){
    digitalWrite(a,LOW); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka==5){
    digitalWrite(a,HIGH); 
    digitalWrite(b,LOW); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka==6){
    digitalWrite(a,HIGH); 
    digitalWrite(b,LOW); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,HIGH); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka==7){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,LOW); 
    digitalWrite(g,LOW);
  }if(angka==8){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,HIGH); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  } if(angka==9){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }
}
