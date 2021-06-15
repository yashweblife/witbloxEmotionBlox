#ifndef Anim_h
#define Anim_h
#include "Arduino.h"

class Animation{
  public:
  Animation(const unsigned char _value[][8192], int _index);
  void play(int vel);
  int index;
  const unsigned char value[][8192];
};

#endif
