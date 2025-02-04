#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


using namespace std;



struct Node {


  Node* head;
  Node* next;

  char* firstName;
  char* lastName;
  int studentID;
  float studentGPA;
  
  




};

  
void ADD(Node* newNode, Node** hashtable, int size); 

void rehash(Node**& hashtable, int &size); 

void PRINT(Node* newNode); 




int main() {





  ifstream fin("student.txt"); // reading in file
  
 
    char* line;
    char** firstNames = new char*[20];

    
    char** lastNames = new char*[20];


    int var1;
    int var2;

    
    for (int i = 0; i < 49; i++) {

      firstNames[i] = new char[20];
      fin >> firstNames[i];
      //cout << firstNames;

      lastNames[i] = new char[20];
      fin >> lastNames[i];
      //  cout << lastNames;

    }

    
    
    fin.close();



  
  int size = 100;
  
  Node** hashtable = new Node*[size];

  

  
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


    Node* newNode = new Node();

    cout << "Enter the number of students you wish to ADD" << endl;

    cin >> numberOfStudents;


    for (int i = 0; i < numberOfStudents; i++) {


      srand(time(0));

      random=rand()%50;

      if (numberOfStudents == random) {
      cout << "First name:" << firstNames[i] << " Last name: " << lastNames[i] << endl;
      
      }
    }





    
    
    //  for (



    
    
    //    newNode -> firstName = "bob"; 
    strcpy(newNode-> firstName, firstNames[0]);

    strcpy(newNode-> lastName, lastNames[0]);

    newNode->studentGPA = 4.00;

    newNode->studentID = 24;

    


    
    
    ADD(newNode, hashtable, size); 

    

  }
  else if (strcmp(input, "PRINT")==0) {


    

    

  }

  else if (strcmp(input, "DELETE")==0) {

    



    
  }

  else if (strcmp(input, "QUIT") ==0) {



    exit(0);


  }
	      
	    

  
  return 0;


  


}


void ADD(Node* newNode, Node** hashtable, int size) {


  int ID = newNode -> studentID;

  int index = ID%size;

  if (hashtable[index] == NULL) {

    //cout << " IASIGNED IT" <<endl;
    hashtable[index] = newNode;
    



  }

  else if (hashtable[index]->next == NULL) {

    hashtable[index] -> next = newNode;



  }

  else if (hashtable[index]->next->next == NULL) {

    hashtable[index] -> next -> next = newNode;



  }

  else {
    
    cout << "WE REACHED HERE" << endl;
    rehash(hashtable, size);


  }
  

  





}


void rehash(Node**& hashtable, int& size) {
  int newSize = size * 2;  // getting the new size of the new hash table

  
    Node** newHashTable = new Node * [newSize]();
    // creating new hsah table
    for (int i = 0; i < newSize; i++) {

      newHashTable[i]=NULL; // setting all slots in the NEW hash table to NULL and empty.


    }
    // going over old hash table, and setting the CURRNET node to it. this is for going to the next node 3 times.
    for (int i = 0; i < size; ++i) {
        Node* current = hashtable[i];

        while (current != NULL) {
	  // get the index for the currnet node.
	  int newIndex = current->studentID % newSize;


	  Node* nextNode = current->next; 

            // Insert the current node into the new hash table
            if (newHashTable[newIndex] == NULL) {

	      newHashTable[newIndex] = current;  // First node at this index

	      current->next = NULL;
            }
            else {

	      Node* temp = newHashTable[newIndex];

	      while (temp->next != NULL) {

		temp = temp->next;  // Find the end of the list at this index

	      }

	      temp->next = current;  // Add the current node at the end

	      current->next = NULL;

	    }

            current = nextNode;  // Move to the next node in the old list
        }
    }

    // Delete the old hash table and replace it with the new one
    delete[] hashtable;
    hashtable = newHashTable;
    size = newSize;  // Update the size of the table

    cout << "Rehashing complete. New table size: " << size << endl;
}






void PRINT(Node* newNode) {



  







}
