#define LEDA 18
#define LEDB 19
#define SWITCH1 1
#define SWITCH2 2

const int a = 300;
const int c = 16;
const int increment = 50;
int b = 1200;
int d = 5500;


void setup() {
  Serial.begin(115200);
  //Define Pins
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
}

void loop() {
  b = 1200;
  d = 5500;

//checkSwitch1();
//checkSwitch2();
//Signal B
digitalWrite(LEDB, HIGH);
delay(50);
digitalWrite(LEDB, LOW);

//Signal A
//Iterate waveform 'c' number of times
  for(int i = 1; i <= c; i++)
  {
    //Pulse LEDA
    digitalWrite(LEDA, HIGH);
    delay(a + increment * i);
    digitalWrite(LEDA, LOW);
    delay(b);
  }
  //Delay between end of waveforms and start of next
  delay(d);
}

//Check if switch1 is ON and prevent operation of system
void checkSwitch1() 
{
  if(digitalRead(SWITCH1) == HIGH)
  {
    delay(5000);
  }
}

//Check if switch2 is on and alter pulsewidthlow and blockdelay variables
int checkSwitch2() 
{
  if(digitalRead(SWITCH2) == HIGH)
  {
    b = 1200/2;
    d = 5500/2;
  }
}
