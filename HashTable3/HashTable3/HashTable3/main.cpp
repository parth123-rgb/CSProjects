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

void rehash(Node**& hashtable, int &size, Student* newStudent); 

void PRINT(Node* newNode, Node**& hashtable, int size);




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

    cout << "Enter the number of students you wish to ADD" << endl;
    
    cin >> numberOfStudents;


    for (int i = 0; i < numberOfStudents; i++) {

      
      
    char* firstName = new char[20];

    char* lastName = new char[20];

    int studentGPA= rand();

    int studentID = round(rand());
				       

     
      random=rand()%50;

      
      Student* newStudent = new Student(firstNames[random], lastNames[random], studentID, studentGPA);
      
      //      cout << "First name:" << firstNames[random]<<"Last names:" << lastNames[random] <<endl;

      cout << "Added " << numberOfStudents << " students!" << endl;

    
    ADD(newNode, hashtable, size, newStudent); 
    }
    

  }
  else if (strcmp(input, "PRINT")==0) {

    
    

    PRINT(newNode, hashtable, size);

  }

  else if (strcmp(input, "DELETE")==0) {

    



    
  }

  else if (strcmp(input, "QUIT") ==0) {



    exit(0);


  }
	      
	    
  }
  
  return 0;


  
 

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

    // If current is NULL, directly assign node to the hashtable slot
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

    // Create a new hash table
    Node** newHashTable = new Node*[newSize]();
    
    // Loop over the old hashtable and rehash each node
    for (int i = 0; i < size; ++i) {
        Node* current = hashtable[i];
        while (current != NULL) {
            int newIndex = current->student->studentID % newSize;

            Node* nextNode = current->next;  // Save next node before breaking the link

            // Insert the current node into the new hash table
            if (newHashTable[newIndex] == NULL) {
                newHashTable[newIndex] = current;  // First node at this index
                current->next = NULL;  // Ensure next is NULL
            } else {
                Node* temp = newHashTable[newIndex];
                while (temp->next != NULL) {
                    temp = temp->next;  // Find the last node
                }
                temp->next = current;  // Add current node to the end
                current->next = NULL;  // Ensure next is NULL
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
    cout << "Student GPA" << newStudent -> studentGPA << endl;



    current = current->next;
    // we get next from the node we are pointing to, and we go to the next student!
      }
  }

  }





}
