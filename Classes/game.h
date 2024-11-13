/*
This is the videogame class file. 



 */


#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Videogame : public DigitalMedia  {

 public:
  // consturctor
  Videogame();
  char publisher[50];
  int rating;
  // variables for the videogames.cpp file
  void getPublisher();
  void getRating();
  //protected:

  // methods for the videogames.cpp file that are in use
  void printFunction();
  ~Videogame(); // deconstructor
};

  
