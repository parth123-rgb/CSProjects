#include <cstring>
#include <iostream>
#include "parent.h"

using namespace std;


DigitalMedia::parent() {
  cout << "Parent Conustructor" << endl;
  int getYear = 0;

}

void DigitalMedia::getTitle() {

  cout << "Please emter the title to your digital media: " << endl;
  cin >> title;
  cout << "Your digital media title is:" << title << endl;
  
}


int DigitalMedia::getYear() {
  cout << "Please enter the year your digital media was created: " << endl;
  cin >> year;
  cout << "The year your digital media was created is: " << year << endl;


}
