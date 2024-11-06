#include <cstring>
#include <iostream>
#include "parent.h"

using namespace std;


DigitalMedia::DigitalMedia() {
  int year = 0;
  getTitle();
  getYear();
}

void DigitalMedia::getTitle() {

  cout << "Please enter the title to your digital media: " << endl;
  cin >> title;
  cout << "Your digital media title is: " << title << endl;
  
}


int DigitalMedia::getYear() {
  cout << "Please enter the year your digital media was created: " << endl;
  cin >> year;
  cout << "The year your digital media was created is: " << year << endl;


}
