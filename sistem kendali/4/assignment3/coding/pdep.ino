#include <EEPROM.h>
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

int rate = 0;
int moveControl = 0;
int kecepatanMotorKanan = 0;
int kecepatanMotorKiri = 0;
int kecepatanSetPoint = 150;

int sensor[8];
int NilaiMaxSensor[8];
int NilaiMinSensor[8];
int NilaiTengahSensor[8];

int state =0;
int setting =0;
int peka[8];
int Kp=20;
int Kd=5;
int kondisi[8];

//button
int kirib  = 3;
int kirid  = 2;
int kananb = 12;
int kanand = 11;

//led
int ledkanan = 8;
int ledkiri  = 7;
void setup(){
  Serial.begin(9600);
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

  for(int i=0; i<8; i++){
    NilaiMaxSensor[i]=1023;
    NilaiMinSensor[i]=0;
    peka[i]=500;
  }
   kondisi[0] = digitalRead(p1);
  kondisi[1] = digitalRead(p2);
  kondisi[2] = digitalRead(p3);
  kondisi[3] = digitalRead(p4);
  kondisi[4] = digitalRead(p5);
  kondisi[5] = digitalRead(p6);
  kondisi[6] = digitalRead(p7);
  kondisi[7] = digitalRead(p8);
  
  for(int i=0; i<8; i++){
    sensor[i]==kondisi[i];
    if(sensor[i] > NilaiMinSensor[i]){
      NilaiMinSensor[i] =sensor[i];
    }
    if(sensor[i] < NilaiMaxSensor[i]){
      NilaiMaxSensor[i] =sensor[i];
    }
    NilaiTengahSensor[i]= (NilaiMinSensor[i]+NilaiMaxSensor[i])/2;
  }
  for(int i=0; i<8; i++){
    EEPROM.write(i, NilaiTengahSensor[i]);
    peka[i]=EEPROM.read(i)*4;
    EEPROM.write(8, Kp);
    Kp=EEPROM.read(8);
    EEPROM.write(9, Kd);
    Kd=EEPROM.read(9);
    Serial.print("peka(");
    Serial.print(i);
    Serial.print(") : ");
    Serial.print(peka[i]);
    Serial.print("Kp :");
    Serial.print(Kp);
    Serial.print("Kd :");
    Serial.print(Kd);
    delay(1000);
  }   
}

void loop(){

  if(digitalRead(kirib)==LOW){
    state==1;
  }if(digitalRead(kirid)==LOW){
    state==2;
  }if(digitalRead(kirib)==LOW && setting==1){
    state==3;
  }if(digitalRead(kirid)==LOW && setting==1){
    state==4;
  }if(digitalRead(kananb)==LOW && setting==1){
    state==5;
  }if(digitalRead(kanand)==LOW && setting==1){
    state==6;
  }

  //state
  if(state==1){
    //auto calibration
  }if(state==2){
    for(int i=0; i<8; i++){
      EEPROM.write(i,peka[i]/4);
    }
    EEPROM.write(8,Kd);
    EEPROM.write(9,Kp);
  }if(state==3){
    digitalWrite(ledkiri,HIGH);
    delay(1000);
    digitalWrite(ledkiri,LOW);
    Kp=Kp-1;
    digitalWrite(8,Kp);
  }if(state==4){
    digitalWrite(ledkiri,HIGH);
    delay(1000);
    digitalWrite(ledkiri,LOW);
    Kp=Kp+1;
    digitalWrite(8,Kp);
  }if(state==5){
    digitalWrite(ledkiri,HIGH);
    delay(1000);
    digitalWrite(ledkiri,LOW);
    Kd=Kd-1;
    digitalWrite(9,Kd);
  }if(state==6){
    digitalWrite(ledkiri,HIGH);
    delay(1000);
    digitalWrite(ledkiri,LOW);
    Kd=Kd+1;
    digitalWrite(9,Kd);
  }
  
  String kondisi = String(kondisi[0]+kondisi[1]+kondisi[2]+kondisi[3]+kondisi[4]+kondisi[5]+kondisi[6]+kondisi[7]);

  if(kondisi = "10000000"){
    satu();
  }
  else if(kondisi = "11000000"){
    dua();
  }
  else if(kondisi = "01000000"){
    tiga();
  }
  else if(kondisi = "01100000"){
    empat();
  }
  else if(kondisi = "00100000"){
    lima();
  }
  else if(kondisi = "00110000"){
    enam();
  }
  else if(kondisi = "00010000"){
    tujuh();
  }
  else if(kondisi = "00011000"){
    delapan();
  }
  else if(kondisi = "00001000"){
    sembilan();
  }
  else if(kondisi = "00001100"){
    sepuluh();
  }
  else if(kondisi = "00000100"){
    sebelas();
  }
  else if(kondisi = "00000110"){
    duabelas();
  }
  else if(kondisi = "00000010"){
    tigabelas();
  }
  else if(kondisi = "00000011"){
    empatbelas();
  }
  else if(kondisi = "00000001"){
    limabelas();
  }
  else if(kondisi = "00000000"){
    enambelas();
  }
  
}
void satu(){
  int Error = -7;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -7");
}
void dua(){
  int Error = -6;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -6");
}
void tiga(){
  int Error = -5;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -5");
}
void empat(){
  int Error = -4;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -4");
}
void lima(){
  int Error = -3;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -3");
}
void enam(){
  int Error = -2;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -2");
}
void tujuh(){
  int Error = -1;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = -1");
}
void delapan(){
  int Error = 0;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 0");
}
void sembilan(){
  int Error = 1;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 1");
}
void sepuluh(){
  int Error = 2;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 2");
}
void sebelas(){
  int Error = 3;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 3");
}
void duabelas(){
  int Error = 4;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 4");
}
void tigabelas(){
  int Error = 5;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 5");
}
void empatbelas(){
  int Error = 6;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 6");
}
void limabelas(){
  int Error = 7;
  int LastError = Error;
  int rate = (Error-LastError);
  moveControl = (Kp*Error)+(Kd+rate);
  kecepatanMotorKanan = kecepatanSetPoint - moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint + moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 7");
}
void enambelas(){
  digitalWrite(mKanan1,LOW);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,LOW);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,0);
  analogWrite(EnB,0);
  Serial.println("STOP");
}
