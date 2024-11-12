#include <iostream>
#include <cstring>
#include <vector>
#include "game.h"
#include "parent.h"
#include "music.h"
#include "movies.h"


using namespace std;


void mediaFunction(vector<DigitalMedia*>& media);



int main() {

  char addFunction[50];
  
  
  vector<DigitalMedia*> media;

  cout << "If you wish to add any medias, type ADD" << endl;
  cout << "If you wish to search for an object, type SEARCH " << endl;
  cout << "If you wish to delete an object, type DELETE " << endl;
  cout << "If you wish to quit, type QUIT" << endl;

  
  cin >> addFunction;
  cin.ignore();

  if (strcmp(addFunction, "ADD") == 0)
    {
      mediaFunction(media);
      
     }
    else if (strcmp(addFunction, "SEARCH") == 0) {

	cout << "Enter the title or year you wish to search for: " << endl;
	
      }
      else if (strcmp(addFunction, "DELETE") == 0) {

	  cout << "Enter the title or year you wish to delete, this will delete the entire object: " << endl;

	}
      else if (strcmp(addFunction, "QUIT") == 0) {
	cout << "Thanks for playing classes!" << endl;
	    exit(0);
	     }
	
}




void mediaFunction(vector<DigitalMedia*>& media) {


  char input[15]; 

  cout << "What type of media do you wish to add? (Type VIDEOGAMES / MUSIC / MOVIES)" << endl;

  cin >> input;
  cin.ignore();
  
  if (strcmp(input, "VIDEOGAMES") == 0) {

    Videogame* v = new Videogame();

    }
  else if (strcmp(input, "MUSIC") == 0) {

    Music* m = new Music();

  }
  else if (strcmp(input, "MOVIES") == 0) {


    Movies* m = new Movies();
  }

}





void searchFunction(vector<DigitalMedia*> media) {

  char searchInput[15];
  cout << "Please enter the Digital Media Year or Name you want to search through " << endl;
  cin.getline(searchInput, 15, '\n');
  
  

  
  for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); it++) {
    // create an iterator, then we will print out the all the student information when the user wishes to

    if (strcmp(searchInput,  

    cout << (*it) ->  << " " << (*it) -> lastName << ", " << (*it) -> studentID << ", " << fixed << setprecision(2) << (*it) -> studentGPA << endl;
  }



}
x
