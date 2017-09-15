#include <TinyRTClib.h>
#include <SSD1306_minimal.h>

SSD1306_Mini oled;
RTC_DS1307 rtc;

void setup() {
  pinMode(1, OUTPUT);
  oled.init(0x78);
  oled.clear();
  TinyWireM.begin();
  rtc.begin();
  delay(1000);
  if (!rtc.isrunning()) {
  flash();
   rtc.adjust(DateTime(__DATE__, __TIME__));
 }
}

void loop() {
  oled.printString("TESTING");
  delay(100);
     flash(); flash();
  DateTime now = rtc.now();
  char buff[4];
  oled.printString(itoa(now.year(), buff, 10));
  delay(500);
  oled.printString(itoa(now.second(), buff, 10));
  delay(500);
}

void flash() {
  digitalWrite(1, HIGH);
  delay(500);
  digitalWrite(1, LOW);
  delay(500);
}
