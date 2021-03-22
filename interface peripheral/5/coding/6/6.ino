int push1 = 7;
int i = 0;
int lightPin = A0; //ldr
int buzz = 11;
int senRead = A5;
int limit = 850;
int ledPin = 13;
int pd = A5; //photodiode

void setup(){
  Serial.begin(9600);
  pinMode(push1,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(pd,OUTPUT);
  digitalWrite(buzz,LOW);
}
void loop(){
  if(digitalRead(push1)==0 && i==0){
    Serial.println(analogRead(lightPin));
    analogWrite(ledPin, analogRead(lightPin)/4);
    delay(10);
    i++;
  }
  else{
     if(digitalRead(push1)==0 && i==1){
      Serial.println(analogRead(senRead));
      analogWrite(ledPin, analogRead(senRead)/4);
      delay(10);
      i++;
    }
    else{
      if(digitalRead(push1)==0 && i==2){
        int val=analogRead(senRead);
        Serial.println(val);
        if(val <= limit){
          digitalWrite(buzz,HIGH);
          delay(20);
        }else if(val > limit){
          digitalWrite(buzz,LOW);
          delay(20);
        }
        i++;
      }
      else{
        if(digitalRead(push1)==0 && i==3){
          int val=analogRead(lightPin);
          Serial.println(val);
          if(val <= limit){
            digitalWrite(buzz,HIGH);
            delay(20);
          }else if(val > limit){
            digitalWrite(buzz,LOW);
            delay(20);
          }
          i++;
        } 
      } 
    }
  }
}
