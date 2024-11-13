#include <iostream>
#include <cstring>
#include <vector>
#include "game.h"
#include "parent.h"
#include "music.h"
#include "movies.h"


using namespace std;

// function prototypes
void mediaFunction(vector<DigitalMedia*>& media);
void searchFunction(vector<DigitalMedia*>& media);
void deleteFunction(vector<DigitalMedia*>& media);


int main() {
  
  char addFunction[50]; // variable for checking what the user wishes to do.
  bool addUser = true;
  
  vector<DigitalMedia*> media; // creating vector to save stuff


  while (addUser) { // asks the userif they wish to add, search, dleete, quit
  cout << "If you wish to add any medias, type ADD" << endl;
  cout << "If you wish to search for an object, type SEARCH " << endl;
  cout << "If you wish to delete an object, type DELETE " << endl;
  cout << "If you wish to quit, type QUIT" << endl;

  
  cin >> addFunction; // enters it in
  cin.ignore();

  if (strcmp(addFunction, "ADD") == 0)
    {
      mediaFunction(media); // if the user enters add play the add function
      
     }
    else if (strcmp(addFunction, "SEARCH") == 0) {
      searchFunction(media); // if the user wishes to search play the search function
      //cout << "Enter the title or year you wish to search for: " << endl;
	
      }
      else if (strcmp(addFunction, "DELETE") == 0) {
	deleteFunction(media); // if the user wishe st odeelte will play the delete function
	//cout << "Enter the title or year you wish to delete, this will delete the entire object: " << endl;

	}
      else if (strcmp(addFunction, "QUIT") == 0) { // if the user wishes to quit, system should ned.
	cout << "Thanks for playing classes!" << endl;
	    exit(0);
	     }
     }
}




void mediaFunction(vector<DigitalMedia*>& media) { // function for adding stuff


  char input[15]; 
  // asking the user if they wish to add a media type of videogames, music, or movies.
  cout << "What type of media do you wish to add? (Type VIDEOGAMES / MUSIC / MOVIES)" << endl;

  cin >> input;
  cin.ignore();
  
  if (strcmp(input, "VIDEOGAMES") == 0) {

    Videogame* v = new Videogame();
    media.push_back(v); // creates new videogame, if the user enter videogame
    }
  else if (strcmp(input, "MUSIC") == 0) {

    Music* m = new Music(); // creates new music if the user enters music
    media.push_back(m);
  }
  else if (strcmp(input, "MOVIES") == 0) {


    Movies* m = new Movies(); // creates new movies, if the user enter movies.
    media.push_back(m);

  }

}




void searchFunction(vector<DigitalMedia*>& media) { // function for when the user wishes to search

  int searchYear;
  char searchTitle[50];
  //int year;
  char yearOrTitle[50];
  
  cout << "Do you want to enter a year or title?" << endl;
  cin >> yearOrTitle;
  cin.ignore(); // asks the user if they wish to search using the year or title
  
  if (strcmp(yearOrTitle, "Year") == 0) {
  cout << "Enter the year that you wish to search: " << endl;
  cin >> searchYear;
  // if user wisehs to ente year.
  
  for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); it++) {
    // iterators....
    
    //cout << "Test" << endl;
    if ((*it) -> getYear() == searchYear) {
      (*it) -> printFunction();
      // compares the getyear that is saevd from any time in the system to the year that the user just entered.. it should print otu eveyrthigmg


  cin.ignore();





      }
  }

 }




  else if (strcmp(yearOrTitle, "Title") == 0) {
  cout << "Enter the Title that you wish to search: " << endl;
  cin >> searchTitle;
  cin.ignore(); // same functionatlity for if the user enters title.

  for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); it++) {

    //cout << "Test" << endl;
    if (strcmp((*it) -> getTitle(), searchTitle) == 0){
      (*it) -> printFunction();
	





      }
  }

 }

}





// fpr deleting things from the vector
void deleteFunction(vector<DigitalMedia*>& media) {

  int deleteYear;
  char deleteTitle[50];
  //int year;
  char deleteYearOrTitle[50];

  // asks the user if thye want to enter year/tit;e
  
  cout << "Do you want to delete a year or title?" << endl;
  cin >> deleteYearOrTitle;
  cin.ignore();
  
  if (strcmp(deleteYearOrTitle, "Year") == 0) {
  cout << "Enter the year that you wish to delete: " << endl;
  cin >> deleteYear;

  
  for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); ++it) {

    //cout << "Test" << endl;
    if ((*it) -> getYear() == deleteYear) {
      delete *it; // deletes the thing that is created if compariosn is true
      media.erase(it);
      
      
      //(*it) -> ~DigitalMedia();
	


      //cin.ignore();

      return;


      }
  }

 }



  else if (strcmp(deleteYearOrTitle, "Title") == 0) { // same with title
  cout << "Enter the Title that you wish to delete: " << endl;
  cin.getline(deleteTitle, 50, 'n');
  //cin.ignore();

  for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); ++it) {

    //cout << "Test" << endl;
    if (strcmp((*it) -> getTitle(), deleteTitle) == 0){
      // (*it) -> ~DigitalMedia();
      delete *it;
      media.erase(it);
	

      return;



      }
  }

 }

}







/*






  /*
  else if (strcmp(yearOrTitle, "Title") == 0) {
  cout << "Please enter the title to your digital media: " << endl;
  cin.getline(title, 50, '\n');
  

  cout << "Please enter the year to your digital media:" << endl;
  cin >> year;
  cin.ignore();

  
  cin >> searchInput;
  }


  
  // if (year == searchInput) == 0) {

   
	//  }

    }
  }

    }
}
  */
