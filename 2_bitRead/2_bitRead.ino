int pos = 0;
unsigned long int 
  t_start = 0,
  t_period = 10;
bool state_led = false;
byte numeral = 0b11000111;
void setup() {
  for (int i = 2; i <= 9; ++i)
    {pinMode(i, OUTPUT);}
Serial.begin(9600);
}

void loop() {
  unsigned long int t_cur = millis();
  
  if (t_cur - t_start >= t_period) {
    t_start = t_cur;
    if (pos == 7){pos=-1;}
  pos++;
    state_led = bitRead(numeral,pos);
        }
     
    digitalWrite(pos+2,state_led);
}
