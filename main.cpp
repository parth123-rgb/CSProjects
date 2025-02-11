#include <cstring>
#include <iostream>
//#include <sstring>
#include <string>

using namespace std;


void ADD(int* heap, int number, int& size);
void heapify(int size, int* heap);
void PRINT(int position, int depth, int size, int* heap);
void DELETE(int* heap, int size, int index);

  
int main() {

  int heap[101];
  bool stillPlaying = true;
  int size = 1;
  
 for (int i = 0; i < 101; i++) {

    heap[i] = 0;


  }


  while (stillPlaying) {

  char input[30];
   
  cout << "Type 'ENTER' to enter numbers yourself" << endl;
  cout << "Type 'FILE' to enter numbers from a file" << endl;
  cout << "If you want to print the file, type 'PRINT'" << endl;
  cout << "IF you want to delete either the largest or all nodes type 'DELETE'" << endl;

  cin >> input;


  if (strcmp(input, "ENTER")==0) {

    int amountOfNumbers;

    cout << "Enter the AMOUNT of numbers you wish to add: " << endl;
    cin >> amountOfNumbers;

    for (int i = 0; i < amountOfNumbers; i++) { // this allows the node to be added EACH time, rather than all at once

      int number;

      cout << "Enter a number: " << endl;
      cin >> number;
      
      ADD(heap, number, size);

    }





  }
  else if (strcmp(input, "PRINT") == 0) {


    PRINT(1, 0, size, heap);


  }

  else if (strcmp(input, "DELETE")==0) {


    // add new variable asking if they want to add or delete all nodes too


    

    DELETE(heap, size, 0);



  }


  }
  




}




void ADD(int* heap, int number, int& size) {

  heap[size] = number; // set the spot in the heap equal to the number that the user entered.
  size++; // then increase the size (index) by 1!
  

  heapify(size-1, heap);


}




// this is essentially to ensure that all conditions are met, and that if the parnet node is not in the correct place, it fixes it!
 void heapify(int tempIndex, int* heap) {

   int parentNode = tempIndex/2;
   // will use this for index

   while (tempIndex > 1) {
   if (heap[parentNode] < heap[tempIndex]) {

     // while the value on the index of the parent node is less than the vlaue of the temorary index on the heap , than you must swap, the parent needs to be the higher value.



     
     // need to add sort method wehre it sawps them
     int temp = heap[tempIndex];
     
     heap[tempIndex] = heap[parentNode];
     heap[parentNode] = temp; // swap!
     
     heapify(parentNode, heap);
     // check recursively
   }
   
   
   else if(heap[parentNode] > heap[tempIndex]) {
     // the parnet node value is higher than the rst!
     // the value at this index is ideal, keep the function going
     return;



   }

   }
 }










void PRINT(int position, int depth, int size, int* heap) { // position is where currently am, depth is checking to see how far down the search tree to place something, size is the next open slot

  // if right node is less than size
  if (position*2+1 < size) {

    // printing out the right node
    PRINT(position*2+1, depth+1, size, heap);


  }

  for (int i = 0; i < depth; i++) {



    cout << "\t"; // tabbing for each depth (so it goes further in the tree when needed)


  }

  cout << heap[position] << endl;


  // if the less node is lower than the current node
  if (position*2 < size) { 


    PRINT(position*2, depth+1, size, heap); // print out the right node

  }
}





void DELETE(int* heap, int size, int index) {

  cout << heap[size-1];



  int largest = index;
  int left = 2 * index;
  int right = 2 * index + 1;


  if (left < size && heap[left] > heap[largest]) {


    heap[largest] = heap[left]; // set the first node (largest node) equal to the last node.
  size--;

    

  }

  else if (right < size && heap[right] > heap[largest]) {



  heap[1] = heap[right];
  size--;



  }
  










}
