#include <iostream>
#include <cstring>
#include "game.h"
//#include "parent.h"


using namespace std;


Videogame::Videogame() {
  //cout << "Videogame consturctor" << endl;
  int rating = 0;
  int year = 0;

  getPublisher();
  getRating();
  
}


/*
void game::title() {
  cout << "Enter a title for your videogame:" << endl;
  cin >> title;
  
}


void game::year() {



}
*/

int Videogame::getPublisher() {

  cout << "Please enter the publisher of your video game: " << endl;
  cin >> publisher;
  //cin.ignore();
  cout << "The publisher of " << title << " is: " << publisher << endl;
  
}

int Videogame::getRating() {

  cout << "Enter the rating of " << title << ": (1-5)" << endl;
  cin >> rating;
  cout << title << "is " << rating << " stars" << endl;

  cout << "YOUR GAME INFO: " << endl;
  cout << "Name: " << title << endl;
  cout << "Year created: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating of game: " << rating << " stars" << endl;

}


