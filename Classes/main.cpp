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


for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); it++) {
    // create an iterator, then we will print out the all the student information when the user wishes to
    cout << (*it) ->  << " " << (*it) -> lastName << ", " << (*it) -> studentID << ", " << fixed << setprecision(2) << (*it) -> studentGPA << endl;
  }



}

  cin >> input;

  if (strcmp(input, "VIDEOGAMES") == 0) {

    Videogame* v = new Videogame();

    }

}





void searchFunction(vector<DigitalMedia*>& media) {

  char searchInput[50];
  char title[50];
  char year[50];
  char yearOrTitle[50];

  cout << "Please enter the title to your digital media: " << endl;
  cin.getline(title, 50, '\n');


  cout << "Please enter the year to your digital media:" << endl;
  cin >> year;
  cin.ignore();

  cout << "Do you want to enter a year or title?" << endl;

  if (strcmp(yearOrTitle, "Year") {
  cout << "Enter the year or title name that you wish to search: " << endl;
  cin >> searchInput;
  }

  if (strcmp(year, searchInput) == 0) {

    for (vector<DigitalMedia*>:: iterator it = media.begin(); it != media.end(); it++) {
      if (strcmp((it*) -> year, year) == 0) {
    // create an iterator, then we will print out the all the student information when the user wishes to




      }

    }
  }

    }
}


