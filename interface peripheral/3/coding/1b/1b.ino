int C[]={13,12,11}; //pin yang terhubung ke pin arduino dari kolom
char R[]={A1,A2,A3,A4}; //pin yang terhubung ke pin arduino dari baris
char keymap[4][3]={ //pendeklarasian keypad 3x4
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char key; // untuk menampung variable dari keymap

void setup(){
  for(int i=0; i<3; i++){ // menjadi semua int C[] sebagai INPUT
    pinMode(C[i],INPUT);}
  for(int i=0; i<4; i++){
    pinMode(R[i],OUTPUT);} // menjadi semua int R[] sebagai OUTPUT
   Serial.begin(9600);
}
void loop(){
  scankeypad(); //masuk ke void scankeypad
  Serial.println(key);
  key=' ';
}
void scankeypad(){ // untuk menscan angka yang ada di keymap
  for(int i=0; i<4; i++){
    digitalWrite(R[i],LOW);
    for(int j=0; j<3; j++){
      if(digitalRead(C[j])==LOW){
        key=keymap[i][j]; // menampilkan angka yang ada di keymap baris dan kolom tertentu
        delay(500);
      }
    }
    digitalWrite(R[i],HIGH); // agar angka bisa berurutan
  }
}
