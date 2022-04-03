#include "IRremote.h"
IRrecv irrecv(2);
decode_results results;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void blink(int pin){
  digitalWrite(pin,HIGH);
  delay(1000);
  digitalWrite(pin,LOW);
  delay(1000);
}

void loop() {
  int mas[2];
  digitalWrite(12,LOW);
  for (int i = 0; i < 2; i++)
  {
    int num = random(0, 6);
    mas[i] = num + 4;
    digitalWrite(num + 4, HIGH);
    delay(1000);
    digitalWrite(num + 4, LOW);
    delay(1000);
  }
  int user_mas[2];
  int count = 0;
  while (count<2)
  {
    if (irrecv.decode(&results))
    {
      Serial.println(results.value, HEX);
     if (results.value == 0xFD08F7)
     {blink(4);
      user_mas[count] = 4;
      count++;}
      else if (results.value == 0xFD8877)
      {blink(5);
       user_mas[count] = 5;
       count++;}
       else if (results.value == 0xFD48B7)
      {blink(6);
       user_mas[count] = 6;
       count++;}
       else if (results.value == 0xFD28D7)
      {blink(7);
       user_mas[count] = 7;
       count++;}
       else if (results.value == 0xFDA857)
      {blink(8);
       user_mas[count] = 8;
       count++;}
       else if (results.value == 0xFD6897)
      {blink(9);
       user_mas[count] = 9;
       count++;}
     irrecv.resume();
    }
  }
  bool right= true;
  for (int i = 0; i<2;i++)
  {if (mas[i]!=user_mas[i])
  {right=false;}
  }
  if (right)
  {digitalWrite(12,HIGH);}
delay(5000);}