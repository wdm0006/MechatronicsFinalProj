#include <EasyTransfer.h>

const int ledpin=13;

EasyTransfer ET; 

struct RECEIVE_DATA_STRUCTURE{
  int player; 
  int index;
};

RECEIVE_DATA_STRUCTURE mydata;

byte player1[9]={0,0,0,0,0,0,0,0,0};
byte player2[9]={0,0,0,0,0,0,0,0,0};

/* need to declare all of the LED pins, in some way that makes sense
*/

void setup(){
  Serial.begin(9600);
  ET.begin(details(mydata), &Serial);
  pinMode(ledpin, OUTPUT); 
  /* need to declare all of those LED pins as outputs */
}

void loop(){
  //check and see if a data packet has come in. 
  if(ET.receiveData()){
    if (mydata.player==1){
      player1[mydata.index]=1; 
      if (checkForWin(player1))
         player1={1,1,1,1,1,1,1,1,1};
         player2={0,0,0,0,0,0,0,0,0};
    }
    else {
       player2[mydata.index]=1; 
      if (checkForWin(player2))
         player2={1,1,1,1,1,1,1,1,1};
         player1={0,0,0,0,0,0,0,0,0};
    }
    /* Need code here to actually write HIGH or LOW to each output pin
    maybe also some like blinking or something like that if someone did 
    win 
    */
  }
  delay(250);
}

boolean checkForWin(byte inar[])
{
   byte winningArray1[9]={1,1,1,0,0,0,0,0,0};
   byte winningArray2[9]={0,0,0,1,1,1,0,0,0};
   byte winningArray3[9]={0,0,0,0,0,0,1,1,1};
   byte winningArray4[9]={1,0,0,1,0,0,1,0,0};
   byte winningArray5[9]={0,1,0,0,1,0,0,1,0};
   byte winningArray6[9]={0,0,1,0,0,1,0,0,1};
   byte winningArray7[9]={1,0,0,0,1,0,0,0,1};
   byte winningArray8[9]={0,0,1,0,1,0,1,0,0};
   
   if (ByteArrayCompare(inar[],winningArray1,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray2,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray3,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray4,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray5,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray6,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray7,9))
      return(true)
   else if (ByteArrayCompare(inar[],winningArray8,9))
      return(true)
   else 
      return(false)
}

boolean ByteArrayCompare(byte a[],byte byte b[],int array_size)
{
    for (int i = 0; i < array_size; ++i)
      if (a[i] != b[i])
        return(false);
    return(true);
}
