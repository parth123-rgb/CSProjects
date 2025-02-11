#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <bits/stdc++.h>



using namespace std;


struct Student {

  //id = studentID;
  //gpa = studentGPA;


  char* firstName;
  char* lastName;
  int studentID;
  float studentGPA;


  Student(char* first, char* last, int id, float gpa) {



    firstName = new char[20];
    lastName = new char[20];

    
      strcpy(firstName, first);

      strcpy(lastName, last);


      studentID = id;

      studentGPA = gpa;


  }

};



struct Node {


  Node* head;
  Node* next;
  Student* student;
  

  Node() {
    student=NULL;
    head = NULL;
    next = NULL;
    

 


  }

};
  
void ADD(Node* newNode, Node** hashtable, int size, Student* newStudent); 

bool uniqueID(Node* newNode, Node**& hashtable, int studentID, int size);

void rehash(Node**& hashtable, int &size, Student* newStudent); 

void PRINT(Node* newNode, Node**& hashtable, int size);

void DELETE(Node* newNode, Node**& hashtable, int size);


int main() {


  
  // vector<Student*>
  bool stillPlaying = true;
  
  srand(time(0));




  ifstream fin("student.txt"); // reading in file
  
 
    char* line;
    char** firstNames = new char*[50];

    
    char** lastNames = new char*[50];


    int var1;
    int var2;

    
    for (int i = 0; i < 50; i++) {

      firstNames[i] = new char[20];
      fin >> firstNames[i];
      //cout << firstNames;
      
      lastNames[i] = new char[20];


      fin >> lastNames[i];
      //  cout << lastNames;
      
    }

    
    
    fin.close();



  
  int size = 100;
  
  Node** hashtable = new Node*[size]();

  //Student* newStudent = new Student(firstNames, lastNames);
  
  Node* newNode = new Node();


  while (stillPlaying) {
 
  char input[50];
  int id = 8;
  int numberOfStudents;
  int random;
 


    cout << "If you want to add a student, type 'ADD'" << endl;
  cout << "If you want to print a student, type 'PRINT'" << endl;
  cout << "If you want to delete a studet, type 'DELETE" << endl;
  cout << "If you want to quit the system type 'QUIT'" << endl;

  cin>>input;
   if (strcmp(input, "ADD")==0) {
      
      char manualStudent[50];
      
      cout << "Do you want to add the student's manually (yes/no)?" << endl;
      cin >> manualStudent;
      
if (strcmp(manualStudent, "yes") == 0) {  // Fix comparison


  // create new variables if the user wants to enter the info manually
  char* firstName = new char[20];

  char* lastName = new char[20];

  float studentGPA;

  int studentID;


  // read them in te from the user
    cout << "Enter the first name:" << endl;
    cin >> firstName;
    
    cout << "Enter the last name: " << endl;
    cin >> lastName;
    
    cout << "Enter the student GPA:" << endl;
    cin >> studentGPA;
    
    cout << "Enter the student ID: " << endl;
    cin >> studentID;


    // create nwe student
    Student* newStudent = new Student(firstName, lastName, studentID, studentGPA);
    
    ADD(newNode, hashtable, size, newStudent);
    // call add function
}

    else if (strcmp(manualStudent, "no")==0) {


      int numberOfStudents;
    cout << "Enter the number of students you wish to ADD" << endl;
    
    cin >> numberOfStudents;


    for (int i = 0; i < numberOfStudents; i++) {

      
      
    char* firstName = new char[20];

    char* lastName = new char[20];

    float preGPA= rand()%300+100;

    float studentGPA = preGPA/100;
    
    int studentID = round(rand()%100000);


    
    while (uniqueID(newNode, hashtable, studentID, size) == true) {


     studentID = round(rand()%100000); 

    
     
    }

    // getting random names from the file    
      random=rand()%50;

    Student* newStudent = new Student(firstNames[random], lastNames[random], studentID, studentGPA);
      
      //      cout << "First name:" << firstNames[random]<<"Last names:" << lastNames[random] <<endl;

      cout << "Added " << numberOfStudents << " students!" << endl;

    
    ADD(newNode, hashtable, size, newStudent); 
    
   }
  }
}




  else if (strcmp(input, "PRINT") == 0) {

    
    

    PRINT(newNode, hashtable, size);

  }

  else if (strcmp(input, "DELETE") == 0) {

    
    //void DELETE(Node* newNode, Node**& hashtable, int studentID, int size)
    DELETE(newNode, hashtable, size);


    
  }

  else if (strcmp(input, "QUIT") == 0) {



    exit(0);


  }
	      
	    
  }
  
  return 0;


  
 

}

bool uniqueID(Node* newNode, Node**& hashtable, int studentID, int size) {


  // going through entire hash table
  for (int i = 0; i < size; i++) {
        Node* current = hashtable[i]; // get the first node at this index



	
        while (current != NULL) {
            if (studentID == current->student->studentID) {

	      cout << "Assigned the same ID, changing the ID" << endl;
	      return true; // Duplicate ID found


	    }
            current = current->next; // Move to the next node in the linked list
   }
   }

    // If no match was found after checking all nodes, return false (ID is unique)
    return false;
}




