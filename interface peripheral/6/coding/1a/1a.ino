float tempC;
int reading;
int tempPin = 0;
void setup(){
  analogReference(INTERNAL);
}
void loop(){
  reading = analofRead(tempPin);
  tempC = reading / 9.31;
}
