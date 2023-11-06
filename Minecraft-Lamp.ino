#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN   2
#define PIXEL_PIN    9  // Use pull-up resistor
#define PIXEL_COUNT  6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

volatile byte state = HIGH;
int showType = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),changeState ,FALLING);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() {
  if (state == LOW) {
      showType++;
      if (showType > 5)
        showType=0;
     startShow(showType); 
   }

state = HIGH;
}

void changeState(){
  state = !state;
}

void startShow(int i) {
  switch(i){
    case 0: colorWipe(strip.Color(0, 0, 0), 10);    // Black/off
            break;
    case 1: colorWipe(strip.Color(255, 0, 0), 10);  // Redstone
            break;
    case 2: colorWipe(strip.Color(0, 255, 0), 10);  // Emerald
            break;
    case 3: colorWipe(strip.Color(0, 0, 255), 10);  // Lapis Lazuli
            break;
    case 4: colorWipe(strip.Color(255, 100, 0), 10);  // Gold
            break;
    case 5: colorWipe(strip.Color(100, 245, 228), 10);  // Diamond
            break;  
            
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
