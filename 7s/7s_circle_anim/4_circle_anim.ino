int segment = 2;
unsigned long int 
  t_start = 0,
  t_period = 1000;
bool state_led = true;
void setup() {
  for (int i = 2; i <= segment; ++i)
    {pinMode(i, OUTPUT);}
  Serial.begin(9600);
}

void loop() {
  unsigned long int t_cur = millis();
  
  if (t_cur - t_start >= t_period) {
    t_start = t_cur;
    switch(segment){
      case 7:
        segment = 2;
        if (state_led == true){state_led = false;}
        else if (state_led == false){state_led = true;}
        break;
      default:
        segment = segment + 1;
        break;
        }
  }   
    Serial.println("Using LED number: " + String(segment) + " Status: " + String(state_led));
    digitalWrite(segment,state_led);
}
