#include <cstring>
#include <vector>
#include "node.h"
#include "student.h"
#include <iomanip>


using namespace std;


void ADD(Node* & head, Node* current, Node* node);
void PRINT(Node* head);
void DELETE(Node*& head, int& studentID, Node* previous);
void AVERAGE (Node* current, Node* previous, float total, float count);
// function prototypees


int main() {


  Node* head = NULL;
  Node* current;
  

  
  char userInput[50];
  bool active = true;

  
 
  // while the function is still going..  
  while (active) {


    // user can choose to add, print, quit the program, delete a student, or average gpas.
    cout << "Type 'ADD' if you wish to add a student" << endl;
  cout << "Type 'PRINT' if you wish to print out all student information" << endl;
  cout << "TYPE 'DELETE', then enter the student ID of the student you wish to delete" << endl;
  cout << "TYPE 'QUIT' if you wish to quit the system" << endl;
  cout << "TYPE 'AVERAGE' if you wish to average of all students, shown to two decimals points" << endl;


  cin >> userInput;
  //  cout << userInput << " gg g " << endl;
  if (strcmp(userInput, "ADD") == 0) {

    char* firstName = new char[50];
    char* lastName = new char[50];
    int studentID;
    float studentGPA;

    cout << "Enter the student's first name" << endl;
    cin >> firstName;

    cout << "Enter the student's last name" << endl;
    cin >> lastName;

    cout << "Enter the student's ID" << endl;
    cin >> studentID;

    cout << "Enter the student's GPA" << endl;
    cin >> studentGPA;
    
    // read in to the appropriate variables.
    Student* newStudent = new Student(firstName, lastName, studentID, studentGPA); // creating new student and node
    Node* newNode = new Node(newStudent);
    

    ADD(head, head, newNode);
  } // calling function
  else if (strcmp(userInput, "PRINT") == 0) {

    //    cout << "GET IN HERE" << endl;

    //cout << newStudent -> printFunction();
    PRINT(head);

    //    active = true;
  }
  else if (strcmp(userInput, "DELETE") == 0) {

    
    int studentID;
  
    cout << "Please enter ID of the student you wish to delete" << endl;
    cin >> studentID;

    DELETE(head, studentID, head);

  }
  else if(strcmp(userInput, "AVERAGE") == 0) {


    AVERAGE (head, head, 0, 0);

  }
  else if (strcmp(userInput, "QUIT") == 0) {



    cout << "Thanks for playing!! " << endl;
    exit(0);

  }
  }

   return 0;

  
}
// add function

void ADD(Node* & head, Node* current, Node* node) {


  // if the head IS NULL.
  if (head == NULL) {

    head = node;
  }
  // sorting out from leastto greatest
  else if (head -> getStudent()->getStudentID() > node -> getStudent()->getStudentID()) {
    // this else if is for sorting the IDS out in correct order. We must recursively go through this to compare each studentID.
    node->setNext(head);
    head = node;

  }
  else if (current -> getNext() == NULL) {

    current -> setNext(node);
    
   
  }
  else if (current->getNext()->getStudent() -> getStudentID() > node->getStudent()->getStudentID()) {

    node -> setNext(current->getNext());
    current -> setNext(node);

    
  }
  else {
    ADD(head, current->getNext(), node); 

  }
  
}



// print fucntion
void PRINT(Node* head) {


  if (head != NULL) {
    cout << "First name: " << head -> getStudent() -> first << endl;
    cout << "Last name: " << head -> getStudent() -> last << endl;
    cout << "Student ID: " << head -> getStudent() -> id << endl;
    cout << "Student GPA: " << head -> getStudent() -> gpa << endl;

    // getting all data from other classes
  PRINT(head->getNext());


  }

 


}



// delete function

void DELETE(Node*& head, int &studentID, Node* previous) {

  if (head==NULL) {
    // check if there is a student
    cout << "There is no student!" << endl;
    return;
  }
 
  
  if (studentID == head -> getStudent() -> id) {
    Node* temp = head;
    head = previous->getNext();
    delete temp;
    // create temp variable, set it to head, then set heaed to the CURRENT node, then delete temp.

    cout << "Deleted Student!" << endl;
    return;
    // basically deleting a full node
  }
  else if (previous -> getNext() -> getStudent() -> id == studentID) {
    // deleting the NEXT node.
    Node* temp = previous->getNext();
    previous->setNext(previous->getNext()->getNext());
    delete temp;
   
    cout << "Deleted student! " << endl;

    
   }
  
  else {
    DELETE(head, studentID, previous->getNext());
    // recursion
  }
}

// average function to find the average gpa


void AVERAGE (Node* current, Node* previous, float total, float count) {



  if (current == NULL) {

    if (count == 0) {

      cout << "THERE ARE NO GPAS TO AVERAGE!" << endl;

      
    }
    else {

      // find the average
      
      float average = total/count;

      cout << fixed << setprecision(2) << "Average GPA: " << average << endl;

    }
    return;
  }
    
    else {
      float gpa = current->getStudent()->getStudentGPA();
      // recursion!
      AVERAGE(current->getNext(), previous->getNext(), total+gpa, count+1); 
      }



 

}
