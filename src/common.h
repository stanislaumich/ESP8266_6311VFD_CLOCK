#ifndef common
#define common
#include <Arduino.h>
#include <EEPROM.h>

#define NODEMCU_D0 16
#define NODEMCU_D1 5
#define NODEMCU_D2 4
#define NODEMCU_D3 0
#define NODEMCU_D4 2
#define NODEMCU_D5 14
#define NODEMCU_D6 12
#define NODEMCU_D7 13
#define NODEMCU_D8 15
#define NODEMCU_D9 3
#define NODEMCU_D10 1
#define NODEMCU_D12 10

#define pinp D2


void beep(int t1,int t2){
 unsigned long h;
  h=millis();
  while (millis()-h<t1){
   digitalWrite(pinp,HIGH);
   delayMicroseconds(t2);
   digitalWrite(pinp,LOW);
   delayMicroseconds(t2);
  }
 }

void mLog(String s){
  Serial.println(s);
 }

void Button(int state){
  mLog("State 2 switched");
  int t=0;
  EEPROM.read(10+state)?t=0:t=1;
  EEPROM.write(10+state,t);
  EEPROM.commit();
 } 

void initCommon(void){
  EEPROM.begin(512);
  pinMode(pinp,OUTPUT);
  digitalWrite(pinp,LOW);
 }
int getButton(int b){
  return EEPROM.read(10+b);
 }

String getValue(String data, char separator, int index){
  // String part01 = getValue(application_command,';',0); 
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;
  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
 }  

int getBud(int p){
  return EEPROM.read(p);
 }

void setBud(int ph,int pm){
  EEPROM.write(0,ph);
  EEPROM.write(1,pm);
  EEPROM.commit();
 } 



#endif