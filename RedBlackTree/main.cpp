
#include <iostream>
#include <cstring>
#include <fstream>


using namespace std;


struct Node {

  int data;
  Node* left;
  Node* right;
  Node* parent;
  char color;
  Node* next;




};




Node* INSERTION(Node* currentNode, int input, Node*& inserted);
//bool SEARCH(Node* currentNode);
bool searchFunction(Node * currentNode);

Node* SUCCESSOR(Node* currentNode);
void leftRotation(Node*& root, Node*& x);
void rightRotation(Node*& root, Node*&current);
//void insertionFIX(Node* currentNode) {

Node* rootNode(Node* currentNode);
Node* DELETION(Node* currentNode, int deleteNumber);
void PRINT(Node* currentNode, int depth); // position is where currently am, depth is checking to see how far down the search tree to place something, size is the next open slot

void insertionFIX(Node*& currentNode, Node *& root);


int main() {
  
    char chooseInput[50];
    int numberOfInput;
    int input;
   // int rootNode;
    bool stillGoing = true;
    int deleteNumber;
    char rootOrNumber[50];
    int fileAmount;
    //char fileInput[50];




    Node* right = NULL;
    Node* parent = NULL;
    Node* root = NULL;
    Node* left = NULL;
    Node* currentNode = NULL; // SET THE NULL SO WE DONT SEE 0
    Node* leftRotation = NULL;

    
    while (stillGoing) {
        
    cout << "If you wish to add numbers manually, type  'ADD'" <<endl;
    cout << "If you wish to add numbers from a file, type  'FILE'"<<endl;
    cout << "If you wish to SEARCH for a node, type 'SEARCH'" << endl;
    cout << "If you wish to PRINT, type 'PRINT'" << endl;
    cout << "If you wish to delete a node, type 'DELETE'" << endl;
    cout << "If you wish to QUIT the system, type 'QUIT'" << endl;

cin >> chooseInput;
  
  
  if (strcmp(chooseInput, "ADD")==0) {
    //cout << "Enter the amount of numbers you wish to insert: " << endl;
    //cin >> numberOfInput;
    
    
    
   // for (int i = 1; i <= numberOfInput; i++) {
        cout << "Enter which number you wish to add to the tree: " << endl;
        
                cin >> input;
		
        Node* inserted = NULL;
        root = INSERTION(root, input, inserted); 
        insertionFIX(inserted, root);          
        PRINT(root, 0);
    // inserting here.
     //   }
        //}
}
  
  else if (strcmp(chooseInput, "FILE")==0) {
  
        int randomNumber;
        cout << "Enter the amount of numbers to read in from file: " << endl;
        cin >> fileAmount;
        ifstream fin("numbers.txt");


        for (int i = 0; i <= fileAmount; i++) {
        
        fin >> input;
    //    for (int i = 0; i <= fileAmount; i++) {
  
      //  for (int i = 0; i < randomNumber; i++) {            
//                      input = randomNumber;
    

           /// fin;
           // input = randomNumber;

           //   }
              
        // input = randomNumber;
            cout << "Read in: " << input << endl;
        
      
      //  currentNode = INSERTION(currentNode, input, root);
    // for (int i = 0; i > fileAmount; i++) {
     Node* inserted = NULL;
        root = INSERTION(root, input, inserted);
      insertionFIX(inserted, root);
   //  }
            
        }
        fin.close();
  }
    
      else if (strcmp(chooseInput, "SEARCH")==0) {
          
      if (searchFunction(root)) {
          cout << "This number is in the tree!" << endl;
      } 
      else {
	      cout << "this number is NOT in the tree!" << endl;
          
      }
      }
      

    else if (strcmp(chooseInput, "PRINT")==0) {
        
        PRINT(root, 0);
    }/*
    else if (strcmp(chooseInput, "DELETE")==0) {
    
 //   cout << "If you want to delete the ROOT, type 'ROOT
    cout << "Enter what number you want to delete: " << endl;
    cin >> deleteNumber;
    
    currentNode = DELETION(currentNode, deleteNumber);
    
   // setting currnet node to the return value!
    }
    
*/    
 
	else if (strcmp(chooseInput, "QUIT")==0) {
	exit(0);
	}
    
    
    
      }
    
    return 0;
}



