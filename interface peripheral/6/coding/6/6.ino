#include <LiquidCrystal_SR_LCD3.h> 
#include <EEPROM.h>
const int PIN_LCD_STROBE  = 3;  
const int PIN_LCD_DATA    = 5; 
const int PIN_LCD_CLOCK   = 4;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);
float tempC;
float nilai;
int reading;
int lm = A2;
int addr = 0;
int push = 7;
int npush = 0;
int led = 8;
int buz = 11;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  analogReference(INTERNAL);
  pinMode(led,OUTPUT);
  pinMode(buz,OUTPUT);
}
void loop(){
  reading = analogRead(lm);
  tempC = reading / 9.31;
  Serial.println(tempC);
  delay(2000);
  
  int tombol = digitalRead(push);
  if(tombol==LOW){
    npush=npush+1;
  }
  if(npush==1){
    EEPROM.put(addr,tempC);
    Serial.print("Tulis Data : ");
    Serial.println(tempC);
    delay(1000);
  }
  if(npush==2){
   nilai = EEPROM.get(addr,nilai);
   lcd.print("Data : ");
   lcd.print(nilai);
   Serial.print("Data : ");
   Serial.println(nilai);
   delay(2000);
  }
  if(npush==3){
    EEPROM.write(0,0);
    lcd.clear();
    digitalWrite(buz,HIGH);
    delay(500);
    digitalWrite(buz,LOW);
  }
  if(npush==4){
    for(int x=0; x<=255; x+=5){
      analogWrite(led,x);
      delay(100);
    }
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
  }
  if(npush==5){
    digitalWrite(led,LOW);
    npush==0;
  }
  
}
