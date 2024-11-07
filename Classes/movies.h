#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Movies : DigitalMedia {

 public:
  Movies();
  char director[40];
  char duration[40];
  char rating[40];

  void getDirector();
  void getDuration();
  void getRating();


};