Node* INSERTION(Node* currentNode, int input, Node*& inserted) {
    

if (currentNode == NULL) {
    inserted = new Node();
    inserted->data = input;
    inserted->color = 'r';
    return inserted;
}

if (input < currentNode->data) {
    Node* leftNode = INSERTION(currentNode->left, input, inserted);
    currentNode->left = leftNode;
    leftNode->parent = currentNode; // normal binarysearch treei nsertion. we call insertion fix at the TOP in main, so we can ensure all red black tree properties are met.
} 



else {
    Node* rightChild = INSERTION(currentNode->right, input, inserted);
    currentNode->right = rightChild;
    rightChild->parent = currentNode;

    
}
//insertionFIX(inserted);

return currentNode;
/*
    
    

    if (root -> data < input) {/
        // we recursivley go down the right and left
        // setting  the right subtree recursively with the INPUT value that the user gave us
        
     //   if (currentNode->right != NULL) {
            root->right = INSERTION(root->right, input);
            ///currentNode -> right = INSERTION(currentNode -> right, input);
            root->right->parent = root;
            //rightChild->parent = currentNode;
            //currentNode->right->parent = currentNode;
     // }
           // currentNode->right->parent = currentNode;
                  //  insertionFIX(currentNode);
       // return currentNode;
       // insertionFIX(currentNode);


    }
    
    // using the value the user entered, we sort it out using the BST algorithim, recursively adding based on the user's input.
    else if (currentNode -> data > input) {
      //  if (currentNode->left != NULL) {
       root->right = INSERTION(root->right, input);
            ///currentNode -> right = INSERTION(currentNode -> right, input);
            root->right->parent = root;
            //rightChild->parent = currentNode;
            //currentNode->right->parent = currentNode;
     
          
     }
  
    return currentNode;*/

}






  Node* rootNode(Node* currentNode) {



   
    if (currentNode != NULL) { 


      while (currentNode->parent != NULL) {
      // while there is a parnet node, keep traversing

      currentNode = currentNode->parent;

    }

      if (currentNode != NULL) {      
      currentNode->color = 'b';
        //continue;
    //  return currentNode;
          
      }

    }
    return currentNode; // when it reaches the end ofthe node, it will be the root node!
    


  }






void leftRotation(Node*& root, Node*& x) {
    Node* y = x->right; // we are doing this for organization and modularity
    x ->right = y->left;
    
    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;
    
    if (x->parent == NULL) {
    
        root = y; // UPDAITNG TREE ROOT
    
        
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    } 
    
    else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}


void rightRotation(Node*& root, Node*& y) {
// rotations are essential for keepign balanced red black trees, and allowing insertionFIX to wokr correcrtlytcorrectly.   
    Node* x = y->left;
    y->left = x->right;
  
    if (x->right != NULL) {
  
        x->right->parent = y;
  
    }

    x->parent = y->parent;
    if (y->parent == NULL) {
    // if y's parent is opened, which it likely will be
        root = x;  // UPDATING TREE ROOT
    
        
    } 
    else if (y == y->parent->left) {
        // otherwise if it is the y parents left child (if y is the right left child)
        y->parent->left = x;
    }
    else {
        y->parent->right = x; // if y is the right chbild.
    }

    x->right = y;
    y->parent = x;
}













/*
void rightRotation(Node*& currentNode) {
    Node* y = currentNode->left;
    Node* root = rootNode(currentNode);  // Get the root node for reference

    currentNode->left = y->right;
    if (y->left != NULL) {
        y->left->parent = currentNode;
    }
    y->parent = currentNode->parent;
    if (currentNode->parent == NULL) {
        currentNode = y;  // If currentNode was the root, update it
    } else if (currentNode == currentNode->parent->left) {
        currentNode->parent->left = y;
    } else {
        currentNode->parent->right = y;
    }
    y->left = currentNode;
    currentNode->parent = y;
}



void rightRotation(Node*& currentNode) {
  // essentially opposite of left rotation function

  // move y's right chld to currentnode's left.
  
  Node* y = currentNode->left; // setting y to be the LEFt child
  Node* root = rootNode(currentNode);
  
  currentNode->left = y->right;

  if (y->right != NULL) { // if y has a right child

    y->parent->left = currentNode;



  }
  // moving y up

  y->parent = currentNode->parent;

  if (currentNode == root) {

    root = y;

  }

  else if (currentNode == currentNode->parent->right) {

    currentNode->parent->right = y;

  }

  else if (currentNode == currentNode->parent->left) {


    currentNode->parent->left = y;

  }


  // mamkign current node the right child of y

  y->left = currentNode;
  currentNode->parent=y;




}
*/






