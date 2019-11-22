#ifndef myIR
#define myIR
//#include "IRremoteint.h"
#include <IRremoteESP8266.h> 
#ifndef common
  #include "common.h"
 #endif
int RECV_PIN = 2; //an IR detector/demodulatord is connected to GPIO pin 2 

IRrecv irrecv(RECV_PIN);
decode_results results;

void MyIRInit(void){
    irrecv.enableIRIn(); // Start the receiver
 }

void MyIRWork(void){
    if (irrecv.decode(&results)) {
    mLog(String(results.value));//, HEX);
    irrecv.resume(); // Receive the next value
  } 
 }

#endif