#include <SoftwareSerial.h>

int motors[]={7,8,9,10};
String state;
SoftwareSerial bluetooth(11,12);//TX RX
void setup(){
  for(int i=0;i<4;i++){
 pinMode(motors[i],OUTPUT);
  }
bluetooth.begin(115200);
Serial.begin(9600);
//bluetooth.begin(9600);
}

void loop(){
    while(bluetooth.available())//check if there is an available byte to read
  {
    delay(10);
    char c=bluetooth.read();//Conduct a serial read
    state +=c;//build the string-either "1","2","3","4";
  }
  if(state.length()>0){
    Serial.println(state);
    // motorsONOFF();
    motorsfwd();
   state="";
}
}
/*
void motorsONOFF(){
   if(state=="1"){
     digitalWrite(motors[0],HIGH);
    
   }
   else if(state=="2"){
        digitalWrite(motors[0],LOW);
    
   }
  else if(state=="3"){
   digitalWrite(motors[1],HIGH);
   
   }
   else if(state=="4"){
    digitalWrite(motors[1],LOW);
    
   }
   else if(state=="5"){
    digitalWrite(motors[2],HIGH);
   
   }
   else if(state=="6"){
    digitalWrite(motors[2],LOW);
   
   }
   else if(state=="7"){
    digitalWrite(motors[3],HIGH);
   delay(1000); 
   }
   else if(state=="8"){
    digitalWrite(motors[4],LOW);
    
   }
  }
*/
void motorsfwd(){
  /*MOVEFORWARD*/
  if(state=="1"){
    digitalWrite(motors[1],HIGH);
    digitalWrite(motors[3],HIGH);
   
  }
   /*REVERSE*/
   else if(state=="2"){
    digitalWrite(motors[0],HIGH);
    digitalWrite(motors[2],HIGH);
   
    } 
  /*TURN OFF FORWARD*/
  else if(state=="3"){
    digitalWrite(motors[1],LOW);
    digitalWrite(motors[3],LOW);
    
    }
   
    /*TURN OFF REVERSE*/
    else if(state=="4"){
      digitalWrite(motors[0],LOW);
      digitalWrite(motors[2],LOW);
     
      }
      /*TURN ALL MOTORS OFF*/
     else if(state=="5"){
      digitalWrite(motors[0],LOW);
      digitalWrite(motors[1],LOW);
      digitalWrite(motors[2],LOW);
      digitalWrite(motors[3],LOW);
     }
  
}