void insertionFIX(Node*& current, Node*& root) {
    // get the root so we can recolor it black at the end

    // as long as we're not at root and parent is red, we have a violation
    while (current != root && current->parent->color == 'r') {
        Node* parent = current->parent;
        Node* grandparent = current->parent->parent;
        Node* uncle = NULL;
        // figure out which side parent is on, and set uncle accordingly
       if (parent == grandparent->left) {
        
        uncle = grandparent->right; // if the parent is the left child of the grandparent, then the uncle is the OTHER side (grandparents right child)
        
           
       } 
        
        else {
        uncle = grandparent->left; // checking if uncle is left, based on what it is, we will set that equal to the uncle node.
        }       
        // if the uncle is red, we must RECOLOR the parent and grandparent and uncle to designsted colors.
        if (uncle != NULL && uncle->color == 'r') {
            cout << " case 1 " << endl;
            parent->color= 'b';
            uncle->color= 'b';
            grandparent->color = 'r';
            current = grandparent;
        }
        else {
            // this is if the current node is in the "inner oaprt". we shoudl change this so the next case can work
            if (parent == grandparent->left && current == parent->right) {
                // preform left rotation on parent
                cout << "case 2" << endl;
                current = parent;
                cout << "left rotation" << endl;
                leftRotation(root, parent); // rotating root and parent
                parent = current->parent; // traversing.
                cout << parent->data << endl;
                grandparent = parent->parent;
                cout << grandparent->data << endl; // debugginmg gfor now , will delete
                cout << root->data << endl;
            }
            else if (parent == grandparent->right && current == parent->left) {
                // preform right rotation on parent
                 //= parent;
                cout << "right rotation" << endl;
                rightRotation(root, parent);
                parent = current->parent;
                grandparent = parent->parent;
            }
            
            // now current node is on outter side. must preform rotatiosn and recolor parent and grandparent.
            cout << "case 3" << endl;
            parent->color= 'b'; // updating parents color
            grandparent->color = 'r'; // updating grnadparents color
            if (parent == grandparent->left) { // updating grnadparents left.
                cout << "right rotation" << endl;
                 rightRotation(root, grandparent); // preforming right rotation.
            } else {
                
                cout << "left rotation" << endl;
                leftRotation(root, grandparent); // preforming left rotation.
            }
            cout << root->data << endl;
        }
        
        root = rootNode(current); // we must change the root if the rotatiosn are moving it
    }
// root should always be black regardless of situation    
    root->color = 'b';
}







   
void PRINT(Node* currentNode, int depth) { 
    if (currentNode == NULL) {
        return;   // make sure the currentNode is not open
    }

if (currentNode -> right != NULL) {
    PRINT(currentNode->right, depth + 1); // if its not open, then recursivley print the right side of the tree
}

    for (int i = 0; i < depth; i++) { // add tabs for each depth!
        cout << "\t";  
    }
    cout << currentNode->data << "(" << currentNode->color << ")" << endl; // print out data when going through the right side
if (currentNode->left !=NULL) {
    PRINT(currentNode->left, depth + 1);// do same wuth left side
}
    
}


bool searchFunction(Node* currentNode) {
    
    int searchNumber;
    
    cout << "Enter which number you would like to search: " << endl;
    cin >> searchNumber;
    
    while (currentNode != NULL) {
        
        if (searchNumber == currentNode->data) { // if the inputted number is equal to the currentnode's data
            return true; // return here otherwise will be infite loop
        }
        else if (searchNumber > currentNode->data) {
            currentNode = currentNode->right;
            // traverse throughout the tree, this works with the while loop, because it will keep running
        }
        else if (searchNumber < currentNode->data) {
            currentNode = currentNode->left; // trabverse through the left side of the tree
            // we know to go left or right, because of the properties of binary trees 
        }

    }
// if it reaches the end, past everything, it means that there is NO matching number!
    return false;
}
