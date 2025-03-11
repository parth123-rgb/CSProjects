#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Node {
    
    int data;
    Node* right;
    Node* left;
    
  //we are adding a acomment here for the sake of committing changes
  
    
    
    
};

Node* INSERTION(Node* currentNode, int input);
bool SEARCH(Node* currentNode);
Node* SUCCESSOR(Node* currentNode);

Node* DELETION(Node* currentNode, int deleteNumber);
void PRINT(Node* currentNode, int depth); // position is where currently am, depth is checking to see how far down the search tree to place something, size is the next open slot



int main() {
    char chooseInput[50];
    int numberOfInput;
    int input;
    int rootNode;
    bool stillGoing = true;
    int deleteNumber;
    char rootOrNumber[50];
    int fileAmount;
    int parth = 0;
   // Node* right = new Node();
//    Node* left = new Node();
    Node* right = NULL;
    Node* left = NULL;
    Node* currentNode = NULL; // SET THE NULL SO WE DONT SEE 0
    
    while (stillGoing) {
        
    cout << "If you wish to add numbers manually, type  'ADD'" <<endl;
    cout << "If you wish to add numbers from a file, type  'FILE'"<<endl;
    cout << "If you wish to SEARCH for a node, type 'SEARCH'" << endl;
    cout << "If you wish to PRINT, type 'PRINT'" << endl;
    cout << "If you wish to delete a node, type 'DELETE'" << endl;

cin >> chooseInput;
  
  
  if (strcmp(chooseInput, "ADD")==0) { 
    cout << "Enter the amount of numbers you wish to read in: " << endl;
    cin >> numberOfInput;
    
    
    
    for (int i = 0; i <= numberOfInput; i++) {
        
        cout << "Enter which number you wish to add to tree: " << endl;
        cin >> input;
        INSERTION(currentNode, input);

        if (input > 999 || input < 0) {
        cout << "Your number is too high or low! "<< endl;
        cout << "Enter a number between 1 and 999: " << endl;
        cin >> input;
        currentNode = INSERTION(currentNode, input); // setting  current node to the return value
        }
    }
  }
  else if (strcmp(chooseInput, "FILE")==0) {
        
        cout << "Enter the amount of numbers to read in from file: " << endl;
        cin >> fileAmount;
        
        ifstream fin("numbers.txt");
        
        for (int i = 0; i <= fileAmount; i++) {
            
        fin >> input;
        cout << "Read in: " << input << endl;
        currentNode = INSERTION(currentNode, input);
        
        
            
        }
        fin.close();
    }
    else if (strcmp(chooseInput, "SEARCH")==0) {
        
        SEARCH(currentNode);
        
    }
    else if (strcmp(chooseInput, "PRINT")==0) {
        
        PRINT(currentNode, 0);
    }
    else if (strcmp(chooseInput, "DELETE")==0) {
    
 //   cout << "If you want to delete the ROOT, type 'ROOT
    cout << "Enter what number you want to delete: " << endl;
    cin >> deleteNumber;
    
    currentNode = DELETION(currentNode, deleteNumber);
    
   // setting currnet node to the return value!
    }
    
    
 }
    
    
    
    
    
    return 0;
}



Node* INSERTION(Node* currentNode, int input) {
    
    if (currentNode == NULL) { // empty spot, new node should be added
        Node* temp = new Node();
        
        temp->data = input;
        temp->right = NULL; // set as null, because newly inserted leafs start as a leaf (ahving no children yet)
        temp -> left = NULL;
        return temp;
        
        
        
        return currentNode;
        
    }
    
    

    if (currentNode -> data < input) {
        // we recursivley go down the right and left
        // setting  the right subtree recursively with the INPUT value that the user gave us
        currentNode -> right = INSERTION(currentNode -> right, input);
        
    }
    
    // using the value the user entered, we sort it out using the BST algorithim, recursively adding based on the user's input.
    else if (currentNode -> data > input) {
        currentNode -> left = INSERTION(currentNode -> left, input);
    }
   
    
    return currentNode;
    /*
    while (currentNode -> right != NULL) {
    cout << "Right nodes:" << currentNode -> data;
    }
    
    while (currentNode -> left != NULL) {
        
        cout << "Left Nodes: " << currentNode -> data;
    }
    
  //  INSERTION(currentNode, input);
    */
}



