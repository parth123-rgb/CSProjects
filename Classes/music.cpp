#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;


Music::Music() {

  char duration[30];
  int year = 0;
  // publisher, artist, duration we code here
  getPublisher();
  getArtist();
  getDuration();

}



void Music::getPublisher() {

  cout << "Enter the publisher of this song: " << endl;
  //cin.ignore();
  cin.getline(publisher, 50, '\n');
  cout << "The publisher of your song is: " << publisher << endl;




}


void Music::getArtist() {

  cout << "Enter the artist of this song: " << endl;
  //  cin.ignore();
  cin.getline(artist, 50, '\n');
  cout << "The artist of this song is: " << artist << endl;


}



void Music::getDuration() {

  cout << "Please enter the duration of your song: " << endl;
  //cin >> duration;
  //cin.ignore();
  cin.getline(duration, 50, '\n');
  
  cout << "The duration of your song is: " << duration << endl;

  cout << "YOUR GAME INFO: " << endl;
  cout << "Name:" << title << endl;
  cout << "Year Created: " << year << endl;
  cout << "Artist: " << artist << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Duration: " << duration << endl;

  

}

