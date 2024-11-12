#include <cstring>
#include <iostream>
#include "parent.h"

using namespace std;


DigitalMedia::DigitalMedia() {
  int year = 0;
  getTitle();
  getYear();
}

char* DigitalMedia::getTitle() {

   // change in the parnet.h file

  
  cout << "Please enter the title to your digital media: " << endl;
  cin.getline(title, 50, '\n');
  //cin.ignore();
  cout << "Your digital media title is: " << title << endl;

 
  
}


int DigitalMedia::getYear() {
  cout << "Please enter the year your digital media was created: " << endl;
  cin >> year;
  cin.ignore();
  cout << "The year your digital media was created is: " << year << endl;


}
