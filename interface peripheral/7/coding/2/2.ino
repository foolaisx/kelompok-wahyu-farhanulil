#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE  = 1;  
const int PIN_LCD_DATA    = 2; 
const int PIN_LCD_CLOCK   = 3;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pirPin = 12; 
char ledPin = A5;

int push = 7;
int npush = 0;
char buz = A0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  pinMode(buz,OUTPUT);
  pinMode(push,INPUT);
}

void loop(){
  int tombol = digitalRead(push);
  if(tombol==LOW){
    npush=npush+1;
  }
  if(npush == 1){
    Serial.print("calibrating sensor "); //1
    for(int i = 0; i < calibrationTime; i++){
     Serial.print(".");
      delay(1000);
    }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    lcd.print("SENSOR ACTIVE");
    delay(50);
  }
  if(npush == 2){
    if(digitalRead(pirPin) == HIGH){ //2
      digitalWrite(ledPin, HIGH);
      if(lockLow){
        lockLow = false;
        Serial.println("---");
        Serial.print("motion detected at ");
        Serial.print(millis()/1000);
        Serial.println(" sec");
        delay(50); 
        lcd.clear();
        lcd.print("motion detected");
        digitalWrite(buz,HIGH);
        delay(500);
      }
   takeLowTime = true;
   }
  }
  if(npush == 3){
    if(digitalRead(pirPin) == LOW){ //3
      digitalWrite(ledPin, LOW);
      if(takeLowTime){ 
        lowIn = millis();
        digitalWrite(ledPin,HIGH);
        delay(500);
        digitalWrite(ledPin,LOW);
        delay(500);
        takeLowTime = false;
      }
      if(!lockLow && millis() - lowIn > pause){
        lockLow = true;
        Serial.print("motion ended at ");
        Serial.print((millis() - pause)/1000);
        Serial.println(" sec");
        lcd.clear();
        delay(50);
      }
   }
 }
 if(npush == 4){
  npush == 0;
 }

} 
