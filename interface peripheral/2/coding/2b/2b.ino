#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  lcd.begin(16,2);
  lcd.print("hello, world!");
  delay(1000);
}
void loop(){ // untuk perulangan program
  for (int positionCounter = 0;
       positionCounter < 13; // 13 adalah total kata hello, world!
       positionCounter++){ // untuk arah agar kata bergerak sebanyak 13 kali
        lcd.scrollDisplayLeft(); // agar kata bergerak ke kiri
        delay(150);
       }
  for (int positionCounter = 0;
       positionCounter < 29; 
       positionCounter++){ // untuk arah agar kata bergerak sebanyak 29 kali
        lcd.scrollDisplayRight(); // kata bergerak ke kanan
        delay(150);
       }
   for (int positionCounter = 0;
       positionCounter < 16; 
       positionCounter++){ // untuk arah agar kata bergerak sebanyak 16 kali
        lcd.scrollDisplayLeft(); // kata bergerak ke kiri
        delay(150);
       }
}
