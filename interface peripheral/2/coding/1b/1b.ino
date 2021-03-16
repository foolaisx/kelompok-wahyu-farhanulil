#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); // pin yang ada di lcd
void setup() {
  lcd.begin(16,2); //16 adalah jumlah huruf yang dapat dipakai dalam 1 baris, 2 merupakan total baris yang akan tampil di lcd
  lcd.print("hello, world!"); // kata-kata yang akan tampil di lcd saat di run

}
void loop() {
 lcd.setCursor(0,1); // penghitungan akan muncul di kolom ke 0 baris ke 1, dimana baris ke 1 adalah row ke 2
 lcd.print(millis()/1000); 

}
