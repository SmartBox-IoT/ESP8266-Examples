/********************************************************************\
 * 
 *  SmartBox IoT - ESP8266 Examples - PTR Callback
 * 
 *  Execute and flip callback procedue by void address pointer.
 * 
 *  Historie:
 *  2018-03-15  released
 * 
\********************************************************************/

// define pointer based procedure
void (*voidCallback)() = NULL;

// assign address of procedure to callback
void setCallback(void (*pVoidCallback)()) {
  voidCallback = pVoidCallback; 
}

// execute callback procedure
void runCallback() {
  voidCallback();
}

// implementation of the callback variants
void myCallback_1() {
  Serial.println("myCallback_1");
}
void myCallback_2() {
  Serial.println("myCallback_2");
}

#define BUILTIN_LED 2

void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println();
  Serial.println("Smartbox IoT - ESP8266 Examples - PTR Callback");

  // assign, execute and flip callback
  setCallback(myCallback_1);
  runCallback();
  setCallback(myCallback_2);
  runCallback();

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