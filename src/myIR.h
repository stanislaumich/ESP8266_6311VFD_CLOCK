#ifndef myIR
#define myIR
//#include "IRremoteint.h"
#include <IRremoteESP8266.h> 
#ifndef common
  #include "common.h"
 #endif
#ifndef MyTeleBot
  #include "myTeleBot.h"
 #endif 
int RECV_PIN = NODEMCU_D5; //an IR detector/demodulatord is connected to GPIO pin 2 

IRrecv irrecv(RECV_PIN);
decode_results results;

void MyIRInit(void){
    irrecv.enableIRIn(); // Start the receiver
 }

void MyIRWork(void){
    if (irrecv.decode(&results)) {
    String mess =  String(results.value,HEX);
    mLog(mess);//, HEX);
    bot.sendMessage(myTele, mess, "");
    irrecv.resume(); // Receive the next value
  } 
 }

#endif