#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

int button;
char answer={};
int timecheck(char ans)
{ 
  if (String(ans) == "T")
 	{
  	int time = Serial.parseInt();
  	//Serial.print(time);
  	return time;
  	}
  //Serial.print(500);
  return 500;
}
void setup()
{
Serial.begin(9600);
lcd.begin(16,2);
pinMode(7,INPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);  
}

void loop(){ 
  button = digitalRead(7);
  lcd.write("What to include?");
  //Serial.print(answer);
  if (button == 1 )
  {lcd.clear();
   lcd.write("BUTTON LED ON");
   delay(500);
  }
  if (Serial.available() > 0){
    lcd.clear();
    answer = Serial.read();
  	if (String(answer) == "R")
  	{
   		digitalWrite(6,1);
   		lcd.write("RED LED ON");
        answer = Serial.read();
   		delay(timecheck(answer));
  	}
  	else if (String(answer) == "B")
  	{
   		digitalWrite(5,1);
   		lcd.write("BLUE LED ON");
        answer = Serial.read();
   		delay(timecheck(answer));
  	}
  	else if (String(answer) == "G")
  	{
   		digitalWrite(4,1);
   		lcd.write("GREEN LED ON");
        answer = Serial.read();
   		delay(timecheck(answer));
  	}
  	else if (String(answer) == "M")
  	{
   		digitalWrite(3,1);
   		lcd.write("ENGINE ON");
        answer = Serial.read();
   		delay(timecheck(answer));
  	}
    else if (String(answer) == "Z")
  	{
        lcd.write("SOUND ON");
        answer = Serial.read();
   		tone(2, 500, timecheck(answer));
  	}
    delay(500);
    answer={};
    for (int i =7;i>2;i--)
    {digitalWrite(i,0);}    
 }
 delay(500);
 lcd.clear();
}
