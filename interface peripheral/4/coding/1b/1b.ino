#include<EEPROM.h> //include library EEPROM.h
int addr = 0; //variable addr =0
int potensio = A0; // variable potensio

void setup(){
  Serial.begin(9600); // Serial
}
void loop(){
  int val = analogRead(potensio)/4; // membaca nilai potensio
  if(addr <=512){ //jika addr kurang dari sama dengan 512
    EEPROM.write(addr,val); //EEPROM print addr dan val
    Serial.print(val);
    Serial.print("\t");
    Serial.print(addr); // print var addr
    addr= addr+1; // addr yang ada + 1
  }
  delay(100);
}
