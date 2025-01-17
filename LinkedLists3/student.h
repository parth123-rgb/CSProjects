#include <cstring>
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;


class Student {


 public:
  Student(char* firstName, char* lastName, int studentID, float studentGPA);
  char* first;
  char* last;
  int id;
  float gpa;

  char* getFirst();
  char* getLast();
  int getStudentID();
  float getStudentGPA();
  //char* printFunction();
  ~Student();
  
};



#endif

















  
