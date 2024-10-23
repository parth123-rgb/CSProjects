#include <iostream>
#include <cstring>
#include <vector>




using namespace std;


struct Student {

  char firstName[50];
  char lastName[50];
  int studentID;
  float studentGPA;
 

};


void addFunction(vector<Student*> & v);
void printFunction(vector<Student*> v);
void deleteMethod(vector<Student*> &v);
// function prototypes 



int main() {
  vector<Student*> v;
  char addAndPrintPlayer[7];
  bool addPlayer = true;
  //int deleteStudentID;
  char quitSys[5];
  // v = new vector<Student*>();
 


  while (addPlayer) {
  cout << "If you want to add a student, type 'ADD'" << endl;
    cout << "If you want to print the saved players, type 'PRINT' " << endl; 
    cout << " If you want to delete a player, type 'DELETE' " << endl;
    cout << " If you want to quit, type 'QUIT': " << endl;
	    
  cin >> addAndPrintPlayer;
  //cin >> addAndPrintPlayer;


  if (strcmp(addAndPrintPlayer, "ADD") == 0) {
    addFunction(v);
  
  }
  
  else if (strcmp(addAndPrintPlayer, "PRINT") == 0) {
    printFunction(v);
    /*
    cout << "Do you want to quit? (Yes / No) " << endl;
    cin >> quitSys;

    if (strcmp(quitSys, "Yes") == 0) {
      exit(0);


      }
    */
      }
  //else if
  else if (strcmp(addAndPrintPlayer, "DELETE") == 0) {

    
    deleteMethod(v);

    //addPlayer = true;
    }
  else if (strcmp(addAndPrintPlayer, "QUIT") == 0) {
    cout << "Your students will miss you..." << endl;
    addPlayer = false;
    }
  }
}




void addFunction(vector<Student*> & v) {
  Student* newStudent = new Student();
  char firstName[50];
  char lastName[50];
  

  cout << "Enter your first name: " << endl;
  cin >> newStudent -> firstName;
  cout << "Enter your last name: " << endl;
  // cin.ignore();
  cin >> newStudent -> lastName;
  // strcpy(newStudent -> lastName, lastName);
  //  cin.ignore();
  cout << "Enter your student ID: " << endl;
  cin >> newStudent -> studentID;
  //int deleteStudentID = newStudent -> studentID;
  cout << "Enter your GPA: " << endl;
  cin >>  newStudent -> studentGPA;



  // cout << newStudent -> firstName << ", " << newStudent -> lastName << ", " << newStudent -> studentID << ", " << newStudent -> studentGPA << endl;
  
  v.push_back(newStudent);
  

  
  
}

void printFunction(vector<Student*> v) {
  for (vector<Student*>:: iterator it = v.begin(); it != v.end(); it++) {

    cout << (*it) -> firstName << ", " << (*it) -> lastName << ", " << (*it) -> studentID << ", " << (*it) -> studentGPA << endl;
  }


}


  
void deleteMethod(vector<Student*> &v) {
  int deleteStudentID;

  cout << "Enter a student ID you wish to delete: " << endl;
  cin >> deleteStudentID;
  //cin.ignore();
  
  for (auto it = v.begin(); it != v.end(); ++it) {
	if ((*it) -> studentID == deleteStudentID ) {

    delete *it;
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

