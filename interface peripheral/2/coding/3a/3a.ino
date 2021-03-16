#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("hello");
}
void loop(){
  if(Serial.available()){
      while(Serial.available() > 0){
        char ch=Serial.read();
        Serial.write(ch);
        lcd.write(ch);
      }
  }
}
