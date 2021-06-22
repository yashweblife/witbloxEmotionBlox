#include "pics.h"
#include "angry.h"
#include "distressed.h"
#include "normal.h"
#include "sad.h"
#include "smile.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED di splay width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
#define LOGO_HEIGHT   32
#define LOGO_WIDTH    128

int d1 = 50;
int d2 = 1000;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  pinMode(14, INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(15,INPUT);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}

void loop() {
  for(int i = 0;i<angryallArray_LEN;i++){
  display.clearDisplay();
  display.drawBitmap(0, 0, angryallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
  display.display();
  delay(d1*i);
  }
  delay(d2);
  for(int i = 0;i<distressedallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, distressedallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(d1*i);
  }
  delay(d2);
  for(int i = 0;i<normalallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, normalallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(d1*i);
  }
  delay(d2);
  for(int i = 0;i<sadallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, sadallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(d1*i);
  }
  delay(d2);
  for(int i = 0;i<happyallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, happyallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(d1*i);
  }
  delay(d2);
}
