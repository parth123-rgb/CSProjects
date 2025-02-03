#include <cstring>
#include <iostream>

using namespace std;



struct Node {


  Node* head;
  Node* next;

  char firstName[50];
  char lastName [50];
  int studentID;
  float studentGPA;
  
  




};

  
void ADD(Node* newNode, Node** hashtable, int size); 

void rehash(Node* newNode, Node** hashtable, int size); 






int main() {


  int size = 100;
  
  Node** hashtable = new Node*[size];

  

  
  char input[50];
  int id = 8;

  cout << "If you want to add a student, type 'ADD'" << endl;
  cout << "If you want to print a student, type 'PRINT'" << endl;
  cout << "If you want to delete a studet, type 'DELETE" << endl;
  cout << "If you want to quit the system type 'QUIT'" << endl;

  cin>>input;

  if (strcmp(input, "ADD")==0) {


    Node* newNode = new Node();


    
    //    newNode -> firstName = "bob"; 
    strcpy(newNode-> firstName, "bob");

    strcpy(newNode-> lastName, "gupta");

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
    rehash(newNode, hashtable, size);


  }
  

  





}


void rehash(Node* newNode, Node** hashtable, int size) 


{


  //int ID = newNode -> studentID;

  int newSize = size;
  // ceating new size varirable
  

  int newIndex = newNode -> studentID%newSize; // taking index
  // new index variable

  size = size*2;
  // multiplying size variable

  Node** newHashTable = new Node*[size]();
  // creatig new hash table
  

  
  for (int i = 0; i < newSize; i++) {
    newHashTable[i] = NULL;

  } // checkcing the NULL 



  //Node* temp = HashTable[i];

  
  for (int i = 0; i < size; ++i) {


    Node* current = hashtable[i];

    while (current != NULL) {

      //  int newIndex = current->next;


      if (newHashTable[newIndex] == NULL) {



	newHashTable[newIndex] = current;


      }
      else {

	Node* temp = newHashTable[newIndex];

	while (temp->next != NULL) {


	  temp = temp->next;


	}


	temp->next = current;


      }
      


      
      current->next = NULL;
      current = newNode->next;

      




    }





  }

 if (newHashTable[newIndex] == NULL) {



    newHashTable[newIndex] = newNode;




  }

  else if (newHashTable[newIndex]->next == NULL) {



    newHashTable[newIndex] -> next = newNode;




  }

  
  else if (newHashTable[newIndex]->next->next == NULL) {

    cout << "VAMOS" << endl;
    newHashTable[newIndex] -> next -> next = newNode;



  }


 delete[] hashtable; // deleting original hashtable
 hashtable = newHashTable; // setting old hash table to the new one

 size = newSize;

 cout << "New table created" << endl;



}





void PRINT(Node* newNode) {



  







}
