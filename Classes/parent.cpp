#include <cstring>
#include <iostream>
#include "parent.h"

using namespace std;
// parent.cpp file. 

DigitalMedia::DigitalMedia() {
  //int year = 0;
  // asks the user for the title and year of whatever they choose to enter
  cout << "Please enter the title your digital media was created: " << endl;
  cin.getline(title, 50, '\n');
  //cin.ignore();
  //cout << "The title your digital media was created is: " << year << endl;

 
  cout << "Please enter the year your digital media was created: " << endl;
  cin >> year;
  cin.ignore();
  //cout << "The year your digital media was created is: " << year << endl;
  
  
  




}

// returns title
char* DigitalMedia::getTitle() {



  
  return title;
   // change in the parnet.h file

}  


// returns year
int DigitalMedia::getYear() {
  
  return year;

}

void DigitalMedia::printFunction() {

  cout << "fhjhfjjfsf" << endl;

}
// deletes adn prints functions.
DigitalMedia::~DigitalMedia() {
  delete title;
  


}
