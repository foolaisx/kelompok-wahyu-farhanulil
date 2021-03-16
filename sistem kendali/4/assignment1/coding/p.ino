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

int Kp = 5;
int moveControl = 0;
int error = 0;
int kecepatanMotorKanan = 0;
int kecepatanMotorKiri = 0;
int kecepatanSetPoint = 150;

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
}

void loop(){
  int kondisi1 = digitalRead(p1);
  int kondisi2 = digitalRead(p2);
  int kondisi3 = digitalRead(p3);
  int kondisi4 = digitalRead(p4);
  int kondisi5 = digitalRead(p5);
  int kondisi6 = digitalRead(p6);
  int kondisi7 = digitalRead(p7);
  int kondisi8 = digitalRead(p8);
  
  String kondisi = String(kondisi1+kondisi2+kondisi3+kondisi4+kondisi5+kondisi6+kondisi7+kondisi8);

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
  int LastError = -7;
  moveControl = Kp*LastError;
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
