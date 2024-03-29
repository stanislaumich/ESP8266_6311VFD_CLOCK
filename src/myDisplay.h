#ifndef MyDisplay
#define MyDisplay
#ifndef common
  #include "common.h"
 #endif
#ifndef symbols
  #include "symbols.h"
 #endif 
#include <PT6311.h>

#define VFD_CS_PIN D1   //blue 
#define VFD_CLK_PIN D2  //gray 
#define VFD_DATA_PIN D3 //brown 



#define VFD_BYTES_PER_DIGIT 3      //3
PT6311 pt6311_driver;


void write_raw(uint8_t value, uint8_t number_of_bytes) 
{
    pt6311_driver.displayMemWriteCmd(true, false);
    for (uint8_t i = 0; i < number_of_bytes; i++)
    {
        pt6311_driver.data(value, false, ((i + 1) == number_of_bytes));
    }
}

void fill_mem(uint8_t value, uint8_t number_of_bytes, uint8_t start_addr)
{
    pt6311_driver.addrSetCmd(start_addr); 
    write_raw(value, number_of_bytes);
}

void showfirst3(int s1,int s2, int s3)
{
  //27
  pt6311_driver.addrSetCmd(27);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(sf[s1]+0, false, false);
  pt6311_driver.data(ss[s1], false, false);
  pt6311_driver.data(0, false, true);
  //24
  pt6311_driver.addrSetCmd(24);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(sf[s2]+2, false, false);
  pt6311_driver.data(ss[s2], false, false);
  pt6311_driver.data(0, false, true);
  //21
  pt6311_driver.addrSetCmd(21);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(sf[s3]+0, false, false);
  pt6311_driver.data(ss[s3], false, false);
  pt6311_driver.data(0, false, true);  
}
void show1(int s1)
{
  //27
  pt6311_driver.addrSetCmd(27);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(sf[s1]+0, false, false);
  pt6311_driver.data(ss[s1], false, false);
  pt6311_driver.data(0, false, true);
}
void showtime3(int h, int m,int ss)
{
  //18
  pt6311_driver.addrSetCmd(18);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(h-h%10)/10]+0, false, false);
  pt6311_driver.data(s[(h-h%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //15
  pt6311_driver.addrSetCmd(15);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[h%10]+2, false, false);
  pt6311_driver.data(s[h%10], false, false);
  pt6311_driver.data(0, false, true);
  //12
  pt6311_driver.addrSetCmd(12);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(m-m%10)/10]+0, false, false);
  pt6311_driver.data(s[(m-m%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //9
  pt6311_driver.addrSetCmd(9);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[m%10]+2, false, false);
  pt6311_driver.data(s[m%10], false, false);
  pt6311_driver.data(0, false, true);
  //6
  pt6311_driver.addrSetCmd(6);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(ss-ss%10)/10]+0, false, false);
  pt6311_driver.data(s[(ss-ss%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //3
  pt6311_driver.addrSetCmd(3);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[ss%10], false, false);
  pt6311_driver.data(s[ss%10], false, false);
  pt6311_driver.data(0, false, true);
}
void showtime2(int h, int m)
{
  /* 
  //18
  pt6311_driver.addrSetCmd(18);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(h-h%10)/10]+0, false, false);
  pt6311_driver.data(s[(h-h%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //15
  pt6311_driver.addrSetCmd(15);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[h%10]+2, false, false);
  pt6311_driver.data(s[h%10], false, false);
  pt6311_driver.data(0, false, true);
  */
  //12
  pt6311_driver.addrSetCmd(12);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(h-h%10)/10]+0, false, false);
  pt6311_driver.data(s[(h-h%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //9
  pt6311_driver.addrSetCmd(9);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[h%10]+2, false, false);
  pt6311_driver.data(s[h%10], false, false);
  pt6311_driver.data(0, false, true);
  //6
  pt6311_driver.addrSetCmd(6);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[(m-m%10)/10]+0, false, false);
  pt6311_driver.data(s[(m-m%10)/10], false, false);
  pt6311_driver.data(0, false, true);
  //3
  pt6311_driver.addrSetCmd(3);
  pt6311_driver.displayMemWriteCmd(true, false);
  pt6311_driver.data(f[m%10], false, false);
  pt6311_driver.data(s[m%10], false, false);
  pt6311_driver.data(0, false, true);
}
/*

unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    unsigned long secsSince1900 = highWord << 16 | lowWord;
    Serial.print("Seconds since Jan 1 1900 = " );
    Serial.println(secsSince1900);
    Serial.print("Unix time = ");
    const unsigned long seventyYears = 2208988800UL;
    unsigned long epoch = secsSince1900 - seventyYears;
    Serial.println(epoch);
    epoch = epoch + GMT * 3600;
    hour = (epoch  % 86400L) / 3600;
    minute = (epoch  % 3600) / 60;
    second = epoch % 60;

    weekday=(epoch/60/60/24+4)%7; // day week, 0-sunday


*/

void writeled(int a){
  pt6311_driver.displayLEDWriteCmd(true, false);
  pt6311_driver.data(a, false, true);
}

void emptyscreen(void){
  for (uint8_t i = 0; i < 12; i++) 
  {
      fill_mem(0x00, VFD_BYTES_PER_DIGIT, i * VFD_BYTES_PER_DIGIT);
      delay(10); 
  }
}

void myDispInit(void){
  //----------------Display INIT
  pt6311_driver.init(VFD_CS_PIN, VFD_CLK_PIN, VFD_DATA_PIN);
  pt6311_driver.reset(VFD_DISP_MODE_10D18S); // good VFD_DISP_MODE_10D18S
  emptyscreen();
  //showtime2(0,0);
  writeled(0);
  //----------------Display
 }

/*

if((weekday>0)and(weekday<6)and(hour>=8)and (hour<=17))  {
     emptyscreen();
     writeled(255);
   }
    else{
      writeled(0); 
      show1(weekday);
      showtime(hour,minute,second);
    }


*/



 #endif 