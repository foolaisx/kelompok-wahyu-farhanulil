#include <LiquidCrystal_SR_LCD3.h>
#include <Keypad.h>
int a=10;
int b=9; 
int c=8;
int d=7;
int e=6;
int f=5;
int g=4;

char buzzer=A5;
char button=A0;

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

const int PIN_LCD_STROBE = 1; 
const int PIN_LCD_DATA = 3; 
const int PIN_LCD_CLOCK = 2;

LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,PIN_LCD_CLOCK,PIN_LCD_STROBE);

char nomer[12];

void setup(){
  for(int a=10; a>=4; a--){
    pinMode(a,OUTPUT);
  }
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT);
  lcd.begin(16,2);
}
void loop(){
  for(int i=0; i<12; i++){
    char angka = mkeypad.getKey();
    nomer[i]=angka;
    if(angka){
      lcd.print(angka);
    }
    if(digitalRead(button) == LOW){
      for (int j=0; j<12; j++){
        if(nomer[j] == '0'){
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,HIGH);
          digitalWrite(g,LOW);
        }if(nomer[j] == '1'){
          digitalWrite(a,LOW);
          digitalWrite(b,HIGH);
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW);
          digitalWrite(e,LOW);
          digitalWrite(f,LOW);
          digitalWrite(g,LOW);
        }if(nomer[j] == '2'){
          digitalWrite(a,HIGH);
          digitalWrite(b,HIGH);
          digitalWrite(c,LOW);
          digitalWrite(d,HIGH);
          digitalWrite(e,HIGH);
          digitalWrite(f,LOW);
          digitalWrite(g,HIGH);
        }if(nomer[j] == '3'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH); 
          digitalWrite(e,LOW); 
          digitalWrite(f,LOW); 
          digitalWrite(g,HIGH);
        }if(nomer[j] == '4'){
          digitalWrite(a,LOW); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW); 
          digitalWrite(e,LOW); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH);
       }if(nomer[j] == '5'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,LOW); 
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH); 
          digitalWrite(e,LOW); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH);
       }if(nomer[j] == '6'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,LOW); 
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH);
      }if(nomer[j] == '7'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW); 
          digitalWrite(e,LOW); 
          digitalWrite(f,LOW); 
          digitalWrite(g,LOW);
      }if(nomer[j] == '8'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH);
          digitalWrite(d,HIGH); 
          digitalWrite(e,HIGH); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH);
      } if(nomer[j] == '9'){
          digitalWrite(a,HIGH); 
          digitalWrite(b,HIGH); 
          digitalWrite(c,HIGH);
          digitalWrite(d,LOW); 
          digitalWrite(e,LOW); 
          digitalWrite(f,HIGH); 
          digitalWrite(g,HIGH);
      }
      }
      digitalWrite(buzzer,HIGH);
      delay(1000);
      digitalWrite(buzzer,LOW);
    }
  }
}
