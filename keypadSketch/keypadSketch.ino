#include <EasyTransfer.h>
#include <Keypad.h>

const int ledpin = 13;

byte rowPins[4]={3,4,5,6};
byte colPins[3]={7,8,9};
char keys[4][3] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'A','B','C'}
};

Keypad kpd=Keypad(makeKeymap(keys),rowPins,colPins,4,3);

EasyTransfer ET;

struct SEND_DATA_STRUCTURE{ 
  int player; 
  int index;
};

SEND_DATA_STRUCTURE mydata;


void setup()
{
  Serial.begin(9600);
  ET.begin(details(mydata), &Serial);
  pinMode(ledpin,OUTPUT);
  randomSeed(analogRead(0));
  mydata.player=1;
  
  digitalWrite(ledpin, HIGH);
}

void loop()
{
  char key = kpd.getKey();
  if (key != NO_KEY){
    mydata.index=key+0; //converts it to an int from a char
    ET.sendData();
    if (mydata.player==1){
      mydata.player=2;
    }
    else {
      mydata.player=1;
    }
  }
  delay(100);
}
