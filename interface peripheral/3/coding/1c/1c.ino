#include <LiquidCrystal_SR_LCD3.h>
#include <Keypad.h>
const byte ROWS = 4;
const byte COLS = 3;
const int PIN_LCD_STROBE = 1; 
const int PIN_LCD_DATA = 3; 
const int PIN_LCD_CLOCK = 2;
LiquidCrystal_SR_LCD3 lcd
(PIN_LCD_DATA,PIN_LCD_CLOCK,PIN_LCD_STROBE);
char keymap[ROWS][COLS]={
  {'3','2','1'},
  {'6','5','4'},
  {'9','8','7'},
  {'#','0','*'}
};
byte rowPins[ROWS] = {A1,A2,A3,A4};
byte colPins[COLS] = {11,12,13};

Keypad keypad = Keypad( makeKeymap(keymap), rowPins, colPins, ROWS, COLS );

void setup(){
   lcd.begin(16,2);
}
void loop(){
  char key = keypad.getKey();
  if (key){
    lcd.print(key);
  }
}
