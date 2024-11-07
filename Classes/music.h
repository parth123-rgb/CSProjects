#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Music : DigitalMedia {

 public:
  Music();
  char artist[50];
  //int duration;
  char duration[30];
  char publisher[50];

  void getPublisher();
  void getArtist();
  void getDuration();

};
