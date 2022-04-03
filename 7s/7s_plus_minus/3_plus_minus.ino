int 
  pos = 0,
  ind = 0,
  port_btn_plus = 10,
  port_btn_minus = 11;
  
unsigned long int 
  t_start = 0,
  t_period = 10;
  
unsigned long timer_btn_plus = 0;
unsigned long timer_btn_minus = 0;

bool old_state_btn_plus = false;
bool old_state_btn_minus = false;

bool state_led = false;
byte digits[10] = {
  0b00111111,
  0b00000110,
  0b01011011,
  0b01001111,
  0b01100110,
  0b01101101,
  0b01111101,
  0b00000111,
  0b01111111,
  0b01101111
};
void setup() {
  for (int i = 2; i <= 9; ++i)
    {pinMode(i, OUTPUT);}
  pinMode(port_btn_plus, INPUT);
  pinMode(port_btn_minus, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool state_btn_plus = digitalRead(port_btn_plus);
  unsigned long int t_cur = millis();
  
  if ((state_btn_plus) && (!old_state_btn_plus)
  && (t_cur - timer_btn_plus >= 200)) {
    if (ind < 9) {
      ind = ind + 1;
    }
    timer_btn_plus = t_cur;
  }
  old_state_btn_plus = state_btn_plus;


  bool state_btn_minus = digitalRead(port_btn_minus);
  if ((state_btn_minus) && (!old_state_btn_minus)
  && (t_cur - timer_btn_minus >= 200)) {
    if (ind > 0) {
     ind = ind - 1;
    }
    timer_btn_minus = t_cur;
  }
  old_state_btn_minus = state_btn_minus;


  if (t_cur - t_start >= t_period) {
    t_start = t_cur;
    if (pos == 7){pos=-1;}
  pos++;
    state_led = bitRead(digits[ind],pos);
        }
    digitalWrite(pos+2,state_led);
}
