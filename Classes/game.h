#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Videogame : DigitalMedia  {

 public:
  VideoGame();
  char publisher[50];
  int rating;
  int getPublisher();
  int getRating();
 protected:
  

};
