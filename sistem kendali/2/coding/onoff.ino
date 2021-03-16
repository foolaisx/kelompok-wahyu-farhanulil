int mKanan1=10;
int mKanan2=9;
int mKiri1=6;
int mKiri2=5;

char p1=A0; // kiri
char p2=A1; // kiri
char p3=A2; // tengah
char p4=A3; // tengah
char p5=A4; // kanan
char p6=A5; // kanan

int led1=7;  // kanan
int led2=8;  // kiri
int led3=13; // tengah

void setup() {
  pinMode(mKanan1,OUTPUT);
  pinMode(mKanan2,OUTPUT);
  pinMode(mKiri1,OUTPUT);
  pinMode(mKiri2,OUTPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(p4,INPUT);
  pinMode(p5,INPUT);
  pinMode(p6,INPUT);
}

void loop(){
  if(digitalRead(p3) == 1 && digitalRead(p4) == 1){
    maju();
  }else{
    if(digitalRead(p1) == 1 && digitalRead(p2) == 1){
      kiri();
    }else{
      if(digitalRead(p5) == 1 && digitalRead(p6) == 1){
        kanan();
      }else{
        if(digitalRead(p1) == 0 && digitalRead(p2) == 0 && digitalRead(p3) == 0 && digitalRead(p4) == 0 && digitalRead(p5) == 0 && digitalRead(p6) == 0){
          berhenti();
        }
      }
    }
  }
}

void maju(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
}

void kanan(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
}

void kiri(){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,LOW);
}

void berhenti(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,LOW);
}
