#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Videogame : DigitalMedia  {

 public:
  Videogame();
  char publisher[50];
  int rating;
  void getPublisher();
  void getRating();
  //protected:
  

};

  
