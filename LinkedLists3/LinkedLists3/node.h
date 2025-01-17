#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"
using namespace std;

class Node {

public:
  Node();
  Node(Student* newStudent); // initlazes node with a given student pointer
  ~Node(); //destructor for Node
  
  Student* getStudent(); //getter for the student with the node
  
  int getValue(); //getter for the int value
  void setValue(int newValue); //setter for the int value in node
 
  void setNext(Node* newNext); //setter for next Node pointer
  Node* getNext(); //getter for next Node pointer
  void setStudent(Student* newStudent); //setter for student thats with the node
  
private:
  Student* student; //pointer to student thats with node
  int value; //int value stored in node
  Node* next; //pointers to the next node
  
};

#endif
