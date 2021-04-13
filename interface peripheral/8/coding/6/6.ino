#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE  = 1;  
const int PIN_LCD_DATA    = 2; 
const int PIN_LCD_CLOCK   = 3;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);

const int pingPin = 12;
int push = 7;
int npush = 0;
char buz = A0;
char ledPin = A5;

void  setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(buz,OUTPUT);
  pinMode(push,INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop(){

  int tombol = digitalRead(push);
  if(tombol==LOW){
    npush=npush+1;
  }
  long duration, inches, cm;
  if(npush == 1){
    pinMode(pingPin,OUTPUT);
    digitalWrite(pingPin, LOW);
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(pingPin, LOW);
    pinMode(pingPin, INPUT);
    Serial.print(pingPin);
    lcd.print(pingPin);
    delay(100);
  }
  if(npush == 2){
    duration = pulseIn(pingPin, HIGH);
    inches = microsecondsToInches(duration);
    cm = microsecondsToCentimeters(duration);
    digitalWrite(buz, HIGH);
    delay(1000);
  }
  if(npush == 3){
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(100);
    lcd.print(inches);
    lcd.print("in, ");
    lcd.setCursor(0,2);
    lcd.print(cm);
    lcd.print("cm");
    lcd.println();
    delay(1000);
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    delay(500);
  }
  if(npush == 4){
    lcd.clear();
    npush == 1;
  }
  
}
long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
