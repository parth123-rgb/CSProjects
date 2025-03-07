#include <cstring>
#include <iostream>

using namespace std;

struct Node {

  char* data;
  Node* next;
  Node* front;
  Node* rear;


  //   newNode -> data;
 
};



void PUSH(Node*& stackHead, Node* newNode);
Node* POP(Node* stackHead);
void PRINT(Node* stackHead);
void ENQUEUE(Node* queueHead, Node* newNode);
int PRECEDENCE(char op);
void SHUNTINGYARD(Node*& queueHead, char prefixFunction[], Node* stackHead);


int main() {

  Node* stackHead = NULL;
  Node* queueHead = NULL;
  //char input[50];

  Node* front = NULL;
  Node* rear = NULL;
  int queue;
  Node* newNode = new Node();
 
  //PUSH(stackHead, newNode);
  //POP(stackHead);
  //PRINT(stackHead);

  char prefixFunction[50];

  cout << "Enter a function" << endl;
  cin >> prefixFunction;

  //cout << "Precedence of + is: " << precedence(input);



  

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

    stackHead = temp->next; // edit ORIGINAL stackhead, and set it equal to the stackheads next.
    //cout << temp -> data;
   
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

  cout << *temp -> data << endl;

  




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




void DEQUEUE(Node*& queueHead, Node* newNode) {


  Node* temp = queueHead;

  cout << queueHead;
  queueHead = queueHead->next;
  cout << queueHead;
  temp->next = NULL;

  return temp;
  
  // if the front is open 
  /* if (front == NULL) {
    rear = NULL;

  }
  */

}


int PRECEDENCE(char op) { // PEMDAS



  if (op == "-" || op == "+") {

    return 1; // least precedence, lowest on pemdas
   
  }
  else if (op == "*" || op == "/") {

    return 2; // more precedence, but less than power
    
  }
  else if (op == "^") {

    return 3; // highest precednece
  }
  else {
    return 0; // we return 0 if the operator is not valid.

  }





}




void SHUNTINGYARD(Node*& queueHead, char prefixFunction[], Node* stackHead) {

 
  cout << "Your PREFIXED function is" << prefixFunction << endl;
  int functionLength = strlen(prefixFunction);

  for (int i = 0; i < functionLength; i++) {
    // so we can get an index value!
  
  

    if (prefixFunction[i] != '+' && prefixFunction[i] != "-" && prefixFunction[i] != "(" && prefixFunction[i] != ")" && prefixFunction[i] !=  "/" && prefixFunction[i] != "^" && prefixFunction[i] != "*") {
    Node* newNode = new Node (prefixFunction[i]);
    
    ENQUEUE(queueHead, newNode);

  }

  if (prefixFunction[i] == "+" || prefixFunction[i] == "-" || prefixFunction[i] ==  "/" || prefixFunction[i] ==  "^" || prefixFunction[i] == "*" || prefixFunction[i] == "-" || prefixFunction[i] ==  "/" || prefixFunction[i] =="^" || prefixFunction[i] == "*") {// if there is an operator... 
    while (stackHead != NULL && PRECEDENCE(stackHead -> data) > PRECEDENCE(prefixFunction[i])) {
	// checknig if the stack head has something, compare the PRECEDENCE (order of operations)

	Node* popNode = POP(stackHead); // we can save it becasue this returns a NODE!!! pop operator onto the queue
	ENQUEUE(queueHead, popNode);



      }
      Node* newNode = new Node (prefixFunction[i]); // getting the operator sfrom the function the user read in
      PUSH(stackHead, newNode);


      }

    if (prefixFunction[i] == "(") {
      
      Node* newNode = new Node(prefixFunction[i]); // to store paranthesis on stack to manage operators.
      
	PUSH(stackHead, newNode); // if paranthesis, push NODE ONTO THE OPERATOR STACK!

	
    }
    else if (prefixFunction[i] == ")") {

      while (stackHead != "(") {


	
	Node* temp = POP(stackHead); // save the paranthesis
	ENQUEUE(queueHead, temp);


      }


      Node* tempNode = POP(stackHead);
      delete tempNode;
    }

  }
}
