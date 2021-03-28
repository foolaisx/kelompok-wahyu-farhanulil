int push1 = 7;
int lightPin = A0; //ldr
int buzz = 11;
int senRead = A5;
int limit = 850;
int ledPin = 13;
int pd = A1; //photodiode
int tekan = 0;

void setup(){
  Serial.begin(9600);
  pinMode(push1,INPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(pd,OUTPUT);
  digitalWrite(buzz,LOW);
}
void loop(){
  int tombol = digitalRead(A0);
    if(tombol==LOW){
    tekan=tekan+1;
  }
  if(tekan==1){
    Serial.println(analogRead(lightPin));
    analogWrite(ledPin, analogRead(lightPin)/4);
    delay(10);
  }else if(tekan==2){
    Serial.println(analogRead(senRead));
    analogWrite(ledPin, analogRead(senRead)/4);
    delay(10);
  }else if(tekan==3){
    int val=analogRead(senRead);
    Serial.println(val);
    if(val <= limit){
      digitalWrite(buzz,HIGH);
      delay(20);
    }else if(val > limit){
      digitalWrite(buzz,LOW);
      delay(20);
    }
  }else if(tekan==4){
    int val=analogRead(lightPin);
    Serial.println(val);
    if(val <= limit){
      digitalWrite(buzz,HIGH);
      delay(20);
    }else if(val > limit){
      digitalWrite(buzz,LOW);
      delay(20);
    }
    tekan == 0;
  }
}
