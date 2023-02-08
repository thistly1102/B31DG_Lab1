#define LEDA 21
#define LEDB 19
#define SWITCH1 22
#define SWITCH2 23

int a = 300;
int b = 1200;
int c = 16;
int d = 5500;
int mode = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Define Pins
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
  //Constants
  int pulsecap = c;
}

void loop() {
  //Signal B
  digitalWrite(LEDB, HIGH);
  delay(50);
  digitalWrite(LEDB, LOW);

//Signal A
//Reset Pulse Width to a
int pulsewidth = a;
//Iterate waveform 'c' number of times
  for(int i = 1; i <= pulsecap; i++)
  {
    int pulsewidthlow = b;
    int blockdelay = d;
    //Call checkSwitch Functions
    checkSwitch1();
    checkSwitch2();
    //Pulse LEDA
    digitalWrite(LEDA, HIGH);
    delay(pulsewidth);
    digitalWrite(LEDA, LOW);
    delay(pulsewidthlow);
    //Increase pulsewidth
    pulsewidth = pulsewidth + 50;

  }
  delay(blockdelay);
}

void checkSwitch1() 
{
  if(SWITCH1 == HIGH)
  {
    delay(1000);
  }
}

void checkSwitch2() 
{
  if(SWITCH2 == HIGH)
  {
    pulsewidthlow = b/2;
    blockdelay = d/2;
  }
}
