#include <FastLED.h>
#define NUM_LEDS 60
#define PIN 2
int t = 0;
int a = 0;
LIB8STATIC fract8 ease8InOutApprox  ( fract8  i );
LIB8STATIC uint8_t quadwave8  ( uint8_t   in  );

CRGB leds[NUM_LEDS];

int arr[NUM_LEDS][3] = {  //initial rgb value for each led
  {255, 191, 0},
  {255, 135, 0},
  {255, 191, 0},
  {255, 135, 0},
  {255, 191, 0},
  {246, 241, 240},
  {246, 241, 240},
  {246, 241, 240},
  {246, 241, 240},
  {246, 241, 240},
  {178, 212, 211},
  {178, 212, 211},
  {178, 212, 211},
  {178, 212, 211},
  {178, 212, 211},
  {226, 135, 67},
  {226, 135, 67},
  {226, 135, 67},
  {226, 135, 67},
  {226, 135, 67},
  {255, 246, 219},
  {255, 246, 219},
  {255, 246, 219},
  {255, 246, 219},
  {255, 246, 219},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {252, 3, 3},
  {252, 3, 3},
  {252, 3, 3},
  {252, 3, 3},
  {252, 3, 3},
  {0, 0, 0},
  {209, 213, 214},
  {255, 255, 255},
  {209, 213, 214},
  {0, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 0, 0},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
  {255, 255, 255},
};


void setup() {
  FastLED.addLeds<WS2811, PIN>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++) {  //sets the inital values of the leds as set in arr
    leds[i].setRGB(arr[i][2], arr[i][0], arr[i][1]);
  }

  FastLED.show();
}

void loop() {
  delay(10);
  t++;
  if (t == 500) { //timer
    t = 0;
  }

  a += 1;
  if (a == 255) { //hue timer
    a = 0;
  }


  //group 2
  if ((0 < t) && (t < 100)) {
    for (int i = 5; i < 10; i++) {
      leds[i].setRGB(240, 246, 241);
    }
  }
  else {
    for (int i = 5; i < 10; i++) {
      leds[i].setRGB(0, 0, 0);
    }
  }

  //group 3
  int rand = random(10, 14);
  if (t % 10 == 0) {
    for (int i = 10; i < 15; i++) {
      if (i == rand) {
        leds[i].setRGB(211, 178, 212);
      }
      else {
        leds[i].setRGB(0, 0, 0);
      }
    }
  }

  //group 7
  if (t % 10 == 0) {
    if (t % 20 == 0) {
      for (int i = 30; i < 35; i++) {
        leds[i].setRGB(3, 252, 3);
      }
    }
    else {
      for (int i = 30; i < 35; i++) {
        leds[i].setRGB(0, 0, 0);
      }
    }
  }
  //group 9
  for (int i = 40; i < 45; i++) {
    leds[i].setHSV(a, 255, 255);
  }
  FastLED.show();
}
