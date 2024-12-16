#include <iostream>
#include <cstring>
#include "student.h"
#ifndef NODE_H
#define NODE_H




using namespace std;


class Node {

 public:
  Node(Student*);
  ~Node();
  Student* student;
  Node* next;
  Node* getNext();
  Student* getStudent();

  void setNext(Node* nextNode);
  // definiung all variables.
  




  //private:








};

#endif
