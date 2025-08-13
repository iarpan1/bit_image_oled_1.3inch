#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin (or -1 if sharing Arduino reset)
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Bitmap size
#define IMG_WIDTH  128
#define IMG_HEIGHT 64

// --- Your provided bitmap data ---
static const unsigned char PROGMEM pirateSkull[] = {
  0x00, 0x00, 0xFF, 0x81, /* ... continue your bitmap bytes here ... */
  // Make sure ALL the bytes you gave me are inside these curly braces
};

void setup() {
  display.begin(0x3C, true); // I2C address for SH1106 is usually 0x3C
  display.clearDisplay();
  display.drawBitmap(0, 0, pirateSkull, IMG_WIDTH, IMG_HEIGHT, SH110X_WHITE);
  display.display();
}

void loop() {
  // Nothing here - the image will stay on screen
}
