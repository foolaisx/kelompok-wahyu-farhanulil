#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int tombol1 = 10;
int tombol2 = 9;
int tombol3 = 8;
void setup() {
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  lcd.begin(16,2);
}
void loop(){
  lcd.setCursor(0,0);
 if(digitalRead(tombol1)==LOW){
  lcd.print("tombol 1 ditekan"); 
 }else if(digitalRead(tombol2)==LOW){
  lcd.print("tombol 2 ditekan");
 }else if(digitalRead(tombol3)==LOW){
  lcd.clear();
 }

}
