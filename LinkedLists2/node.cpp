#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;


Node::Node(Student* newStudent) {
  // constructor


  // creaitng new student
  Student* student = new Student();
  next = NULL; // setting next to null


}

Node::~Node(){

  // deconstructor


  // deleting the studennt
  delete student;


}



Node* Node::getNext() {

  return next;
  // reutrn the next variable when going to the next node.

}


Student* Node::getStudent() {


  return student;


}


void Node::setNext(Node* nextNode) {

  next = nextNode;

}
