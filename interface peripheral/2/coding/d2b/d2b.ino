#include <LiquidCrystal_SR_LCD3.h>
const int PIN_LCD_STROBE  = 2;
const int PIN_LCD_DATA    = 3;
const int PIN_LCD_CLOCK   = 4;
int sw_ok   = 7;
int sw_up   = 6;
int sw_back = 5;
int batas;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

void setup(){
  lcd.begin(16,2);
  lcd.home();
  lcd.setCursor(4,0); // colom 4 baris ke 0
  lcd.print("D3TK-43-02");
  delay(3000);
  batas=0;
  menu();
}
void loop(){
  for(int i = 0; i <= batas; i++){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("BATAS : ");
    lcd.setCursor(7,0);
    lcd.print("batas : ");
    lcd.setCursor(0,1);
    lcd.print("Data : ");
    lcd.setCursor(7,1);
    lcd.print(i);
    delay(1000);
  }
}
void menu(){
  set: // saat fungsi mencapai goto set akan kembali ke sini
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("SETTING : ");
  lcd.setCursor(0,1);
  lcd.print("SET : ");
  lcd.setCursor(11,1);
  lcd.print("START : ");
  if(digitalRead(sw_ok)==LOW){ //saat tombol ditekan
    while(digitalRead(sw_ok)==LOW){} //waktu tombol ditekan
      goto set1;
  }
  if(digitalRead(sw_back)==LOW){ 
    while(digitalRead(sw_back)==LOW){} // waktu tombol ditekan
      goto start;
  } else{
    goto set; // kembali ke set:
  }
  set1: // saat fungsi mencapai goto set1 akan kembali ke sini
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BATAS : ");
  lcd.setCursor(7,0);
  lcd.print(batas);
  lcd.setCursor(0,1);
  lcd.print("SET : ");
  lcd.setCursor(7,1);
  lcd.print("UP : ");
  lcd.setCursor(12,1);
  lcd.print("DOWN : ");

  if(digitalRead(sw_ok)==LOW){
    while(digitalRead(sw_ok)==LOW){} // waktu tombol ditekan
      goto set; // kembali ke set1:
  } 
  if(digitalRead(sw_back)==LOW){ // jika tombol ditekan
    batas=batas-1;
    if(batas<0){
      batas=0;
    }
    delay(100);
    goto set1;
  }
  if(digitalRead(sw_up)==LOW){
    batas=batas+1; // penjumlahan total
    delay(100);
    goto set1;
  } else{
    goto set1; //kembali ke set1:
  }

  start:
  lcd.clear();
  lcd.setCursor(8,0);
  lcd.print("DONE");
  delay(3000);
  
}
