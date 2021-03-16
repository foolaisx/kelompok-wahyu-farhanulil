char buzzer=A5; //penempatan pin buzzer
void setup(){
  pinMode(buzzer,OUTPUT); //buzzer sebagai output
}
void loop(){
  digitalWrite(buzzer,HIGH); //buzer menyala
  delay(1000);
  digitalWrite(buzzer,LOW); //buzzer mati
  delay(1000); 
}
