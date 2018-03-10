#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip0 = Adafruit_NeoPixel(60, 3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(60, 4, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(60, 5, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(60, 6, NEO_RGB + NEO_KHZ800);

String readString;
int rval;
long st;
int s = 0;
int val[2]={0,0};

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  strip0.begin();
  strip0.show();
  strip1.begin();
  strip1.show();
  strip2.begin();
  strip2.show();
  strip3.begin();
  strip3.show();
}

void loop() {
  int loopNum = 0;
 
  while (Serial.available()) {
    delay(3);
    char c = Serial.read();

    if (c == ',' | c == '\n') {
      val[loopNum] = readString.toInt();
      readString = "";
      Serial.print(loopNum);
      Serial.print(": ");
      Serial.println(val[loopNum]);
      loopNum += 1;
    } else {
      readString += c;
    }
  }
  if (loopNum == 2) {
    if ((val[0] < 5 || val[0] > 55) & s == 0) {
      st = millis();
      s = 1;
    }
    if (val[0] > 5 & val[0] < 55 & s>0) {
      s = 0;
    }

    if (millis() - st > 1000 & s == 1) {
      s = 2;
    }
  }


  if (s == 2) {
    if (millis() % 1000 < 500) {
      for (int i = 0; i < 60; i++) {
        strip0.setPixelColor(i, strip0.Color(0, 0, 0));
        strip1.setPixelColor(i, strip1.Color(0, 0, 0));
        strip2.setPixelColor(i, strip2.Color(0, 0, 0));
        strip3.setPixelColor(i, strip3.Color(0, 0, 0));
      } 
        strip0.setPixelColor(val[0], strip0.Color(0, val[1], val[1]));
        strip1.setPixelColor(val[0], strip1.Color(0, val[1], val[1]));
        strip2.setPixelColor(val[0], strip2.Color(0, val[1], val[1]));
        strip3.setPixelColor(val[0], strip3.Color(0, val[1], val[1])); 
    } else {
      for (int i = 0; i < 60; i++) {
        strip0.setPixelColor(i, strip0.Color(0, 0, 0));
        strip1.setPixelColor(i, strip1.Color(0, 0, 0));
        strip2.setPixelColor(i, strip2.Color(0, 0, 0));
        strip3.setPixelColor(i, strip3.Color(0, 0, 0));
      }
    }
    strip0.show();
    strip1.show();
    strip2.show();
    strip3.show();
    delay(15);
  } else {
    for (int i = 0; i < 60; i++) {
      strip0.setPixelColor(i, strip0.Color(0, 0, 0));
      strip1.setPixelColor(i, strip1.Color(0, 0, 0));
      strip2.setPixelColor(i, strip2.Color(0, 0, 0));
      strip3.setPixelColor(i, strip3.Color(0, 0, 0));
    }
    if(val[1]>125 & val[1]!=0){
        strip0.setPixelColor(val[0]-1, strip0.Color(255, 0, 0));
        strip1.setPixelColor(val[0]-1, strip1.Color(255, 0, 0));
        strip2.setPixelColor(val[0]-1, strip2.Color(255, 0, 0));
        strip3.setPixelColor(val[0]-1, strip3.Color(255, 0, 0));
        strip0.setPixelColor(val[0], strip0.Color(255, 0, 0));
        strip1.setPixelColor(val[0], strip1.Color(255, 0, 0));
        strip2.setPixelColor(val[0], strip2.Color(255, 0, 0));
        strip3.setPixelColor(val[0], strip3.Color(255, 0, 0));
        strip0.setPixelColor(val[0]+1, strip0.Color(255, 0, 0));
        strip1.setPixelColor(val[0]+1, strip1.Color(255, 0, 0));
        strip2.setPixelColor(val[0]+1, strip2.Color(255, 0, 0));
        strip3.setPixelColor(val[0]+1, strip3.Color(255, 0, 0));
    }else{
      for (int i = 0; i < 60; i++) {
        strip0.setPixelColor(i, strip0.Color(0, val[1], val[1]));
        strip1.setPixelColor(i, strip1.Color(0, val[1], val[1]));
        strip2.setPixelColor(i, strip2.Color(0, val[1], val[1]));
        strip3.setPixelColor(i, strip3.Color(0, val[1], val[1]));
      }
    }
    strip0.show();
    strip1.show();
    strip2.show();
    strip3.show();
    delay(15);
  }
}
