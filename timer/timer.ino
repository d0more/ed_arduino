//#include <analogWrite.h>
unsigned long int 
  t_start = 0,
  t_period = 100;
const byte port_bar_first = 2;//12
const byte port_bar_last = 7;//19
int PWM_fill = 0,
	count_led = 0,
	value_light = 0,
	invert = 1;
void setup() {
  for (int i = 0; i < port_bar_last; i++) {
    pinMode(port_bar_first + i, OUTPUT);
    digitalWrite(port_bar_first + i, LOW);
  }
Serial.begin(9600);
}

void loop() {
  unsigned long int t_cur = millis();

  if (t_cur - t_start >= t_period) {
    t_start = t_cur;
    if  (PWM_fill>=244){count_led += 1; PWM_fill = 0; value_light = 0;}
    else {PWM_fill = (value_light % 32) * 8; value_light += 2;}
	if (count_led == 6){count_led = 0;}
  }
analogWrite(port_bar_first + count_led, PWM_fill); 
Serial.println(String(PWM_fill)+"/"+String(count_led));  
}