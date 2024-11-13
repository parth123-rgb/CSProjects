#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;


Music::Music() {
  // constructor
  char duration[30];
  int year = 0;

  // reintialzinig variables
  // publisher, artist, duration we code here
  getPublisher();
  getArtist();
  getDuration();
  // fucntions that are in use in this cpp file
  printFunction();
  
}


 
void Music::getPublisher() {
  // asks the user for the publisher
  cout << "Enter the publisher of this song: " << endl;
  //cin.ignore();
  // allows input
  cin.getline(publisher, 50, '\n');
  //cout << "The publisher of your song is: " << publisher << endl;




}

// asks the user for the artist and inputs it into variable
void Music::getArtist() {

  cout << "Enter the artist of this song: " << endl;
  //  cin.ignore();
  cin.getline(artist, 50, '\n');
  //cout << "The artist of this song is: " << artist << endl;


}


// asks the user the duration of the song. Allows semicolons!
void Music::getDuration() {

  cout << "Please enter the duration of your song: " << endl;
  //cin >> duration;
  //cin.ignore();
  cin.getline(duration, 50, '\n');
  
  //  cout << "The duration of your song is: " << duration << endl;
  

}
// collects all the informaiton and prints it out
void Music::printFunction() {


  
  cout << "YOUR GAME INFO: " << endl;
  cout << "Name:" << title << endl;
  cout << "Year Created: " << year << endl;
  cout << "Artist: " << artist << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Duration: " << duration << endl;

}

// this is for deleting using deconstrucotr when the user wishes to deconstruct.
Music:: ~Music() {
  //cout << " hello " << endl;
  delete[] artist;

  //cout << "Bye" << endl;
  delete publisher;
  delete duration;

}
