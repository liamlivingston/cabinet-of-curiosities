#include <FastLED.h>
#define NUM_LEDS 60
#define PIN 2
int t = 0;
LIB8STATIC fract8 ease8InOutApprox  ( fract8  i );
LIB8STATIC uint8_t quadwave8  ( uint8_t   in  );

CRGB leds[NUM_LEDS];

int arr[NUM_LEDS][3] = {  //initial rgb value for each led
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {235, 136, 75},
  {75, 198, 235},
  {235, 136, 75},
  {75, 198, 235},
  {235, 136, 75},
  {79, 79, 79},
  {79, 79, 79},
  {79, 79, 79},
  {100, 255, 55},
  {62, 255, 55},
  {240, 235, 218},
  {240, 235, 218},
  {240, 235, 218},
  {240, 235, 218},
  {240, 235, 218},
  {243, 245, 249},
  {243, 245, 249},
  {243, 245, 249},
  {243, 245, 249},
  {243, 245, 249},
  {252, 3, 132},
  {252, 3, 132},
  {252, 3, 132},
  {252, 3, 132},
  {252, 3, 132},
  {87, 3, 255},
  {87, 3, 255},
  {87, 3, 255},
  {87, 3, 255},
  {87, 3, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {155, 10, 10},
  {155, 10, 10},
  {30, 200, 130},
  {30, 200, 130},
  {30, 200, 130},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {238, 238, 221},
  {238, 238, 221},
  {238, 238, 221},
  {238, 238, 221},
  {238, 238, 221},
};


void setup() {
  FastLED.addLeds<WS2811, PIN>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++) {  //sets the inital values of the leds as set in arr
    leds[i].setRGB(arr[i][2], arr[i][0], arr[i][1]);
  }

  FastLED.show();
}

void loop() {
  delay(100);
  t++;
  if (t == 90) { //timer
    t = 0;
  }

  //group 1
  if (((0 < t) && (t < 5)) || ((30 < t) && (t < 35)) || ((60 < t) && (t < 65))) {
    for (int i = 0; i < 5; i++) {
      leds[i].setRGB(0, 255, 0);
    }
  }
  else {
    for (int i = 0; i < 5; i++) {
      leds[i].setRGB(0, 0, 0);
    }
  }

  //group 3 -  dont understand what they want
  if ((0 < t) && (t < 45)) {

  }

  //group 7
  if ((0 < t) && (t < 45)) {
    for (int i = 30; i < 35; i++) {
      leds[i].setRGB(int(255 - 3.56 * t + 0.5), int(87 + 3.73 * t + 0.5), 3);
    }
  }
  else if ((44 < t) && (t < 90)) {
    for (int i = 30; i < 35; i++) {
      leds[i].setRGB(int(95 + 3.56 * (t - 45) + 0.5), int(255 - 3.73 * (t - 45) + 0.5), 3);
    }
  }
  FastLED.show();
}
