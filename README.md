# witbloxEmotionBlox
This repo contains the final code for the emotion blox

<h1>Project Explaination</h1>

Folders
Maker->maker.ino
Test->Anim.cpp, Anim.h, make.py, pics.h, test.ino

<h1>Files</h1>

<h2>Root:</h2>

|Name|Description|
|----|-----------|
|pics.h|Contains set of raw byte data for animation in c++ format|
|----|-----------|
|Vector.h|Contains Custom Vector libray for deconstruction and animation control|

<h2>maker:</h2>

|Name|Description|
|----|-----------|
|maker.h|Contains Firebase control interface for nodemcu,You can control animations through an app|
|----|-----------|
<h2>test:</h2>

|Name|Description|
|----|-----------|
|Anim.cpp,Anim.h|Animation Objects decomperssion and runtime code|
|----|-----------|
|make.py|Compressor code, makes byte comression|
|----|-----------|
|pics.h|Contains Latest raw byte data for animation|
|----|-----------|
|test.ino|Main file to upload onto nodemcu|

# Task List
 - [x] making test animations
 - [x] making jerk sensor code
 - [x] adding 4 inputs
 - [x] making more animations
 - [ ] code clean up
 - [x] optimizations

 # Changes Made On 22/06/2021
 - Remade Animations :+1:
 - Added New Animations 👍
 - Animations Are Now In HEX 👍
 - Added Inputs 👎
 - Made a new way to animate using 1D arrays 👍
 - Used Lossy Compression on animation frames 👍
 - Used New Custom Compressor On Res Frames 👍