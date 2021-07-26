#include "angry.h"
#include "distressed.h"
#include "normal.h"
#include "sad.h"
#include "smile.h"
#include "wakeup.h"
#include "animations.h"

#include <Wire.h>

const int buzzer = 9;//2
const int indicator = 10;//0
const int toggle = 7;//3;
const int inp1 = 2;//14;
const int inp2 = 3;//12;
const int inp3 = 4;//13;
const int inp4 = 5;//15;
const int sensor = A0;
bool _mode = false;

void initAll(){
  Serial.begin(115200);
  pinMode(buzzer,OUTPUT);
  pinMode(indicator,OUTPUT);
  pinMode(toggle,INPUT);
  pinMode(inp1,INPUT);
  pinMode(inp2,INPUT);
  pinMode(inp3,INPUT);
  pinMode(inp4,INPUT);
  pinMode(sensor,INPUT);
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  randomSeed(analogRead(0));
  
  for(int i = 0;i<4;i++){
    digitalWrite(indicator,1);
    delay(200);
    digitalWrite(indicator,1);    
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
  activateWakeUp();
  activateNormal();
  checkMode();
}

void newLoop(){
  runTime();
}
void setup() {
newSetup();
}
void loop() {
  //activateWakeUp();
  //activateNormal();
newLoop();  
}
