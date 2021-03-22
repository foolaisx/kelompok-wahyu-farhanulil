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

int Kp = 15;
int Kd = 5;
int rate = 0;
int moveControl = 0;
int kecepatanMotorKanan = 0;
int kecepatanMotorKiri = 0;
int kecepatanSetPoint = 150;

int sensor[8];
int NilaiMaxSensor[8];
int NilaiMinSensor[8];
int NilaiTengahSensor[8];

int led1 = 8;
int led2 = 7;
int kondisi[8];

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
  }
}

void loop(){
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
    NilaiTengahSensor[i]= NilaiMinSensor[i]+NilaiMaxSensor[i]/2;
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    delay(1000);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    delay(1000);
  }
  
  String kondisix = String(kondisi[0]+kondisi[1]+kondisi[2]+kondisi[3]+kondisi[4]+kondisi[5]+kondisi[6]+kondisi[7]);

  if(kondisix = "10000000"){
    satu();
  }
  else if(kondisix = "11000000"){
    dua();
  }
  else if(kondisix = "01000000"){
    tiga();
  }
  else if(kondisix = "01100000"){
    empat();
  }
  else if(kondisix = "00100000"){
    lima();
  }
  else if(kondisix = "00110000"){
    enam();
  }
  else if(kondisix = "00010000"){
    tujuh();
  }
  else if(kondisix = "00011000"){
    delapan();
  }
  else if(kondisix = "00001000"){
    sembilan();
  }
  else if(kondisix = "00001100"){
    sepuluh();
  }
  else if(kondisix = "00000100"){
    sebelas();
  }
  else if(kondisix = "00000110"){
    duabelas();
  }
  else if(kondisix = "00000010"){
    tigabelas();
  }
  else if(kondisix = "00000011"){
    empatbelas();
  }
  else if(kondisix = "00000001"){
    limabelas();
  }
  else if(kondisix = "00000000"){
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
  int LastError = -6;
  moveControl = Kp*LastError;
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
  int LastError = -5;
  moveControl = Kp*LastError;
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
  int LastError = -4;
  moveControl = Kp*LastError;
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
  int LastError = -3;
  moveControl = Kp*LastError;
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
  int LastError = -2;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
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
  int LastError = -1;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
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
  int LastError = 0;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
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
  int LastError = 1;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
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
  int LastError = 2;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
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
  int LastError = 3;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint - moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 3");
}
void duabelas(){
  int LastError = 4;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint - moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 4");
}
void tigabelas(){
  int LastError = 5;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint - moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 5");
}
void empatbelas(){
  int LastError = 6;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint - moveControl;
  digitalWrite(mKanan1,HIGH);
  digitalWrite(mKanan2,LOW);
  digitalWrite(mKiri1,HIGH);
  digitalWrite(mKiri2,LOW);
  analogWrite(EnA,kecepatanMotorKanan);
  analogWrite(EnB,kecepatanMotorKiri);
  Serial.println("Error = 6");
}
void limabelas(){
  int LastError = 7;
  moveControl = Kp*LastError;
  kecepatanMotorKanan = kecepatanSetPoint + moveControl;
  kecepatanMotorKiri  = kecepatanSetPoint - moveControl;
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
