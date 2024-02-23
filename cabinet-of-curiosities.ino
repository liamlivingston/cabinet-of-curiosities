#include <FastLED.h>
#define NUM_LEDS 6
#define PIN 10
CRGB leds[NUM_LEDS];

int arr[NUM_LEDS][3] = {
  {25, 2, 3},
  {1, 25, 3},
  {1, 2, 25},
  {25, 2, 3},
  {1, 25, 3},
  {1, 2, 25}
};

void setup() {
  delay(3000);
  FastLED.addLeds<WS2811, PIN>(leds, NUM_LEDS);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setRGB(arr[i][0], arr[i][1], arr[i][2]);
    FastLED.show();
  }
}
