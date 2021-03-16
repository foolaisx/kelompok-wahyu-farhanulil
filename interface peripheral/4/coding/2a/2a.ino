#include<EEPROM.h>
int address=0;
byte value;

void setup(){
  Serial.begin(9600);
}
void loop(){
  value = EEPROM.read(address); //EEPROM membaca nilai address
  Serial.print(address); //print var address
  Serial.print("\t"); //print var address
  Serial.print(value, DEC); //print value, DEC
  Serial.println(); //
  address = address + 1; //menjumlah address
  if (address == 512) //jika address sama dengan 512
    address = 0; //adress = 0
  delay(500);
}
