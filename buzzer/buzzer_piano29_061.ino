#include <Keypad.h> // Подключаем библиотеку 
#include <Adafruit_NeoPixel.h>
#define sv_pin 11
#define sv_num 12
Adafruit_NeoPixel sv_music = Adafruit_NeoPixel(sv_num,sv_pin,NEO_GRB + NEO_KHZ800);
const byte ROWS = 4; // 4 строки
const byte COLS = 4; // 4 столбца
int time = 300;
char keys[ROWS][COLS] = {
  {'4','7',';','>'},
  {'B','F','J','N'},
  {'S','X',']','c'},
  {'*','0','#','D'}
}; 
bool record = false;
char rec_sound[10]; 
int i=0;
byte rowPins[ROWS] = {9, 8, 7, 6}; //пины строк клавиатуры
byte colPins[COLS] = {5, 4, 3, 2}; //пины столбцов клавиатуры
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char play(char note)
{ if (int(note)!=0){
  int sv_count = 0;
  for (int m=0;m<11;m++){
    for (int j=0;j<11;j++){
      if (keys[m][j]==note){break;}
      else{sv_count+=1;}}
    break;}
  Serial.println(sv_count);
  Serial.print("chastota:");
  Serial.println(int(note)*10); // Передаем название нажатой клавиши в сериал порт
  Serial.print("dlitelnost:");
  Serial.println(time);         // Длительность ноты
  tone(10, int(note)*10, time); // Издаем звуковой сигнал длиной 300 миллисекунд 
  sv_music.setPixelColor(sv_count,sv_music.Color(255,0,0));
  sv_music.show();
  delay(300);
  noTone(10);
  sv_music.setPixelColor(sv_count,sv_music.Color(0,0,0));
  sv_music.show();}}
void setup(){
  Serial.begin(9600);
  sv_music.begin();
}
void loop(){
  char key = keypad.getKey();
  if (key){
    if (key=='#'){
      if (time>50){time-=10;}}
    else if (key=='D'){
      if (time<1000){time+=10;}}
    else if (key=='*'){
      if (record==false){
        for (i;i>0;i--){rec_sound[i]=0;}
        i=0;
        record=true;
        }
      else{record=false;}}
    else if (record==true){
    	rec_sound[i]=key;
		i+=1;
   		play(key);}
    else if (key=='0' && record==false){
      Serial.println(rec_sound); //вывод данных, записанной мелодии
      for (int k = 0;k<sizeof(rec_sound)-1;k++){
        	play(rec_sound[k]);}}
    else{play(key);} 
    }}

  //{'','','',''}, первая октава
  //{'!','#','%','('},
  //{')',',','.','1'},
  //{'4','7',';','>'}