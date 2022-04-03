#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);
void setup()
{
  lcd.begin(16,2);
  pinMode(7,OUTPUT);
  //lcd.print("hello, world!");
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
  delay(100);
  lcd.clear();
    while (Serial.available()>0){
    lcd.write(Serial.read());}}
for (int poscount = 0; poscount<13;poscount++)
{lcd.scrollDisplayLeft();
 delay(150);
}
 for (int poscount = 0; poscount<29;poscount++)
 {
   lcd.scrollDisplayLeft();
  delay(150);}
 for (int poscount = 0; poscount<16;poscount++)
 {
   lcd.scrollDisplayLeft();
  delay(150);}  
  
  delay(1000);
  
}