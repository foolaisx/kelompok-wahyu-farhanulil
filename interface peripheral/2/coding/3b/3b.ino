#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
}
void loop(){
  if(Serial.available()){ // untuk menghasilkan jumlah byte di port serial yang belum terbaca
    delay(100);
    lcd.clear();
    while(Serial.available() > 0){ // saat ada kata yang diketik akan
      lcd.write(Serial.read()); // ditampilkan di lcd
    }
  }
}
