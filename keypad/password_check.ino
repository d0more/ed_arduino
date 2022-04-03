#include <Keypad.h>
#include <string.h>
const byte ROWS = 4; //4 строки
const byte COLS = 4; //4 столбца
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //пины строк клавиатуры
byte colPins[COLS] = {5, 4, 3, 2}; //пины столбцов клавиатуры
char password[5];
//int rnd = random(100,999);

//str1 = String(rnd);
String(rnd).toCharArray(password,5);

char key[5];
int num;
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}
bool checkpass(char *ar1, char *ar2)//С помощью указателей мы не создаем новую переменную, а используем значения "на прямую", по их адресу
{
  int i = 0;
  while(ar1[i] != '\0' && ar2[i] != '\0'){ // пока i-тый элемент массива 1 И 2 не "\0"
    if(ar1[i]!=ar2[i]) //если что-то не совпало, возвращаем false
    {return false;}
    i++;}
  return true;
}
void loop() {	
  Serial.println(password);
  
  Serial.println("enter the correct password!");
  while (digitalRead(10)==0){
    while (num<sizeof(key)-1){ //пока переменная меньше длины массива-1(из-за знака перехода на сл.строку)
        char keyPressed = keypad.waitForKey();//waitForKey ждёт пока будет нажата клавиша
        key[num] = keyPressed;
    	num+=1;
    	}
     digitalWrite(13,1);	
  }
  digitalWrite(13,0);
  delay(500);
  if (checkpass(key,password)){
    digitalWrite(12,1);
  	delay(1500);
  	digitalWrite(12,0);}
  else{
    digitalWrite(11,1);
    delay(1500);
  	digitalWrite(11,0);}
  //Serial.println(key);
  //Serial.println(password);
  delay(1000);
  for (int i=0; i<sizeof(key)-1;i++) //обнуление данных
  	{key[i] = 0;}
  num=0;
}