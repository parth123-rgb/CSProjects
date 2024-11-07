#ifndef CLASSES
#define CLASSES

#include <cstring>

using namespace std;

class DigitalMedia {

 protected:
  char title[50];
  int year;

 public:
  DigitalMedia();
  DigitalMedia(char* title, int year);
  void getTitle();
  void getYear();
};

#endif
