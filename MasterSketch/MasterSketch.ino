#include <EasyTransfer.h>

const int g1=2;
const int r8=3;
const int g8=4;
const int g5=5;
const int r2=6;
const int g2=7;
const int r9=8;
const int g9=9;
const int r6=10;
const int g6=11;
const int r3=12;
const int g3=13;

const int r1=A0;
const int g4=A1;
const int r4=A2;
const int g7=A3;
const int r7=A4;
const int r5=A5;

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
  pinMode(r1, OUTPUT); 
  pinMode(r2, OUTPUT); 
  pinMode(r3, OUTPUT); 
  pinMode(r4, OUTPUT); 
  pinMode(r5, OUTPUT); 
  pinMode(r6, OUTPUT); 
  pinMode(r7, OUTPUT); 
  pinMode(r8, OUTPUT); 
  pinMode(r9, OUTPUT); 
  pinMode(g1, OUTPUT); 
  pinMode(g2, OUTPUT); 
  pinMode(g3, OUTPUT); 
  pinMode(g4, OUTPUT); 
  pinMode(g5, OUTPUT); 
  pinMode(g6, OUTPUT); 
  pinMode(g7, OUTPUT); 
  pinMode(g8, OUTPUT); 
  pinMode(g9, OUTPUT); 
}

void loop(){
  //check and see if a data packet has come in. 
  if(ET.receiveData()){
    if (mydata.player==1){
      player1[mydata.index]=1; 
      if (checkForWin(player1)){
         for(int i=0; i<9; i++){
         player1[i]=1;
         player2[i]=0;
         }
      }
    }
    else {
       player2[mydata.index]=1; 
      if (checkForWin(player2)){
         for(int i=0; i<9; i++){
         player1[i]=0;
         player2[i]=1;
         }
      }
    }
    if (player1[0]==1)
      digitalWrite(r1,HIGH);
    if (player1[1]==1)
      digitalWrite(r2,HIGH);
    if (player1[2]==1)
      digitalWrite(r3,HIGH);
    if (player1[3]==1)
      digitalWrite(r4,HIGH);
    if (player1[4]==1)
      digitalWrite(r5,HIGH);
    if (player1[5]==1)
      digitalWrite(r6,HIGH);
    if (player1[6]==1)
      digitalWrite(r7,HIGH);
    if (player1[7]==1)
      digitalWrite(r8,HIGH);
    if (player1[8]==1)
      digitalWrite(r9,HIGH);
      
    if (player2[0]==1)
      digitalWrite(g1,HIGH);
    if (player2[1]==1)
      digitalWrite(g2,HIGH);
    if (player2[2]==1)
      digitalWrite(g3,HIGH);
    if (player2[3]==1)
      digitalWrite(g4,HIGH);
    if (player2[4]==1)
      digitalWrite(g5,HIGH);
    if (player2[5]==1)
      digitalWrite(g6,HIGH);
    if (player2[6]==1)
      digitalWrite(g7,HIGH);
    if (player2[7]==1)
      digitalWrite(g8,HIGH);
    if (player2[8]==1)
      digitalWrite(g9,HIGH);
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
   
   if (ByteArrayCompare(inar,winningArray1,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray2,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray3,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray4,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray5,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray6,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray7,9))
      return(true);
   else if (ByteArrayCompare(inar,winningArray8,9))
      return(true);
   else 
      return(false);
}

boolean ByteArrayCompare(byte a[],byte b[],int array_size)
{
    for (int i = 0; i < array_size; ++i)
      if (a[i] != b[i])
        return(false);
    return(true);
}
