//Define LED pin numbers
#define LEDA 18
#define LEDB 19
//Define Switch pin numbers
#define SWITCH1 1
#define SWITCH2 2

const int a = 300;  //Width of 1st pulse
const int c = 16;   //Number of pulses in a block
const int increment = 50; //Pulse time increment per pulse  
int b = 1200; //Width of space between pulses
int d = 5500; //Space between Pulse Blocks


void setup() {
  Serial.begin(115200);
  //Define LED pins
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  //Define Switch Pins
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
}

void loop() {
//Call CheckSwitch functions to check if switches are HIGH 
checkSwitch1();
checkSwitch2();

//Signal B Waveform
digitalWrite(LEDB, HIGH); //Set LEDB to HIGH
delayMicroseconds(50);
digitalWrite(LEDB, LOW);  //Set LEDB to LOW

//Signal A Waveform
//Iterate Signal A waveform 'c = 16' number of times
  for(int i = 0; i <= c-1; i++)
  {
    //Pulse LEDA
    digitalWrite(LEDA, HIGH); //Set LEDA to HIGH
    delayMicroseconds(a + increment * i); //Delay by 'a' plus the incremental delay
    digitalWrite(LEDA, LOW);  //Set LEDA to LOW
    delayMicroseconds(b); //Delay by 'b'
  }
  //Delay between end of Signal A waveform and start of Signal B Waveform
  delayMicroseconds(d);
}

//Check if SWITCH1 is HIGH
void checkSwitch1() 
{
  int stopsystem = 0;
  //If SWITCH1 is HIGH, Stop operation of Signal A and Signal B waveforms
  if(digitalRead(SWITCH1) == HIGH)
  {
    stopsystem = 1;
  }
  //Maintain delay of operation while SWITCH1 remains HIGH
  while(stopsystem == 1)
  {
    delay(1000);
    if(digitalRead(SWITCH1) == LOW)
    {
      stopsystem = 0;
    }
  }
}

//Check if SWITCH2 is HIGH
void checkSwitch2() 
{
  //If SWITCH2 is HIGH, half 'b' and 'd' delay variables for operation of the signal waveforms
  if(digitalRead(SWITCH2) == HIGH)
  {
    b = 1200/2;
    d = 5500/2;
  }
  //If SWITCH2 is LOW return b and d delay variables to original value
  else
  {
    b = 1200;
    d = 5500;
  }
}
