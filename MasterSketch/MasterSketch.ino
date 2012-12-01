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

int player=1;

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
    
      
    Serial.write("Data received\n");
    Serial.write("player:\t");
    Serial.write(player == 1?"1":"2");
    Serial.write("\nindex:\t");
    Serial.write(mydata.index);
    
    if(  mydata.index > '9' ) return; 
    mydata.index -= 48;
    
    int playIndx = mydata.index-1;
    char line[40];
    
    Serial.write("\n\n");
    if (player==1){
      Serial.write("player 1 selected\n");
      
      
     
     
      if( player2[playIndx] == 1 ){
        Serial.println("P1 Redo");  
        return;
      }
     
      player1[playIndx]=1; 
      
       sprintf(line, "Player Index:%i\tPlayer Value:%i", playIndx, player1[playIndx] );
       Serial.println(line);
       Serial.println();
       
       for(int n = 0; n<9; Serial.print( player1[n++] ) );
      
      Serial.println();
      Serial.write(player1[playIndx] == 1?"1":"0");
      if (checkForWin(player1)){
        Serial.println("Player1 Win");
         for(int i=0; i<9; i++){
         player1[i]=1;
         player2[i]=0;
         }
      }
    }
    else {
      
      
      
      Serial.write("player 2 selected\n");      
      
    
    if( player1[playIndx] == 1 ){
        Serial.println("P2 Redo"); 
        return;      
    }
     
      player2[playIndx]=1; 
       
       sprintf(line, "Player Index:%i\tPlayer Value:%i", playIndx, player2[playIndx] );
      
       Serial.println(line);
       
        Serial.println();
       
       for(int n = 0; n<9; Serial.print( player2[n++] ) );
      
      Serial.println();
      
      if (checkForWin(player2)){
        Serial.println("Player2 win");
         for(int i=0; i<9; i++){
         player1[i]=0;
         player2[i]=1;
         }
      }
    }
    
    if (player1[0]==1)
      digitalWrite(r1,HIGH);
    else
      digitalWrite(r1,LOW);
    if (player1[1]==1)
      digitalWrite(r2,HIGH);
      else
      digitalWrite(r2,LOW);
    if (player1[2]==1)
      digitalWrite(r3,HIGH);
      else
      digitalWrite(r3,LOW);
    if (player1[3]==1)
      digitalWrite(r4,HIGH);
      else
      digitalWrite(r4,LOW);
    if (player1[4]==1)
      digitalWrite(r5,HIGH);
      else
      digitalWrite(r5,LOW);
    if (player1[5]==1)
      digitalWrite(r6,HIGH);
      else
      digitalWrite(r6,LOW);
    if (player1[6]==1)
      digitalWrite(r7,HIGH);
      else
      digitalWrite(r7,LOW);
    if (player1[7]==1)
      digitalWrite(r8,HIGH);
      else
      digitalWrite(r8,LOW);
    if (player1[8]==1)
      digitalWrite(r9,HIGH);
      else
      digitalWrite(r9,LOW);
      
    if (player2[0]==1)
      digitalWrite(g1,HIGH);
      else
      digitalWrite(g1,LOW);
    if (player2[1]==1)
      digitalWrite(g2,HIGH);
      else
      digitalWrite(g2
      ,LOW);
    if (player2[2]==1)
      digitalWrite(g3,HIGH);
      else
      digitalWrite(g3,LOW);
    if (player2[3]==1)
      digitalWrite(g4,HIGH);
      else
      digitalWrite(g4,LOW);
    if (player2[4]==1)
      digitalWrite(g5,HIGH);
      else
      digitalWrite(g5,LOW);
    if (player2[5]==1)
      digitalWrite(g6,HIGH);
      else
      digitalWrite(g6,LOW);
    if (player2[6]==1)
      digitalWrite(g7,HIGH);
      else
      digitalWrite(g7,LOW);
    if (player2[7]==1)
      digitalWrite(g8,HIGH);
      else
      digitalWrite(g8,LOW);
    if (player2[8]==1)
      digitalWrite(g9,HIGH);
      else
      digitalWrite(g9,LOW);
  
 

   if (player==1)
      player=2;
    else
      player=1; 
  }
  delay(50);
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
