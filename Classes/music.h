
/*
This is the class for the music


 */


#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Music : public DigitalMedia {

public: // the vriables in here will be used publically... 
  Music(); // constructor
  char artist[50];
  //int duration;
  char duration[30];
  char publisher[50];

  // functions in the music.cpp file
  
  void getPublisher();
  void getArtist();
  void getDuration();
  void printFunction();
  ~Music(); // deconstructor
  
};
