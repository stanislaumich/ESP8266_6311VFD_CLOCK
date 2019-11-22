#include <Arduino.h>
#ifndef common
  #include "common.h"
 #endif
#ifndef MyDisplay
  #include "myDisplay.h"
 #endif 
#ifndef MyWiFi
  #include "myWiFi.h"
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
#ifndef myIR
  #include "myIR.h"
 #endif 

/////////////////////////////////////////////////////////////////////////////////////// 
void setup() {
  initCommon();
  beep(125,50);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");
  MyWiFiInit();
  MyTimeInit();
  MyWebinit();
  MyTeleBotInit();
  bot.sendMessage(myTele, "Бот запущен: "+IP_to_String(WiFi.localIP()), "");
  beep(125,50);
   delay(50);
  beep(125,50); 

}

void loop() {
  goBot();
  httpServer.handleClient();
  clok();
}