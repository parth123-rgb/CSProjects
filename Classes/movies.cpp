#include <cstring>
#include <iostream>
#include "movies.h"

using namespace std;

Movies::Movies() {

  int year = 0;

  // director, duration, and rating we code here
  getDirector();
  getDuration();
  getRating();


}


void Movies::getDirector() {

  cout << "Enter the director of the movie: " << endl;
  cin.getline(director, 40, '\n');
  

}

void Movies::getDuration() {

  cout << "Enter the duration of the movie: " << endl;
  cin.getline(duration, 40, '\n');
  

}

void Movies::getRating() {

  cout << "Enter the rating of the movie: " << endl;
  cin.getline(rating, 40, '\n');
  

}


void Movies::printFunction() {


  cout << "MOVIE INFO: " << endl;
  cout << "Movie name: " << title << endl;
  cout << "Movie Year: " << year << endl;
  cout << "Director name: " << director << endl;
  cout << "Movie Duration: " << duration << endl;
  cout << "Movie rating: " << rating << endl;






}
