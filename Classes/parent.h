#include <cstring>

using namespace std;

class DigitalMedia {

 protected:
  char title[50];
  int year;

 public:
  parent();
  DigitalMedia(char* title, int year);
  void getTitle();
  int getYear();
};
