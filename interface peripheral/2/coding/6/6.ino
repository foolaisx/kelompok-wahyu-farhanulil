#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE = 2;
const int PIN_LCD_DATA = 3;
const int PIN_LCD_CLOCK = 4;
int tombol1 = 7;
int tombol2 = 6;
int tombol3 = 5;
int led1 = 10;
int led2 = 9;
int led3 = 8;
int blink,run,fading,batas;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA, PIN_LCD_CLOCK,
PIN_LCD_STROBE);

void setup(){
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(4,0);
  lcd.print("D3TK-43-02");
  delay(3000);
  blink = 0;
  run = 0;
  fading = 0;
  batas = 0;
  menu();
}
void loop(){
  for(int i=0; i<=batas; i++){
    lcd.clear();
    if(blink = 1){
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      delay(1000);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(1000);
    }
    delay(1000);
  }
}
void menu(){
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("MENU");
  lcd.setCursor(4,1);
  lcd.print("1");
  lcd.setCursor(8,1);
  lcd.print("2");
  lcd.setCursor(12,1);
  lcd.print("3");
  if(digitalRead(tombol1)==LOW){
    blink=blink+1;
    goto start;
    lcd.print("BLINK LED");
    delay(4000);
  }
  if(digitalRead(tombol2)==LOW){
    run=run+1;
    goto start;
    lcd.print("RUNNING LED");
    delay(4000);
  }
  if(digitalRead(tombol3)==LOW){
    fading=fading+1;
    goto start;
    lcd.print("FADING LED");
    delay(4000);
  }
  start:
  lcd.clear();
  lcd.setCursor(0,0);
}
