int 
  pos = 0,
  ind = 0;
  
unsigned long int 
  t_start = 0,
  t_period = 10,
  t_num = 0;
  
bool state_led = false;
byte digits[21] = {
  0b00000110,
  0b01000110,
  0b01110110,
  0b00000000,
  0b01001001,
  0b01111001,
  0b00000000,
  0b00001000,
  0b00111000,
  0b00000000,
  0b00001000,
  0b00111000,
  0b00000000,
  0b00000110,
  0b00001111,
  0b00111111,
  0b00111001,
  0b00110000,
  0b00000000,
  0b10000110,
  0b00000000
};
void setup() {
  for (int i = 2; i <= 9; ++i)
    {pinMode(i, OUTPUT);}
}

void loop() {

  unsigned long int t_cur = millis();

  if (t_cur - t_start >= t_period) {
    t_start = t_cur;
    if (pos == 7){
      pos=-1;}
    pos++;
    state_led = bitRead(digits[ind],pos);
    t_num = t_num + t_period;
    if (t_num == 1000 + t_period){
    ind++;
      if (ind > 21){ind=0;}
      t_num = 0;}
    }
  
    digitalWrite(pos+2,state_led);
}
