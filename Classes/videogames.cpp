#include <iostream>
#include <cstring>
#include "game.h"
//#include "parent.h"


using namespace std;


Videogame::Videogame() : DigitalMedia() {
  //cout << "Videogame consturctor" << endl;
    //  int rating = 0;
    //year = 0;

  getPublisher();
  getRating();
  printFunction();

}


/*
void game::title() {
  cout << "Enter a title for your videogame:" << endl;
  cin >> title;
  
}


void game::year() {



}
*/

void Videogame::getPublisher() {

  cout << "Please enter the publisher of your video game: " << endl;
  cin >> publisher;
  //cin.ignore();
  //cout << "The publisher of " << title << " is: " << publisher << endl;
  
}

void Videogame::getRating() {

  cout << "Enter the rating of " << title << ": (1-5)" << endl;
  cin >> rating;
  cout << title << "is " << rating << " stars" << endl;

}

void Videogame::printFunction() {

  cout << "YOUR GAME INFO: " << endl;
  cout << "Title: " << title << endl;
  cout << "Year created: " << year << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Rating of game: " << rating << " stars" << endl;




}

Videogame:: ~Videogame() {

  delete publisher;
  

}
