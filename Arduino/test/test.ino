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

const int buzzer = 9;
const int indicator = 10;
const int toggle = 7;
const int inp1 = 2;
const int inp2 = 3;
const int inp3 = 4;
const int inp4 = 5;
const int sensor = A0;
const int gpioSize = 8;
const int gpioSet[gpioSize] = {
  buzzer,
  indicator,
  toggle,
  inp1,
  inp2,
  inp3,
  inp4,
  sensor
  };

bool _mode = false;

void initAll(){
  Serial.begin(9600);
  pinMode(gpioSet[0],OUTPUT);
  pinMode(gpioSet[1],OUTPUT);
  pinMode(gpioSet[2],INPUT);
  pinMode(gpioSet[3],INPUT);
  pinMode(gpioSet[4],INPUT);
  pinMode(gpioSet[5],INPUT);
  pinMode(gpioSet[6],INPUT);
  pinMode(gpioSet[7],INPUT);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  for(int i = 0;i<4;i++){
    digitalWrite(gpioSet[1],1);
    delay(200);
    digitalWrite(gpioSet[1],1);    
  }
}

void activateWakeUp(int a = d1){
  
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

void checkMode(){
  if(digitalRead(toggle)){
    _mode = true;
  }else{
    _mode = false;
  }
}
void runTime(){
  if(_mode == true){
    int duration = pulseIn(sensor,HIGH);
    Serial.println(duration);
  }
  else{
    if(digitalRead(inp1)){
      activateAngry();
    }
    else if(digitalRead(inp2)){
      activateHappy();
    }
    else if(digitalRead(inp3)){
      activateDistress();
    }
    else if(digitalRead(inp4)){
      activateSad();
    }
    else{
      activateNormal();
    }
  }
}


void newSetup(){
  initAll();
  activateWakeup();
  activateNormal();
}
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
  
}
