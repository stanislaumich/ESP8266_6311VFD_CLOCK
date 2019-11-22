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
  Serial.begin(115200);
  mLog(" ");    
  mLog("Booting...");
  mLog("Starting common...");
  initCommon();    
  mLog("Beep...");
  beep(125,50);
  mLog("IR...");
  MyIRInit();
  mLog("WiFi...");
  MyWiFiInit();
  mLog("Time...");
  MyTimeInit();
  mLog("Web...");
  MyWebinit();
  mLog("TeleBot...");
  MyTeleBotInit();
  bot.sendMessage(myTele, "Бот запущен: "+IP_to_String(WiFi.localIP()), "");
  mLog("Bep-belep...");
  beep(125,50);
   delay(50);
  beep(125,50); 
  mLog("Let's do it.");
}

void loop() {

  goBot();
  httpServer.handleClient();
  clok();
}