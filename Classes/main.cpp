#include <iostream>
#include <cstring>
#include <vector>
#include "game.h"
#include "parent.h"


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

	    exit(0);
	         }
	
}










void mediaFunction(vector<DigitalMedia*>& media) {


  char input[15]; 

  /*
  char title[50];
  int year;
  char publisher[50];
  int rating;
  char artist[50];
  char duration[10];
  char director[50];
  */


  cout << "What type of media do you wish to add? (Type VIDEOGAMES / MUSIC / MOVIES)" << endl;

  cin >> input;

  if (strcmp(input, "VIDEOGAMES") == 0) {

    // Videogame* v = new Videogame();

    }





  
  
  

}
