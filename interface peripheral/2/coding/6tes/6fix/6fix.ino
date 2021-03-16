#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE  = 2;
const int PIN_LCD_DATA    = 3;
const int PIN_LCD_CLOCK   = 4;
int tombol1   = 7;
int tombol2   = 6;
int tombol3   = 5;
int led1 = 10;
int led2 = 9;
int led3 = 8;
int blin,runn,fading,batas;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

void setup(){
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(4,0);
  lcd.print("D3TK-43-02");
  delay(3000);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  blin = 0;
  batas=0;
  menu();
}
void loop(){
    lcd.clear();
    if(blin == 1){
      lcd.print("BLINK LED");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(500);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(500);
    }if(runn == 1){
      lcd.print("RUNNING LED");
      digitalWrite(led1,HIGH);
      delay(500);
      digitalWrite(led1,LOW);
      digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led2,LOW);
      digitalWrite(led3,HIGH);
      delay(500);
      digitalWrite(led3,LOW);
    }if(fading == 1){
      lcd.print("FADING LED");
      for(int i=0; i<=255; i+=5){
        analogWrite(led1,i);
        analogWrite(led2,i);
        analogWrite(led3,i);
        delay(150);
      }
      for(int i=255; i>=0; i-=5){
        analogWrite(led1,i);
        analogWrite(led2,i);
        analogWrite(led3,i);
        delay(150);
      }
    }
}
void menu(){
  set:
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("MENU : ");
  lcd.setCursor(0,1);
  lcd.print("BLINK");
  lcd.setCursor(6,1);
  lcd.print("RUN");
  lcd.setCursor(10,1);
  lcd.print("FADING");
  if(digitalRead(tombol1)==LOW){
    blin=blin+1;
    goto start;
  }if(digitalRead(tombol2)==LOW){
    runn=runn+1;
    goto start;
  }if(digitalRead(tombol3)==LOW){
    fading=fading+1;
    goto start;
  }else{
    goto set;
  }
  start:
  lcd.clear();
}
