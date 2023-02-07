#define LEDA 21
#define LEDB 19
#define SWITCH1 22
#define SWITCH2 23

int a = 100;
int b = 100;
int c = 16;
int d = 1500;
int mode = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
}

void loop() {
  digitalWrite(LEDB, HIGH);
  delay(50);
  digitalWrite(LEDB, LOW);
  int pulsewidth = a;
  int pulsewidthlow = b;
  int pulsecap = c;
  int blockdelay = d;
  for(int i = 1; i == pulsecap; i++)
  {
    digitalWrite(LEDA, HIGH);
    delay(pulsewidth);
    digitalWrite(LEDA, LOW);
    delay(pulsewidthlow);
    pulsewidth = pulsewidth + 50;

  }
  delay(blockdelay);

  /*
  if(digitalRead(SWITCH1 == 1))
  {
    digitalWrite(LEDA, HIGH);
  }
  else
  {
    digitalWrite(LEDA, LOW);
  }
  delay(10); // this speeds up the simulation
  */
}
