#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED di splay width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     LED_BUILTIN // Reset pin # (or -1 if sharing Arduino reset pin)
#define LOGO_HEIGHT   32
#define LOGO_WIDTH    128

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int d1 = 50;

void activateLogo(int a = d1){
  for(int i = 0;i<logoallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, logoallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
  delay(1000);
  display.clearDisplay();
  display.setTextSize(1.5);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(SCREEN_WIDTH/2-(7), 4);
  display.write("For");
  display.setCursor(SCREEN_WIDTH/2-(3*7), 12);
  display.write("Endless");
  display.setCursor(SCREEN_WIDTH/2-(5*7), 20);
  display.write("Innovations");
  display.display();
  delay(1000);
}

void activateWakeUp(int a = d1){
  for(int i = 0;i<wakeupallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, wakeupallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
}

void activateNormal(int a = d1){
  for(int i = 0;i<normalallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, normalallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
}

void activateAngry(int a = d1){
  for(int i = 0;i<angryallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, angryallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
}

void activateDistress(int a = d1){
  for(int i = 0;i<distressedallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, distressedallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
}

void activateSad(int a = d1){
  for(int i = 0;i<sadallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, sadallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  } 
}

void activateHappy(int a = d1){
  for(int i = 0;i<happyallArray_LEN;i++){
    display.clearDisplay();
    display.drawBitmap(0, 0, happyallArray[i], LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
    delay(a*i);
  }
}

void activateWaiting(int a){
  activateNormal();
  delay(a);
}
