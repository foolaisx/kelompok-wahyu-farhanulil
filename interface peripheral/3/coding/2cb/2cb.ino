#include <Keypad.h>
int a=10;
int b=9; 
int c=8;
int d=7;
int e=6;
int f=5;
int g=4;
const byte ROWS = 4;
const byte COLS = 3;
char keymap[ROWS][COLS]={
  {'3','2','1'},
  {'6','5','4'},
  {'9','8','7'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {A1,A2,A3,A4};
byte colPins[COLS] = {11,12,13};

Keypad mkeypad = Keypad( makeKeymap(keymap), rowPins, colPins, ROWS, COLS );

void setup(){
  for(int a=10; a>=4; a--){
    pinMode(a,OUTPUT);
  }
}
void loop(){
  char angka = mkeypad.getKey();
  if(angka == '0'){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,LOW);
  }if(angka == '1'){
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
  }
  if(angka == '2'){
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
  }if(angka == '3'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,LOW); 
    digitalWrite(f,LOW); 
    digitalWrite(g,HIGH);
  }if(angka == '4'){
    digitalWrite(a,LOW); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka == '5'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,LOW); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka == '6'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,LOW); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,HIGH); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }if(angka == '7'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,LOW); 
    digitalWrite(g,LOW);
  }if(angka == '8'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH); 
    digitalWrite(e,HIGH); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  } if(angka == '9'){
    digitalWrite(a,HIGH); 
    digitalWrite(b,HIGH); 
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW); 
    digitalWrite(e,LOW); 
    digitalWrite(f,HIGH); 
    digitalWrite(g,HIGH);
  }
}
