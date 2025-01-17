#include <cstring>
#include <iostream>
#include "student.h"


using namespace std;



Student::Student(char* firstName, char* lastName, int studentID, float studentGPA) {




  first = new char[30];
  last = new char[30];
  strcpy(first, firstName);
  strcpy(last, lastName);
  //strcpy(id, studentID);
  //strcpy(gpa, studentGPA);
  id = studentID;
  gpa = studentGPA;

}


char* Student::getFirst() {

  return first;
}

char* Student::getLast() {

  return last;
}

int Student::getStudentID() {

  return id;


}

float Student::getStudentGPA(){


  return gpa;


}


Student::~Student() {


  delete first;
  delete last;
  



}







/*

char* printFunction() {


  cout << "First name: " << first << endl;
  cout << "Last name: " << last << endl;
  cout << "Student ID" << id << endl;
  cout << "Student GPA: " << gpa << endl;





}
*/
