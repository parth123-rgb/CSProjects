#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Movies : public DigitalMedia {

 public:
  Movies(); // constructor
  char director[40]; // creating variables that will be in use for the movies.cpp file
  char duration[40];
  char rating[40];


  // methods that will be in use in the movies.cpp file
  void getDirector();
  void getDuration();
  void getRating();

  void printFunction();
  ~Movies();
  
};
