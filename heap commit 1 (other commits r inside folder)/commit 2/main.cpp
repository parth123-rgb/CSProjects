
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>



using namespace std;


void ADD(int* heap, int number, int& size);
void heapify(int size, int* heap);
void PRINT(int position, int depth, int size, int* heap);
bool DELETE(int heap[101], int& size);
//bool deleteALL (int* heap, int size);

int main() {

    int heap[101];
    bool stillPlaying = true;
    int size = 1;
    srand(0);

    for (int i = 0; i < 101; i++) {

        heap[i] = 0;


    }


    while (stillPlaying) {

        char input[30];
	int number;
	
	int amountOfNumbers; // chekc this carfully
	//int randomNumbers[100];
	     
        cout << "Type 'ENTER' to enter numbers yourself" << endl;
        cout << "Type 'FILE' to enter numbers from a file" << endl;
        cout << "If you want to print the file, type 'PRINT'" << endl;
        cout << "IF you want to delete either the largest or all nodes type 'DELETE'" << endl;

        cin >> input;


        if (strcmp(input, "ENTER") == 0) {

            cout << "Enter the AMOUNT of numbers you wish to add: " << endl;
            cin >> amountOfNumbers;

            for (int i = 0; i < amountOfNumbers; i++) { // this allows the node to be added EACH time, rather than all at once

          
                cout << "Enter a number: " << endl;
                cin >> number;
		// calling add function for each number that is added
                ADD(heap, number, size);

            }





        }

	else if (strcmp(input, "FILE") == 0) {
	  
	 
	  cout << "Enter the amount of numbers you wish to READ IN from the file: (up to 100) " << endl;
	  cin >> amountOfNumbers;

	  //	  cout << "Reading in: " << amountOfNumbers << endl;
	  ifstream fin("numbers.txt");

	  for (int i = 0; i < amountOfNumbers; i++) {
	  //  while (fin >> number && amount < amountOfNumbers) {
	    fin >> number; // read in a number each time the user asks
	    cout << "Read in: " << number << endl;
	    ADD(heap, number, size); // run add funcftion
	    

	  }

	  fin.close();
	

	}


	
        else if (strcmp(input, "PRINT") == 0) {

	  // running print funfcciton
            PRINT(1, 0, size, heap);


        }

        else if (strcmp(input, "DELETE") == 0) {


            // add new variable asking if they want to add or delete all nodes too

            char deleteNode[50];

            cout << "If you want to delete the head node type 'HEAD'" << endl;
	    cout << "If you want to delete all nodes 1 by 1, type 'ALL'" << endl;
	    
	    cin.ignore();
            cin.getline(deleteNode, 50, '\n');
            //cin.ignore();

            if (strcmp(deleteNode, "HEAD") == 0) {



                DELETE(heap, size);
            }
	    else if (strcmp(deleteNode, "ALL")==0) {

	      /*
	        while (DELETE(heap, size) == true) {


		
		deleteALL (heap, size);



		}
	      */

	      for (int i = 0; i < size; i++) { // iterate thjrough the entiure heap

		//		while (heap[i] != 0) { // while the heap is NOT empty.. 


		while (size != 0) {
		  DELETE(heap,size); // delete the head!
		  
		  PRINT(1, 0, size, heap); // print out each time to show deletion

		  // i
		}
		//if (heap[i] == 0) {
		if (heap[i] == 0) {
		    cout << "deleted all nodes!" << endl;
		    //}
		   
		          }

	    }


        }


    }


}


}




void ADD(int* heap, int number, int& size) {

  
    heap[size] = number; // set the spot in the heap equal to the number that the user entered.
    size++; // then increase the size (index) by 1!


    heapify(size - 1, heap);


}




// this is essentially to ensure that all conditions are met, and that if the parnet node is not in the correct place, it fixes it!
void heapify(int tempIndex, int* heap) {

    int parentNode = tempIndex / 2;
    // will use this for index

    while (tempIndex > 1) {
        if (heap[parentNode] < heap[tempIndex]) {

            // while the value on the index of the parent node is less than the vlaue of the temorary index on the heap , than you must swap, the parent needs to be the higher value.




            // need to add sort method wehre it sawps them
            int temp = heap[tempIndex];

            heap[tempIndex] = heap[parentNode];

            heap[parentNode] = temp; // swap!
            //tempIndex = parentNode;
          //  parentNode = tempIndex;

            heapify(parentNode, heap);
            // check recursively
        }


        else if (heap[parentNode] > heap[tempIndex]) {
            // the parnet node value is higher than the rst!
            // the value at this index is ideal, keep the function going
            return;



        }

    }
}










void PRINT(int position, int depth, int size, int* heap) { // position is where currently am, depth is checking to see how far down the search tree to place something, size is the next open slot

  // if right node is less than size
    if (position * 2 + 1 < size) {

        // printing out the right node
        PRINT(position * 2 + 1, depth + 1, size, heap);


    }

    for (int i = 0; i < depth; i++) {



        cout << "\t"; // tabbing for each depth (so it goes further in the tree when needed)


    }

    cout << heap[position] << endl;


    // if the less node is lower than the current node
    if (position * 2 < size) {


        PRINT(position * 2, depth + 1, size, heap); // print out the right node

    }
}









bool DELETE(int heap[101], int& size) {

    // cout << heap[size-1];

    //heap[1] = heap[size];
    //size--;
    int index = 1;


    cout << "Deleting the head: " << heap[1] << endl;


    heap[index] = heap[size - 1];
    size--;


    while (true) {

        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;



        if (left < size && heap[left] > heap[largest]) {



            largest = left;
	    
	    

            //      size--;
            /*
            if (heap[left] < heap[index]) {

                  left = index;
                           heapify(0, heap);



              }
              */


              /*



                  if (heap[right] > heap[left]) {


                      largest = right;
                       heapify(0, heap);


                  }
                  else {

                      largest = left;
                        heapify(0, heap);


                  }

                  */

                  //size--;

                 // heapify(0, heap);
                 // cout << heap[index];

                //  heapify(size-1, heap);


        }

        if (right < size && heap[right] > heap[largest]) {




            largest = right;
	    
	    
	}

	/*        if (heap[right] < heap[index]) {

            right = index;
            heapify(0, heap);






            /*
            if (heap[right] > heap[index]) {


                largest = right;
                heapify(0, heap);

            }
            else {

                largest = left;
                heapify(0, heap);


            }

            */

            //   size--;

               //int temporary = heap[right];
               //heap[right] = heap[1];
               //int 


               //heap[largest] = heap[left]; // set the first node (largest node) equal to the last node.
               //size--;
            //  largest = right; 
            // heap[largest] = heap[right]; // setting the root ot the nearest (higher valued chiold)
             //size--;

           //      heapify(0, heap);


            // heapify(size-1, heap);


	//      }



        //if (largest != index) {



        //}


        if (largest != index) {
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;

            index = largest;

        }
        else {


	  break;

	}

       

    }

    return true;

}


/*
bool deleteALL (int* heap, int size) {



  for (int i = 0; i < size; i++) {

    while (heap[i] != 0) {


      DELETE(heap, size);



    }



    //deleteALL(heap, size);




  }

  return true;


}
*/
