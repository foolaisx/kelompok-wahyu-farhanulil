#include <LiquidCrystal_SR_LCD3.h> // library baru
const int PIN_LCD_STROBE  = 2;  //lcd shift-register strobe
const int PIN_LCD_DATA    = 3; //lcd shift-register data
const int PIN_LCD_CLOCK   = 4; //lcd shift-register clock
int tombol1 = 7;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE); //definisi pin

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print("HALLO");
  delay(500);
  lcd.clear();
  pinMode(tombol1,INPUT);
}
void loop(){
  if(Serial.available()){
    while(Serial.available() > 0){
      char kata = Serial.read();
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
