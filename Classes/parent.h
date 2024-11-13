/*

This is the parent class. EVERYTHING IN HERE will be inherited by the child.


 */



#ifndef CLASSES
#define CLASSES

#include <cstring>

using namespace std;

class DigitalMedia {
  // variables that the child can use
 protected:
  char title[50];
  int year;

 public:
  // creating constructor
  DigitalMedia();
  DigitalMedia(char* title, int year);
  char* getTitle();
  // methods that will be in the parent.cpp file.
  int getYear();
  // virtual functions for printing out everything, and deleting what needed.
  virtual void printFunction();
  virtual ~DigitalMedia();
};

#endif
