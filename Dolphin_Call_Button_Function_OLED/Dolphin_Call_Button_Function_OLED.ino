#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); //Set SH1106 OLED 


void setup(void) {
    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  u8g2.begin();
}
void loop(void) {
// read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(1,15,"A Dolphin Has Been");  // write something to the internal memory
    u8g2.drawStr(1,30,"Dispached To Your"); //write line two
    u8g2.drawStr(1,45,"Location. The Dolphin"); //write line three
    u8g2.drawStr(1,60,"Will Arrive Soon!"); //write line four
    u8g2.sendBuffer();          // transfer internal memory to the display
    delay(5000);  
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(2,15,"Kinsley Push Button");  // write something to the internal memory
    u8g2.drawStr(2,30,"To Attract Dolphins"); //write line two
    u8g2.sendBuffer();          // transfer internal memory to the display
    delay(100);
  }
}
//void loop(void) {
//  u8g2.clearBuffer();					// clear the internal memory
//  u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
//  u8g2.drawStr(2,15," Kinsley's Dolphin");	// write something to the internal memory
//  u8g2.drawStr(2,30,"Call: Version 1.0"); //write line two
//  u8g2.sendBuffer();					// transfer internal memory to the display
//  delay(1000);  
//}
