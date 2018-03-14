/********************************************************************\
 * 
 *  SmartBox IoT - ESP8266 Examples - MD5 Firmware
 * 
 *  Calculate MD5 hash of firmware binary including the bootloader.
 * 
 *  Historie:
 *  2018-03-11  released
 * 
\********************************************************************/

#define BUILTIN_LED 2

void setup() 
{
  // use serial debug  
  Serial.begin(9600);
  while(!Serial && millis()<100) {delay(1);}
  Serial.println();
  yield();

  // calculate MD5 hash
  Serial.println("Smartbox IOT - ESP8266 Examples - MD5 Firmware");
  uint32_t nBeg = millis();
  String sMD5 = ESP.getSketchMD5();
  uint32_t nEnd = millis();  
  char cMD5[33] = {0};
  strcpy(cMD5, sMD5.c_str());
  Serial.print("SketchSize : "); Serial.println(ESP.getSketchSize());
  Serial.print("SketchMD5  : "); Serial.println(ESP.getSketchMD5());
  Serial.print("SketchCalc : "); Serial.print(nEnd-nBeg); Serial.println(" ms");

  // blink internal led
  pinMode(BUILTIN_LED,OUTPUT);  
}

void loop() 
{
  digitalWrite(BUILTIN_LED,LOW);  
  delay(1000);
  digitalWrite(BUILTIN_LED,HIGH);  
  delay(1000);
}