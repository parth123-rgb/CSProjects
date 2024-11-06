#include <iostream>
#include <cstring>
#include "game.h"
//#include "parent.h"


using namespace std;


Videogame::VideoGame() {
  cout << "Videogame consturctor" << endl;
  int rating = 0;
  int year = 0;

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
  cin.getline(publisher, 50, '\n');
  cin.ignore();
  cout << "The publisher of" << title << "is: " << publisher;
  
}

int Videogame::getRating() {

  cout << "Enter the rating of (1-5)" << title << ": " << endl;
  cin >> rating;
  cout << title << "is " << rating << "stars" << endl;

}


