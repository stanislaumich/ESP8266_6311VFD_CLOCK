#include <Arduino.h>
#ifndef common
  #include "common.h"
 #endif
#ifndef MyDisplay
  #include "myDisplay.h"
 #endif 
#ifndef MyWiFi
  #include "myDisplay.h"
 #endif
#ifndef myTime
  #include "myTime.h"
 #endif 
#ifndef myWeb
 #include "myWebServer.h"
 #endif  
#ifndef MyTeleBot
  #include "myTeleBot.h"
 #endif

/////////////////////////////////////////////////////////////////////////////////////// 
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  goBot();

  clok();
}