void ADD(Node* newNode, Node** hashtable, int size, Student* newStudent) {

  // newNode -> firstName

  int ID = newStudent -> studentID;

  
  int index = ID%size;


  Node* node = new Node();
  node->student = newStudent;

  // creating a new node that saves all student data and pulls a new data set each time the user gets a new student.


  
  if (hashtable[index] == NULL) {

    //cout << " IASIGNED IT" <<endl;
    hashtable[index] = node;
 


  }
  /*
  else if (hashtable[index]->next == NULL) {

    hashtable[index] -> next = node;



  }

  else if (hashtable[index]->next->next == NULL) {

    hashtable[index] -> next -> next = node;



  }
  */


 
else {
    Node* current = hashtable[index]; // getting the hash table in the node
    int collisions = 0;

    while (current != NULL) { // if the hash table isn't empty
        collisions++;

        if (collisions > 3) {
            cout << "WE REACHED HERE" << endl;
            current = hashtable[index];
            hashtable[index] = NULL;
            rehash(hashtable, size, newStudent);
            return;
        }
    else {
    Node* current = hashtable[index]; // getting the hash table in the node
    int collisions = 0;

    while (current != NULL) { // if the hash table isn't empty
        collisions++;

        if (collisions > 3) {
            cout << "WE REACHED HERE" << endl;
            current = hashtable[index];
            hashtable[index] = NULL;
            rehash(hashtable, size, newStudent);
            return;
        }

        if (current->next == NULL) {
            // This part is problematic if `current` is NULL
            current->next = node;
            return;
        }

        current = current->next;
    }

    // assign node to hash table slot
    if (current == NULL) {
        hashtable[index] = node;
        return;
    }
    }





  
                  }
         }

}



void rehash(Node**& hashtable, int& size, Student* newStudent) {
    int newSize = size * 2;  // getting the new size of the new hash table
    cout << "Rehashing to new size: " << newSize << endl;


    // creating the new hash table
    Node** newHashTable = new Node*[newSize]();


    
    for (int i = 0; i < size; ++i) {
      Node* current = hashtable[i]; // setting the hash table into the ucrrent node.

      while (current != NULL) { // while the current node does NOT have open data
	int newIndex = current->student->studentID % newSize; 

	Node* nextNode = current->next; // we save the nextNode




	// we are trasnfering ofver the data here
	if (newHashTable[newIndex] == NULL) {
	  newHashTable[newIndex] = current;  // setting first node to current
                current->next = NULL;  // Ensure next is NULL
            } else {
                Node* temp = newHashTable[newIndex];
                while (temp->next != NULL) {
                    temp = temp->next;  // Find the last node
                }
                temp->next = current;  // Add current node to the end
                current->next = NULL;  // Ensure next is NULL
		return;
	    }

	    
             current = nextNode;  // Move to the next node in the old list
        }
    }

    delete[] hashtable;
    hashtable = newHashTable;
    size = newSize;  // Update the size of the table
}







void PRINT(Node* newNode, Node**& hashtable, int size) {

  for (int i = 0; i < size; i++) {
    Node* current = hashtable[i]; // put the hash table into this node


    
    if (current != NULL) { // if the hash table is not empty


      while (current != NULL) { // while its not empty
	Student* newStudent = current->student;

	cout << "First name:" << newStudent -> firstName << endl; // go through the hash table and print out all saved data
	cout << "Last name:" << newStudent -> lastName << endl;
    cout << "Student ID:" << newStudent -> studentID << endl;
    cout << "Student GPA: " << newStudent -> studentGPA << endl;



    current = current->next;
    // we get next from the node we are pointing to, and we go to the next student!
      }
  }

  }






}



// DELETE FUCNTION

void DELETE(Node* newNode, Node**& hashtable, int size) {

  int input;


    cout << "Please enter the ID you wish to delete" << endl;

  cin >> input;

  //Node* deleteNode = NULL;
  

  
for (int i = 0; i < size; i++) {

  
  Node* previous = NULL;
  
  Node* current = hashtable[i]; // setting the hash table into the current node

  while (current!=NULL) {
      
    if (current->student->studentID == input){

      if (previous==NULL) { // here we are going to st the hash table equal to the current's next node.

      /*      
      Node* temp = current;
    current = current->next;
    //previous->next= current;
    delete temp;
      */
      hashtable[i]=current->next; // point to the next node
      // this way we save the hash table into the currents NEXT node, because we WILL be deleting current.

      //previous = current;
      //current = current->next; // move to the next node
  
  }

    else{

      previous->next = current -> next; // otherwise we set the previous next to the currentn ext


      // or set the previous's next node to the current node.
      

    
    }

      cout << "Deelted student!" << endl;

      
      delete current; // deleting the current node
  
    return;
     
}

    previous = current;
  current = current->next; // move to the next node
  
  
  


  }

  }
 }
