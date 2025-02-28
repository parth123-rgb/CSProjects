#include <cstring>
#include <iostream>

using namespace std;

struct Node {

  char* data;
  Node* next;
  Node* front;
  Node* rear;


   newNode -> data = "C";
 
};

void PUSH(Node*& stackHead, Node* newNode);
Node* POP(Node* stackHead);
void PRINT(Node* stackHead);

int main() {

  Node* stackHead = NULL;
  Node* queueHead = NULL;
  //char input[50];

  Node* front = NULL;
  Node* rear = NULL;
  int queue;
  Node* newNode = new Node();
 
  PUSH(stackHead, newNode);
  POP(stackHead);
  PRINT(stackHead);
  

  return false;

}


void PUSH(Node*& stackHead, Node* newNode) { //x Node* current) {

  if (stackHead == NULL) {
    // if the head is  open, create a new node in the head.
    stackHead = newNode;
  }

  else {
  
  Node* temp = stackHead;
  // stackHead = current;
  while (temp->next != NULL) {
    temp = temp -> next;

  }

  temp -> next = newNode;
  
     }
}



Node* POP(Node* stackHead) {


  if (stackHead == NULL) {

    return NULL;



  }

  Node* temp = stackHead;
  if (temp->next != NULL) { // while the current's next is NOT open, set the current node  equal to the current's next

    stackHead = temp->next;
    cout << temp -> data;
   
    return temp;

  }
  else {
    // else if there is only one node in he stack, open it up!
    stackHead = NULL;
    return temp;

  }
  //->next = stackHead;



}


void PRINT(Node* stackHead) {

 Node* temp = stackHead;
 if (temp != NULL) { // while the list is not empty, print out the char data.


    cout << temp->data;

    
 PRINT(stackHead->next);


  }



}


void PEEK(Node* newNode) {

  Node* temp = newNode;

  cout << temp -> data << endl;






}





void ENQUEUE(Node* queueHead, Node* newNode) {

  if (queueHead == NULL) {
    
    queueHead = rear = newNode;
  }

  else {

    Node* temp = rear;


    while (rear->next != NULL) {



      rear = rear->next;
      //      temp = temp->next;

    }
    rear->next = newNode;

  }

}




void DEQUEUE(Node* queueHead, Node* newNode) {


  Node* temp = queueHead;

  queueHead->next = NULL;

  queueHead = queueHead->next;

  return temp;
  
  // if the front is open 
  if (front == NULL) {
    rear = NULL;

  }


}



