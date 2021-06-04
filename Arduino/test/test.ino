#include "pics.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED di splay width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
#define LOGO_HEIGHT   32
#define LOGO_WIDTH    128
bool screen_busy = false;
long rand_val = 0;
float reader = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void Blink(int rate = 50) {
  for (int i = 0; i < 5; i++) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _blink[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(rate);
  }
  for (int i = 4; i >= 0; i--) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _blink[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(rate);
  }
  delay(rate*2);
}
void Happy(int rate = 50) {
  for (int i = 0; i < 3; i++) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _happy[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(50);
  }
  delay(1000);
  for (int i = 2; i >= 0; i--) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _happy[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(50);
  }
}
void Angry(int rate = 50) {
  for (int i = 0; i < 3; i++) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _angry[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(50);
  }
  delay(1000);
  for (int i = 2; i >= 0; i--) {
    display.clearDisplay();
    display.drawBitmap(0, 0, _angry[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(50);
  }
}
void setup() {
  Serial.begin(115200);
  pinMode(14, INPUT);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}
void loop() {
  reader = digitalRead(14);
  if(reader){
  Serial.print("::");
  Serial.println(reader);
  make();
  delay(10);    
  }
}


int make(){
  rand_val = random(100);
  if(screen_busy){
    return(0);
  }
  screen_busy = true;
  if(rand_val<=20){
    Happy();
    Serial.println(1);
  }else if(rand_val>20 && rand_val<=60){
    Blink();
   Serial.println(2); 
  }else if(rand_val>60 && rand_val<=80){
   Serial.println(3); 
  }else if(rand_val>80 && rand_val<=95){
   Serial.println(4); 
  }else if(rand_val>95 && rand_val<=100){
    Angry();
   Serial.println(5); 
  }
  Serial.print("Random Value = ");
  Serial.println(rand_val);
  screen_busy = false;
}