bool SEARCH(Node* currentNode) {
    int searchInput;
    
    cout << "Enter the number you wish to search: " << endl;
    cin >> searchInput;
    
    
    while (currentNode != NULL) {
        
    
    if (searchInput == currentNode -> data) {
        cout << "There is: " << searchInput << " in the tree!" << endl;
    return true; // when it is found, should return back to avoid  infinite loop
    }
    
    else if (searchInput < currentNode -> data) { // comparing the input to the data values, if its less than 
    // then we must move it, so the system can keep iterating throhg it
        
        currentNode = currentNode -> left; // move to this to the left, so the systme searches left
    }
    else if (searchInput > currentNode -> data) {
        currentNode = currentNode->right; // same thing with right!
        
    
    
    } 
   // else if (searchInput != currentNode->data){
        
       // cout << "This node is nOT in the tree" << endl;
       // }
        
       // SEARCH(currentNode);
    }
            cout << "This node is nOT in the tree" << endl;
            return false;
            // when it reaches the end of the function, if it does, than it means the node is NOT in the tree.

   // return currentNode;
}


Node* SUCCESSOR(Node* currentNode) {
    
    currentNode = currentNode->right;
    while (currentNode != NULL &&  currentNode -> left != NULL) {
    currentNode = currentNode -> left;

    }
    
    return currentNode;

}




Node* DELETION(Node* currentNode, int deleteNumber) {
    
    if (currentNode == NULL) {
        return NULL;
    }
    
    // we need to find which node to delete
    
    if (deleteNumber > currentNode -> data) {
        currentNode -> right = DELETION(currentNode ->right, deleteNumber); // this is for finding the correct number to delete!
    }
    // checking  both right and left
    //comparing the user's input to the data in the current node
    // we must check both sides
    else if (deleteNumber < currentNode -> data) {
        currentNode -> left = DELETION(currentNode -> left, deleteNumber); 
        // recursively finding the node on the left
    }
    else {
    //if (deleteNumber == currentNode->data) {
        if (currentNode -> left == NULL && currentNode -> right == NULL) {
        //Node* temp = currentNode;
        delete currentNode;
        return NULL;
        // if there is no child, then delete current node completely!
        
        }
        else if (currentNode -> left == NULL) {
            // if there is a right child...
            Node* temp = currentNode->right;
            delete currentNode; // delete currentNode
            return temp;
            // returning new root , we will use in main
        }
        else if (currentNode -> right == NULL) { 
        // if there is only a LEFT cchild
        Node* temp = currentNode->left;
        delete currentNode;
        return temp; // returning new root
        }
        
        else if (currentNode -> right != NULL && currentNode -> left != NULL) {
            // if there are no empty childs (if there are two childs...)
            
            Node* successorNode = SUCCESSOR(currentNode);
            currentNode->data = successorNode->data;
            // replace current node data with successor node data
        currentNode->right = DELETION(currentNode->right, successorNode->data);


        }
       // return currentNode;
//cout << "Deleted: " << currentNode;
            // if there are two childs
}
return currentNode;
}


/*
void PRINT(Node* currentNode) {
    
    if (currentNode != NULL) {
    cout << currentNode ->data << " "; // seperate it so it prints in order

        if (currentNode -> left != NULL) { // if there are data values on the left side of the tree (if it isn't empty)
            PRINT(currentNode->left);

        }
        if (currentNode -> right != NULL) {
            //cout << currentNode -> data;
            PRINT(currentNode->right); 
        }
    }
    */
   
   
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
    cout << currentNode->data << endl; // print out data when going through the right side
if (currentNode->left !=NULL) {
    PRINT(currentNode->left, depth + 1);// do same wuth left side
}
    
}
