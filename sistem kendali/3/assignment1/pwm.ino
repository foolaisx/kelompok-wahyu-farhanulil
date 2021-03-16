int mKanan1=9;
int mKanan2=10;
int mKiri1=6;
int mKiri2=5;
int EnA= 11;
int EnB= 3;

char p1=A0;
char p2=A1;
char p3=A2;
char p4=A3;
char p5=A4;
char p6=A5;
char p7=7;
char p8=8;

void setup(){

  pinMode(mKanan1,OUTPUT);
  pinMode(mKanan2,OUTPUT);
  pinMode(mKiri1,OUTPUT);
  pinMode(mKiri2,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  
  pinMode(p1,INPUT);
  pinMode(p2,INPUT);
  pinMode(p3,INPUT);
  pinMode(p4,INPUT);
  pinMode(p5,INPUT);
  pinMode(p6,INPUT);
  pinMode(p7,INPUT);
  pinMode(p8,INPUT);
}

void loop(){
  if(digitalRead(p4)==1 && digitalRead(p5)==1){
    empatlima();
  }else{
    if(digitalRead(p1)==1 && digitalRead(p2)==1){
      satudua();
    }else{
      if(digitalRead(p2)==1 && digitalRead(p3)==1){
        duatiga();
      }else{
        if(digitalRead(p3)==1 && digitalRead(p4)==1){
          tigaempat();
        }else{
          if(digitalRead(p7)==1 && digitalRead(p8)==1){
            tujuhdelapan();
          }else{
            if(digitalRead(p6)==1 && digitalRead(p7)==HIGH){
              enamtuju();
            }else{
              if(digitalRead(p5)==1 && digitalRead(p6)==1){
               limaenam(); 
              }
            }
          }
        }
      }
    }
  }
}

void empatlima(){
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,153);
  analogWrite(EnB,153);
}

void satudua(){
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,0);
  analogWrite(EnB,127);
}

void duatiga(){
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,HIGH);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,51);
  analogWrite(EnB,127);
}

void tigaempat(){
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,HIGH);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,102);
  analogWrite(EnB,127);
}

void tujuhdelapan(){
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,127);
  analogWrite(EnB,0);
}

void enamtuju(){
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,HIGH);
  analogWrite(EnA,127);
  analogWrite(EnB,51);
}

void limaenam(){
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,HIGH);
  analogWrite(EnA,127);
  analogWrite(EnB,102);
}
