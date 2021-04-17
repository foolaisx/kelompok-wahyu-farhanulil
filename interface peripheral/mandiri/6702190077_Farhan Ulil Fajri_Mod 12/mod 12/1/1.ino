/***************************************************************
*  Aplikasi kontrol LED via Blynk Server
* Buka command windows pada direktori berikut
* C:\Users\Username\Documents\Arduino\libraries\Blynk\scripts
*
* Pada command prompt ketikan: blynk-ser.bat -c COM2 lalu enter
* COM2 disesuaikan dengan port yang digunakan pada Proteus Anda!

****************************************************************/ 
#include <BlynkSimpleStream.h>

// Pin Assignments
int redPin=13,yellowPin=12,greenPin=11,bluePin=10;

//Ganti Auth Token sesuai kode yang muncul pada aplikasi Blynk pada
//smartphone Anda. Auth Token di bawah ini hanyalah contoh. 
char auth[] = "CLkYR83HKiFze3qQ9W9tI_br_NJ2O1yc";

void setup()
{
//Atur pin sebagai output 
pinMode(redPin,OUTPUT); 
pinMode(yellowPin,OUTPUT); 
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);

// Blynk berkomunikasi melalui komunikasi serial Serial.begin(9600);
Blynk.begin(auth, Serial);
}

void loop()
{
//mengaktifkan fungsi Blynk Blynk.run();
}
