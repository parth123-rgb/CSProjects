/*

Parth Chaudhary
Mr. Galbraith
C++ / Data Structures DC
23 October 2024


This program is called student list. It allows the user to enter a new student name, last name, student ID, and GPA. The user can then choose to reprint these values out. They can also delete a student by typing delete, following with the student ID number they wish to delete. The user can also quit the system by typing, quit!

 */









#include <iostream>
#include <cstring>
#include <vector>




using namespace std;

// creating struct with variables ( will use a vector pointer later )
struct Student {

  char firstName[50];
  char lastName[50];
  int studentID;
  float studentGPA;
 

};

// declaring functions before used
void addFunction(vector<Student*> & v);
void printFunction(vector<Student*> v);
void deleteMethod(vector<Student*> &v);
// function prototypes 



int main() { // creating vector and assigning it to the variable 'v'
  vector<Student*> v;
  char addAndPrintPlayer[7]; // this char array will be used for if the player wishes to add a student, print, delete, or quit the game
  bool addPlayer = true; // this boolean will be used for a while loop, ensuring the game keeps playing.
  //int deleteStudentID;
  //char quitSys[5]; 
  // v = new vector<Student*>();
 


  while (addPlayer) {
    // here we ask the user if they wish to add , print , delete ,or quit the system.
  cout << "If you want to add a student, type 'ADD'" << endl;
    cout << "If you want to print the saved players, type 'PRINT' " << endl; 
    cout << " If you want to delete a player, type 'DELETE' " << endl;
    cout << " If you want to quit, type 'QUIT': " << endl;
	    
	    cin >> addAndPrintPlayer; // we will assign whatever they say to the variable on our left.
  //cin >> addAndPrintPlayer;


    if (strcmp(addAndPrintPlayer, "ADD") == 0) { // if the user says they wish to add, we will run the add mehtod
    addFunction(v);
  
  }
  
  else if (strcmp(addAndPrintPlayer, "PRINT") == 0) {
    printFunction(v); // if the user wishes to print the users, we will run the print method
    /*
    cout << "Do you want to quit? (Yes / No) " << endl;
    cin >> quitSys;

    if (strcmp(quitSys, "Yes") == 0) {
      exit(0);


      }
    */
      }
  //else if

    // if the user wishes to delete a player ,we will run the delete method
  else if (strcmp(addAndPrintPlayer, "DELETE") == 0) {

    
    deleteMethod(v);

    //addPlayer = true;
    }

    // if the user wants to quit , system will end.
  else if (strcmp(addAndPrintPlayer, "QUIT") == 0) {
    cout << "Your students will miss you..." << endl;
    addPlayer = false;
    }
  }
}



// our addFunction method, for when the user wishes to add a new student
void addFunction(vector<Student*> & v) { // passing the vector (with the struct in) through the parameter.
  Student* newStudent = new Student(); // will create a new student
  char firstName[50]; // getting first name
  char lastName[50]; // for getting last name
  

  cout << "Enter your first name: " << endl;
  cin >> newStudent -> firstName; // ask the user their first and last name and assign it ot the variable fisr name (we used newStudent -> because we want this to happen each time a new student is created)
  cout << "Enter your last name: " << endl;
  // cin.ignore();
  cin >> newStudent -> lastName;
  // strcpy(newStudent -> lastName, lastName);
  //  cin.ignore();
  cout << "Enter your student ID: " << endl;
  cin >> newStudent -> studentID; // asks for student id and GPA, then assigns it to designated variable.
  //int deleteStudentID = newStudent -> studentID;
  cout << "Enter your GPA: " << endl;
  cin >>  newStudent -> studentGPA;



  // cout << newStudent -> firstName << ", " << newStudent -> lastName << ", " << newStudent -> studentID << ", " << newStudent -> studentGPA << endl;
  
  v.push_back(newStudent);
  
  // this saves it in the array list, sort of like a stack!
  
  
}


//this method will be used for printing the saved studnets
void printFunction(vector<Student*> v) {
  for (vector<Student*>:: iterator it = v.begin(); it != v.end(); it++) {
    // create an iterator, then we will print out the all the student information when the user wishes to
    cout << (*it) -> firstName << " " << (*it) -> lastName << ", " << (*it) -> studentID << ", " << (*it) -> studentGPA << endl;
  }


}


  
void deleteMethod(vector<Student*> &v) { // this method is used for deleting a student
  int deleteStudentID; // we will create a new variable, which will allow the user to say what they want to delete
  

  cout << "Enter a student ID you wish to delete: " << endl; //asks the user what they want to delete.
  cin >> deleteStudentID; // saves it in the deleteStudentID varaible
  //cin.ignore();
  
  for (auto it = v.begin(); it != v.end(); ++it) { // make a foor loop for the iterator from the the beginning all the way to the end
    if ((*it) -> studentID == deleteStudentID ) { // we will compare the studentID to the studentId that the user wants to delete. If the user enters a studentID saved in the vector, it will follow...

      delete *it; // deletes 
    v.erase(it);
    break;
	}
	/*   else {
      ++it;
         }
	*/
  }
  return; 
}

// returns
