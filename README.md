# witbloxEmotionBlox
This repo contains the final code for the emotion blox

<h1>Project Explaination</h1>

Folders
Maker->maker.ino
Test->Anim.cpp, Anim.h, make.py, pics.h, test.ino

<h1>Files</h1>
Root:
    pics.h
        Contains set of raw byte data for animation in c++ format
    Vector.h
        Contains Custom Vector libray for deconstruction and animation control

maker:
    maker.h
        Contains Firebase control interface for nodemcu,
        You can control animations through an app

test:
    Anim.cpp,Anim.h
        Animation Objects decomperssion and runtime code,
    make.py
        Compressor code, makes byte comression
    pics.h
        Contains Latest raw byte data for animation
    test.ino
        Main file to upload onto nodemcu