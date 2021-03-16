#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE  = 2; 
const int PIN_LCD_DATA    = 3; 
const int PIN_LCD_CLOCK   = 4; 
int tombol1 = 7;
int tombol2 = 6;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

void setup(){
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print("HALLO WORLD!");
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
}
void loop(){
  lcd.setCursor(0,1);
  if(digitalRead(tombol1)==LOW){
    lcd.print("tombol 1 ditekan");
  } else if(digitalRead(tombol2)==LOW){
    lcd.print("tombol 2 ditekan");
  }
}
