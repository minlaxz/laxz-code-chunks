#include <FastLED.h>

#define LED_PIN     13
#define NUM_LEDS    32
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

int leftSignal = 10;
int rightSignal = 11;

int l , r;
int flag;

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRGY PROGMEM;
unsigned long timer;

void setup() {
  delay(1000); // power-up safety delay_1
  pinMode(leftSignal, INPUT_PULLUP);
  pinMode(rightSignal, INPUT_PULLUP);
  delay( 2000 ); // power-up safety delay_2
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {

  l = digitalRead(leftSignal);
  r = digitalRead(rightSignal);

  if (l == 0 && r == 1) {
    timer = millis();
    do {
      flag = 0 ;
      BlackAndWhite();
    } while (millis() - timer < 2500);
  }

  else if (r == 0 && l == 1) {
    timer = millis();
    do {
      flag = 1 ;
      BlackAndWhite();
    } while (millis() - timer < 2500);
  }

  else if (l == 0 && r == 0) {
    timer = millis();
    do {
      flag = 2 ;
      BlackAndWhite();
    } while (millis() - timer < 2500);
  }

  else {
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
    static uint8_t startIndex = 0;
    startIndex = startIndex + 1; /* motion speed */

    FillLEDsFromPaletteColors_B_RGY( startIndex); //

    FastLED.show();
    FastLED.delay(1000 / UPDATES_PER_SECOND);
  }
}

void BlackAndWhite() {
  SetupBlackAndWhiteStripedPalette();
  currentBlending = LINEARBLEND;
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  switch (flag) {
    case 0: //left
      FillLEDsFromPaletteColors_L( startIndex); //
      break;
    case 1:
      FillLEDsFromPaletteColors_R( startIndex); //
      break;
    case 2:
      FillLEDsFromPaletteColors_B( startIndex); //
      break;
  }
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors_R( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  for ( int i = NUM_LEDS - 1 ; i >= 0; i--) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

void FillLEDsFromPaletteColors_L( uint8_t colorIndex)
{
  uint8_t brightness = 255;
  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

void FillLEDsFromPaletteColors_B( uint8_t colorIndex)
{
  ////0, 1, 2, 3, 4, 5, 6,7
  ////15,14,13,12,11,10,9,8

  uint8_t brightness = 255;
  for ( int i = 0 ; i <= 7; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    leds[15 - i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

void FillLEDsFromPaletteColors_B_RGY( uint8_t colorIndex)
{
  currentPalette = myRGY;
  currentBlending = LINEARBLEND;

  uint8_t brightness = 255;
  for ( int i = 0 ; i <= 7; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    leds[15 - i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

void SetupBlackAndWhiteStripedPalette()
{
  fill_solid( currentPalette, 16, CRGB::Black);
  currentPalette[0] = CRGB::White;
  currentPalette[4] = CRGB::White;
  currentPalette[8] = CRGB::White;
  currentPalette[12] = CRGB::White;

}

const TProgmemPalette16 myRGY PROGMEM =
{
  CRGB::Red,
  CRGB::Purple,
  CRGB::Cyan,
  

  CRGB::Gray,
  CRGB::Gray,
  CRGB::Gray,
  
  CRGB::Black,
  CRGB::Black,

  CRGB::Red,
  CRGB::Red,
  CRGB::Purple,
  CRGB::Purple,
  CRGB::Cyan,
  CRGB::Cyan,
  CRGB::Black,
  CRGB::Black

};
