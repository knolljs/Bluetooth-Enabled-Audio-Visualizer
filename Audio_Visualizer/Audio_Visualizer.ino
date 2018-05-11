#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>
#define PIN 6
SoftwareSerial BTSerial(2,3);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30,PIN,NEO_GRB + NEO_KHZ800);
int toggle = 0;
int i = 0;
void setup() {
  BTSerial.begin(38400);    // 38400 is the default baud rate for the serial Bluetooth module
  Serial.begin(9600);
  strip.begin();
  strip.show();
}
void loop() {
  // listen for the data
  if ( BTSerial.available() > 0 ) {
    toggle = BTSerial.read();
    Serial.println(toggle);
    if(toggle<=60 && toggle!=0){
        strip.setPixelColor(i,strip.Color(0,255,0));
    }
    if(toggle>60 && toggle<=120){
        strip.setPixelColor(i,strip.Color(255,0,0));
    }
    if(toggle>120){
        strip.setPixelColor(i,strip.Color(0,0,255));
    }
    if(i>=30){
      i = 0;
      strip.show();
    }
    else{
      i++;
    }
  }
}


