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

  
 
  
  while (active) {

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
    

    Student* newStudent = new Student(firstName, lastName, studentID, studentGPA);
    Node* newNode = new Node(newStudent);
    

    ADD(head, head, newNode);
  }
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


void ADD(Node* & head, Node* current, Node* node) {

  if (head == NULL) {

    head = node;
  }
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

void PRINT(Node* head) {


  if (head != NULL) {
    cout << "First name: " << head -> getStudent() -> first << endl;
    cout << "Last name: " << head -> getStudent() -> last << endl;
    cout << "Student ID: " << head -> getStudent() -> id << endl;
    cout << "Student GPA: " << head -> getStudent() -> gpa << endl;


  PRINT(head->getNext());


  }

 


}


void DELETE(Node*& head, int &studentID, Node* previous) {

  if (head==NULL) {

    cout << "There is no student!" << endl;
    return;
  }
 
  
  if (studentID == head -> getStudent() -> id) {
    Node* temp = head;
    head = previous->getNext();
    delete temp;

    cout << "Deleted Student!" << endl;
    return;
   
  }
  else if (previous -> getNext() -> getStudent() -> id == studentID) {

    Node* temp = previous->getNext();
    previous->setNext(previous->getNext()->getNext());
    delete temp;
   
    cout << "Deleted student! " << endl;

    
   }
  
  else {
    DELETE(head, studentID, previous->getNext());

  }
}


void AVERAGE (Node* current, Node* previous, float total, float count) {



  if (current == NULL) {

    if (count == 0) {

      cout << "THERE ARE NO GPAS TO AVERAGE!" << endl;

      
    }
    else {

      
      
      float average = total/count;

      cout << fixed << setprecision(2) << "Average GPA: " << average << endl;

    }
    return;
  }
    
    else {
      float gpa = current->getStudent()->getStudentGPA();

      AVERAGE(current->getNext(), previous->getNext(), total+gpa, count+1); 
      }



 

}
