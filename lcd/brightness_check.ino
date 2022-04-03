#include <LiquidCrystal.h>
LiquidCrystal lcd(4, 5, 10, 11, 12, 13);

int potenz = 0;
int number = 0;
int light = 0;
byte light_bar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup()
{
  lcd.createChar(0, light_bar);
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  lcd.print("LED (1-16)");
  
}

void loop()
{
  // ощищаем экран
  lcd.clear();
  // выводим сообщение в первой строчке
  lcd.print("LED (1-16)");
  // устанавливаем курсор на второй строчке
  lcd.setCursor(0, 1);
  // считываем показания с потенциометра
  potenz = analogRead(A0);
  Serial.print(potenz);
  // конвертируем значения в яркость от 0 до 255
  light = map(potenz, 0, 1024, 0, 255);
  // меняем яркость светодиода в зависимости от значений от потенциметра
  
  analogWrite(6, light);
  // конвертируем значения яркость в проценты для индикатора от 0 до 17
  number = map(light, 0, 255, 0, 17);
  // выводим индикатор
  for (int i = 0; i < number; i++)
  {
    lcd.setCursor(i, 1);
    lcd.write(byte(0));
    
  }
  // пауза
  delay(750);
}