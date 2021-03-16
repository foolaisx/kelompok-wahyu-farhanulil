#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int tombol1 = 10;
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.print("Hallo");
  pinMode(tombol1,INPUT);
  delay(500);
  lcd.clear();
}
void loop(){
  if(Serial.available()){
    while(Serial.available() > 0){
      char kata=Serial.read();
      Serial.write(kata);
      lcd.write(kata);
    }
  }
  if(digitalRead(tombol1)==LOW){
    for(int positionCounter=0;
        positionCounter < 16;
        positionCounter++){
          lcd.scrollDisplayLeft();
          delay(150);
        }
    for(int positionCounter=0;
          positionCounter < 32;
          positionCounter++){
            lcd.scrollDisplayRight();
            delay(150);
          }
    for(int positionCounter=0;
          positionCounter < 32;
          positionCounter++){
            lcd.scrollDisplayLeft();
            delay(150);
          }
    }
}
