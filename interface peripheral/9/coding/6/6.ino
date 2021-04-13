#include <LiquidCrystal_SR_LCD3.h> 
const int PIN_LCD_STROBE  = 1;  
const int PIN_LCD_DATA    = 2; 
const int PIN_LCD_CLOCK   = 3;
LiquidCrystal_SR_LCD3 lcd(PIN_LCD_DATA,
PIN_LCD_CLOCK, PIN_LCD_STROBE);


int ProxSensor = A0;
int Buzzer = A1;
int inputVal = 0;
int push = 7;
int npush = 0;
char ledPin = A5;


void setup(){
  pinMode(Buzzer, OUTPUT);
  pinMode(ProxSensor, INPUT);
  pinMode(push,INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop(){
  int tombol = digitalRead(push);
  if(tombol==LOW){
    npush=npush+1;
  }
  if(npush == 1){
    if(digitalRead(ProxSensor) == LOW){
      Serial.println("Terdeteksi Halangan!");
      digitalWrite(Buzzer, HIGH);
      inputVal = analogRead(ProxSensor);
      Serial.println(inputVal);
      lcd.print(inputVal);
      delay(1000);
    }
  }
  if(npush == 2){
    if(inputVal < 66){
      lcd.clear();
      digitalWrite(Buzzer, HIGH);
      lcd.print("Warning");
      Serial.println("Warning");
      delay(1000); 
    }
  }
  if(npush == 3){
    if(digitalRead(ProxSensor) == HIGH){
      lcd.clear();
      Serial.println("Clear!");
      digitalWrite(Buzzer, LOW);
      inputVal = analogRead(ProxSensor);
      Serial.println(inputVal);
      lcd.print(inputVal);
      delay(1000);
      for(int i=0; i<=255; i++){
        digitalWrite(ledPin,i);
        delay(100);
      }
    }
  }
  if(npush == 4){
    lcd.clear();
    npush == 0;
  }
}
