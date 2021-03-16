#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int tombol1 = 10;
int tombol2 = 9;
void setup(){
  lcd.begin(16,2);
  lcd.print("hello, world!");
  delay(1000);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
}
void loop(){
  if(digitalRead(tombol1)==LOW){
    for (int positionCounter = 0;
       positionCounter < 19;
       positionCounter++){
        lcd.scrollDisplayRight();
        delay(150);
       }
  } else if(digitalRead(tombol2)==LOW){
    for (int positionCounter = 0;
       positionCounter < 13;
       positionCounter++){
        lcd.scrollDisplayLeft();
        delay(150);
       }
  }
}
