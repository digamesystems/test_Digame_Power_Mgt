#include <Arduino.h>
#include <digameDebug.h>
#include <digamePowerMgt.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  setFullPowerMode();
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  print_wakeup_reason();
  Serial.println();
  Serial.println("Hello from Full Power Mode (240MHz)");
  Serial.println("    Delaying 30 sec..." );
  delay(30000); // 54 mA

  setMediumPowerMode();
  Serial.begin(9600);
  delay(1000);
  Serial.println("Hello from Medium Power Mode (80MHz)");
  Serial.println("    Delaying 30 sec..." );
  delay(30000); // 37 mA

  setLowPowerMode();
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.println("Hello from Low Power Mode (40MHz)");
  Serial.println("    Delaying 30 sec..." );
  delay(30000); // 26 mA

  Serial.println("Entering Light Sleep...");
  Serial.println("    Sleeping 30 sec..." );
  delay(1000);
  lightSleepMSec(30000);  // 14 mA
  Serial.begin(9600);
  delay(1000);
  Serial.println("    Yawn! Morning!");

  Serial.println("Entering Deep Sleep...");
  Serial.println("    Sleeping 30 sec. On wakeup, system will reset..." );
  delay(1000);
  deepSleepMSec(30000);  // 12 mA
  // We should never get here since coming out of deep sleep resets the system.
  Serial.println("    Yawn! Morning!");
  

}

unsigned long t1, t2;

void loop() {

}