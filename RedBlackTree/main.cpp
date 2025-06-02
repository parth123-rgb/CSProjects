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
// function prototypes!!!!!

Node* INSERTION(Node* currentNode, int input, Node*& inserted);
Node* searchFunction(Node* currentNode);
Node* SUCCESSOR(Node* node);


void leftRotation(Node*& root, Node*& x);
void rightRotation(Node*& root, Node*& current);


Node* rootNode(Node* currentNode);
void PRINT(Node* currentNode, int depth);
void insertionFIX(Node*& currentNode, Node*& root);
Node* SEARCH(Node* currentNode, int searchNum);


void deletionCHECK(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
void DELETION(Node*& root, Node* current_search_start_node, int deleteNumber);

// prototypes for cases
void caseTwo(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
bool caseThree(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
void caseFour(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
void caseFive(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
void caseSix(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent);
Node* assignValues(Node*& current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent); // Parameter 'Sibling' changed to 'sibling', 'parent' to 'parent'

int main() {
    char chooseInput[50];
    int input;
    bool stillGoing = true;
    int fileAmount;

    Node* root = NULL;
    Node* tempCurrentNode = NULL; // literallyl just for callingfunctions

    while (stillGoing) {
        cout << "If you wish to add numbers yourself, type 'ADD'" << endl;
        cout << "If you wish to add numbers from a file, type 'FILE'" << endl;
        cout << "If you wish to SEARCH for a node, type 'SEARCH'" << endl;
        cout << "If you wish to PRINT, type 'PRINT'" << endl;
        cout << "If you wish to delete a node, type 'DELETE'" << endl;
        cout << "If you wish to quit the system, type 'QUIT'" << endl;

        cin >> chooseInput;

        if (strcmp(chooseInput, "ADD") == 0) {
            cout << "Enter which number you wish to add to the tree: " << endl;
            cin >> input;
           
           
            Node* inserted = NULL;
            root = INSERTION(root, input, inserted);
            if (inserted != NULL) {
                insertionFIX(inserted, root);
            }
           
            PRINT(root, 0);
        } 
        
        else if (strcmp(chooseInput, "FILE") == 0) {
            cout << "Enter the amount of numbers to read in from file: " << endl;
            cin >> fileAmount;
          // reading input from file

            ifstream fin("numbers.txt");
            

            for (int i = 0; i < fileAmount; i++) {
                fin >> input;
                // reading each time the user had asked for
                cout << "Read in: " << input << endl;
                
                Node* inserted = NULL;
                root = INSERTION(root, input, inserted);
               
                if (inserted != NULL) {
                    insertionFIX(inserted, root);
                    // calling insertionFIX as long as inserted node exists
                }
            }
            fin.close();
            PRINT(root, 0); // Print after all file insertions
        } 
        else if (strcmp(chooseInput, "SEARCH") == 0) {
            tempCurrentNode = searchFunction(root); // Result can be used if needed
        } 
        
        else if (strcmp(chooseInput, "PRINT") == 0) {
            PRINT(root, 0);
        } 
        
        else if (strcmp(chooseInput, "DELETE") == 0) {
            int deleteNumber;
            cout << "Enter the number you wish to delete: " << endl;
            cin >> deleteNumber;
           
            DELETION(root, root, deleteNumber);
            PRINT(root, 0);
        } 
        
        else if (strcmp(chooseInput, "QUIT") == 0) {
            stillGoing = false;
        } 
    }
    }
// insertion function, following noraml BST algorithim
Node* INSERTION(Node* currentNode, int input, Node*& inserted) {
    

if (currentNode == NULL) {
    inserted = new Node();
    inserted->data = input;
    inserted->color = 'r';
    return inserted;
}

if (input < currentNode->data) {
    Node* leftChild = INSERTION(currentNode->left, input, inserted);
    currentNode->left = leftChild;
    leftChild->parent = currentNode;
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






  Node* rootNode(Node* currentNode) { // Thsi will get usr oot node for isneritonFIx
    
    if (currentNode == NULL) {
        return NULL; //  DNE
    }
    else {


   
    if (currentNode != NULL) { 


      while (currentNode->parent != NULL) {
      // while there is a parnet node, keep traversing

      currentNode = currentNode->parent;

    }
    }
  
     
    return currentNode; // when it reaches the end ofthe node, it will be the root node!
    

}
  }

// rotations (left and right ) are crucial for insertion/deletion fix, as we wil need to 
// rotate accordingly

void leftRotation(Node*& root, Node*& x) {
    
    if (x == NULL || x->right == NULL) {
        
        return; // Does not exiszt
    }
    
    
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
    
    if (y == NULL || y->left == NULL) {
        return;
    }
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




void insertionFIX(Node*& currentNode, Node*& root) {
    // get the root so we can recolor it black at the end

    // as long as we're not at root and parent is red, we have a violation
    while (currentNode != root && currentNode->parent->color == 'r') {
        Node* parent = currentNode->parent;
        Node* grandparent = currentNode->parent->parent;
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
            currentNode = grandparent;
        }
        else {
            // this is if the current node is in the "inner oaprt". we shoudl change this so the next case can work
            if (parent == grandparent->left && currentNode == parent->right) {
                // preform left rotation on parent
                cout << "case 2" << endl;
                currentNode = parent;
                cout << "left rotation" << endl;
                leftRotation(root, parent); // rotating root and parent
                parent = currentNode->parent; // traversing.
                cout << parent->data << endl;
                grandparent = parent->parent;
                cout << grandparent->data << endl; // debugginmg gfor now , will delete
                cout << root->data << endl;
            }
            else if (parent == grandparent->right && currentNode == parent->left) {
                // preform right rotation on parent
                 currentNode = parent;
                cout << "right rotation" << endl;
                rightRotation(root, parent);
                parent = currentNode->parent;
                grandparent = parent->parent;
            }
            
            // now current node is on outter side. must preform rotatiosn and recolor parent and grandparent.
            cout << "case 3" << endl;
            parent->color= 'b'; // updating parents color
            grandparent->color = 'r'; // updating grnadparents color
            if (parent == grandparent->left) { // updating grnadparents left.
                cout << "right rotation" << endl;
                 rightRotation(root, grandparent); // preforming right rotation.
            }  else {
                cout << "left rotation" << endl;
                leftRotation(root, grandparent); // preforming left rotation.
            }
            cout << root->data << endl;
        }
        
        root = rootNode(currentNode); // we must change the root if the rotatiosn are moving it
        cout << "currentNodeS VALUE AFTER INSERTIONFIX" << currentNode->data << endl;
    }
// root should always be black regardless of situation    
    root->color = 'b';
}



void PRINT(Node* currentNode, int depth) { // copied from BST code
    if (currentNode == NULL) {
        return;
    }
    if (currentNode->right != NULL) {
        PRINT(currentNode->right, depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        cout << "\t";
    }
    cout << currentNode->data << "(" << currentNode->color << ")";

    cout << endl;
    if (currentNode->left != NULL) {
        PRINT(currentNode->left, depth + 1);
    }
}



Node* searchFunction(Node* root) {
    int searchNumber;
    if (root == NULL) {
        return NULL;
    }
    cout << "Enter which number you would like to search: " << endl;
    cin >> searchNumber;
     

    Node* searchNode = SEARCH(root, searchNumber);
    // to get the node value which was returned from the next function

    if (searchNode == NULL) {
        
        cout << searchNumber << " is NOT in the RBT!!!" << endl;
        
    } // if the searchNode ends up being NULL (bc we reutrn null), then it is not in the RBNT
    
    else if (searchNode != NULL) {
    
    cout << searchNumber << "IS in the red black tree" << endl;

    } // if there IS A value found, then it will have been returned, adn it is in the RBT
    
    return searchNode;
}



Node* SEARCH(Node* currentNode, int searchNum) {
    Node* current = currentNode;
    
    while (current != NULL) {
        if (searchNum == current->data) { // then node is FOUND
            return current;
      
        } 
        
        else if (searchNum > current->data) { 
            
            // if the number the user entered is MORE THAN the fisrt node, we must traverse right (following BST property)
            current = current->right;
        } 
        
        else if (searchNum < current->data) { 
        // following BSt property, traverse left if nodei s not found
            current = current->left;
        }
    }
    return NULL; // if it reaches end, no noe bhas been found
}




Node* SUCCESSOR(Node* node) { 
    // finding successor, will be useful in deletion
    
    if (node == NULL || node->right == NULL) {
        
        return NULL;
    }
    
    Node* current = node->right;
    while (current->left != NULL) {
      
        current = current->left;
    }
    return current;
}




void DELETION(Node*& root, Node* search_start_node, int deleteNumber) {
    Node* searchNode = SEARCH(search_start_node, deleteNumber);

    if (searchNode == NULL) {
        return; // no node isf ound
    }

    Node* y;
    Node* x;
    char originalColor;


// these lines of code are from simon frazier univeresities RBT 
    if (searchNode->left == NULL || searchNode->right == NULL) {
        y = searchNode;
    } // adjusts y accoridngly based on what type of deletion (one, zeor, two)
    else {
        y = SUCCESSOR(searchNode);
    }

    originalColor = y->color; // we gawther this, becaue wewill call deletionFIx with it

    if (y->left != NULL) { // need to check if y->left exists...
       // if()
        x = y->left;
    }
    
    else {
        x = y->right;
    }

    Node* xParent = y->parent; 
    // eventually, the parent of y wil be x's parent (following roatations, etc.)
 
 
 
 //  else { // if current node is the right child
       // temp->left->parent = temp->parent->left;
        //temp->parent->right = temp->parent;
  
    if (x != NULL) { // x is the child of y, and will take y's spot in the RBT
        x->parent = y->parent;
    }

 if (y->parent == NULL) { 
        root = x;
    } 
    
    else if (y == y->parent->left) {
    y->parent->left = x;
    } 
    
    else {
        
        y->parent->right = x;
    }

    if (y != searchNode) { // searchNode holds 
    // if y is the SUCCESESOR, we must copy y's data into searchNodes data.
        searchNode->data = y->data;
    }


    Node* toDelete = y; // we will end up deleting htis,m ev entually

    if (originalColor == 'b') { 
        // start fixing ONLY if the original color 
    // was black
        if (x != NULL) {
            Node* xSibling = NULL;
        Node* xInsideNephew = NULL;
        Node* xOutsideNephew = NULL;
        // we create these variables so we can call the reassign varibale function here.
            // otherwise it would  be out of scope ( trust me, i found out the hard way)
   assignValues(x, xSibling, xInsideNephew, xOutsideNephew, x->parent);
            deletionCHECK(root, x, xSibling, xInsideNephew, xOutsideNephew, x->parent);
        } 
        
        else if (xParent != NULL) { 
           Node* temp = new Node();
            temp->parent = xParent;
            temp->color = 'b';
            //  temp->left->right = temp->parent;
     //   temp

            temp->left = NULL;
            temp->right = NULL;
            temp->next = NULL;

            
            if (xParent->left == x) { // x is the NULL left child
                xParent->left = temp;
            } 
            
            else if (xParent->right == x) {// x is the NULL right child
                xParent->right = temp;
            }

            Node* tempSibling = NULL;
            // Node* 
            Node* tempInsideNephew = NULL;
            
            Node* tempOutsideNephew = NULL;

            assignValues(temp, tempSibling, tempInsideNephew, tempOutsideNephew, xParent);
            // we create these variables, becuase we are going to reassing them in our
            // reassign function, then we can use them! #modularity
          
            deletionCHECK(root, temp, tempSibling, tempInsideNephew, tempOutsideNephew, xParent);

           if (temp->parent != NULL) {
             //  if (temp->parent->left == temp) { // if current node is the left child
       //     temp->parent->left = temp->left;
       
                if (temp == temp->parent->left) {
                    // temp->parent->right = NULL
                    temp->parent->left = NULL; // null child
                } 
                
                else {
                    temp->parent->right = NULL; //NULL child
                }
           }
            
            
            else if (root == temp) { // Should not happen if xParent was not NULL
                root = NULL;
            }
            
            delete temp;
        }
    
    }
    
    delete toDelete;

    if (root != NULL) { // always set root back to black (rbt propeyt)
        root->color = 'b';
    }
}







// I FOLLOWEWD WIKIPEDIDA FOR ALL CASES

void caseTwo(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
    if (sibling != NULL) {
        sibling->color = 'r';
    }
}






bool caseThree(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
   // if (root == NULL && sibling == NULL && )
    if (sibling == NULL || parent == NULL) { // if either of these are null
    // function should not continue
        return false;
    }
    sibling->color = 'b';
    parent->color = 'r';

    if (current == parent->left) {
       // if (current != parent->right)
        cout << "Left rotation case 3 " << endl;
        leftRotation(root, parent);
    } 
    else { 
        cout << "reaching right rotatiom for case 3" << endl;
        rightRotation(root, parent);
    }
    cout << "Reached the  END of case three" << endl;
    // ROTATION MEAN REaSSIGNMENT!
    assignValues(current, sibling, insideNephew, outsideNephew, parent);
    return false;
}



void caseFour(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
    
    if (sibling != NULL) { // need to make sure sibling eixst before recolor
        sibling->color = 'r';
    }
    if (parent != NULL) { // making sure parent exists, before recoloring
        parent->color = 'b';
    }
    
}

void caseFive(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
    
    
        if (parent == NULL || sibling == NULL || insideNephew == NULL) { 
        // all 3 of the variablse above are needed.
        // therefore , if the function does not have them, need to restrat
         return;
    }
    
    
    insideNephew->color = 'b';
    sibling->color = 'r';

    if (current == parent->left && sibling == parent->right) { 
        // if current is left child, while the sibling is the right child,. should rotate
        rightRotation(root, sibling);
    } 
else if (sibling == parent->left && current == parent->right) { // current is R, sibling is L, insideNephew is sibling->right
        // OR , if the SIBLING is LEFT and the CURRENT is RIGHT child.
        leftRotation(root, sibling);
    }


    // we need to reASSIGN values AFTER ROTATION
    assignValues(current, sibling, insideNephew, outsideNephew, parent); // This updates sibling and nephews
   caseSix(root, current, sibling, insideNephew, outsideNephew, parent);
}




void caseSix(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
    
    
    if (parent == NULL) {
        cout << "PARENT ODES NOT EXIST" << endl;
        return; 
        // this is if a parent diesnt exist
}


    if (sibling != NULL) {
        sibling->color = parent->color;
    }
    parent->color = 'b';

    if (outsideNephew != NULL) {
        outsideNephew->color = 'b';
    }


    // DECIDING IF LEFT ROTATION OR RIGHT ROTATION.
    if (current == parent->left) {
//        cout << "rotating: " root->data << "and " << parent->data << endl;
        leftRotation(root, parent);
    } 
    else if (current == parent->right) {
        rightRotation(root, parent);
    }
    
}


// this function is for reassigning values following rotation

Node* assignValues(Node*& current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
    if (current == NULL) {
        // IF CURRENT DOES NOT EXIST WE SET EVERTYHIGN TO NULL AND RETURN
        
        sibling = NULL;
        insideNephew = NULL;
        outsideNephew = NULL;
        
        return current;
    }

    parent = current->parent;

    if (parent == NULL) { // current is root
        sibling = NULL;
        insideNephew = NULL;
        outsideNephew = NULL;
        return current;
    }

    if (current == parent->left) {
        
        sibling = parent->right;
        
        if (sibling != NULL) {
//outsideNephew= sibling->l
    insideNephew = sibling->left;
            outsideNephew = sibling->right;
        } 
        
        else {
            insideNephew = NULL;
            outsideNephew = NULL;
    }
    }
    
    else if (current == parent->right) { 
        sibling = parent->left;
        if (sibling != NULL) {
            insideNephew = sibling->right;
            outsideNephew = sibling->left;
        } 
        
        else {
            insideNephew = NULL;
            outsideNephew = NULL;
        }
}
    return current;
}



void deletionCHECK(Node*& root, Node* current, Node*& sibling, Node*& insideNephew, Node*& outsideNephew, Node*& parent) {
  
  
    while (current != root && (current == NULL || current->color == 'b')) {
        
        cout << "we get here "  << endl;
        
        if (current == NULL && parent == NULL && current != root) {
            return;
            
        }


        Node* tempParent;
        
        if (current !=  NULL) {
            tempParent = current->parent;
        }
        else if (current == NULL) {
            tempParent = parent;
        }

        if (tempParent == NULL && current != root) {
             return;
        }
        
        
        parent = tempParent; 
// if (root!= NULL) {
        if (current != NULL) {
            assignValues(current, sibling, insideNephew, outsideNephew, parent);
        } 
        
        else { 
            if (parent == NULL) {
                return;  // if parent can not be found DNE
            
            }
            bool nullLeftChild = true; 

            if (parent->left == current) {
                /* if (parent->right = true) {
                    nullLeftChild = true;
                }*/
                nullLeftChild  = true;
        }
            else  if (parent->right == current) {
                nullLeftChild = false; 
            }
            
            // setting the siblign as the right child or left child
            // accordingly!
               
              if (parent->left == NULL && parent->right != NULL) { 
                //sibling->right = parent;
                 sibling = parent->right;
            } 
            
            else if (parent->right == NULL && parent->left != NULL) { 
        cout << "setting sibling to parents left cihld " << endl;
                 sibling = parent->left;
            } 
            
            else if (parent->left == NULL && parent->right == NULL) { 
                 sibling = NULL; 
            } 
            
            else { 
                if (parent->left == current) {
                    sibling = parent->right; 
                    // sibling is right
                }
                else if (parent->right == current) {
                sibling = parent->left;
            }
      }

            if (sibling != NULL) {
                if (current == parent->left || (parent->left == current && current == NULL) ) { 
                    // null child man
                    insideNephew = sibling->left;
                    outsideNephew = sibling->right;
                } 
                
                else { // current is right or conceptual right NULL
                    insideNephew = sibling->right;
                    outsideNephew = sibling->left;
                }
            } 
                    else {
                        // must set nephews to null
                        insideNephew = NULL;
                        outsideNephew = NULL;
                    }
        }

        if (parent == NULL && current != root) { 
            return;  // need to make sure we are not at root, and that parent exists.
        }
        
        


        if (sibling != NULL && sibling->color == 'r') { // Case 1 (Your caseThree)
            caseThree(root, current, sibling, insideNephew, outsideNephew, parent);
           // reassign value functions will reassign any neccessary variables
            continue;
        }

        // when sibling exists and sibling is black
        bool SiblingChildrenBlack = true;
        // We create this for simplicity
        // if (sibling != NULL && )
        if (sibling != NULL && sibling->color == 'b') { // Only check children if sibling exists
            if (insideNephew != NULL && insideNephew->color == 'r') {
                SiblingChildrenBlack = false;
           
            }
            if (outsideNephew != NULL && outsideNephew->color == 'r') {
                SiblingChildrenBlack = false;
        } 
        }
        
        else { 
             SiblingChildrenBlack = true;
        }


        if (SiblingChildrenBlack == true) {
            
            if (parent != NULL && parent->color == 'r') { // calling case four
               cout << "callign case 4" << endl;
                caseFour(root, current, sibling, insideNephew, outsideNephew, parent);
                if (current != NULL) {
                    
                    current->color = 'b';
               return;
            } 
            }
            
            else { 
                caseTwo(root, current, sibling, insideNephew, outsideNephew, parent);
                current = parent; // Move problem up
            
            // if (root == NULL)
                if (current == root || current == NULL) return; 
               
               // break;
                continue;
            }
        } 
        
        else { // else then the siblingis black and has atleast one child that is
             if (sibling == NULL) { 
                 return; 
             }

            if (outsideNephew != NULL && outsideNephew->color == 'r') { // Case 4 (Your caseSix)
                caseSix(root, current, sibling, insideNephew, outsideNephew, parent);
                if (current != NULL) { 
                    current->color = 'b';
                 // current  need to exist.
                }
                
                return;
            
            } 
            else if (insideNephew != NULL && insideNephew->color == 'r') { // calling case 5
                 //  else { // 
                 // cout << "DELETION  FIXUP WE GET HERE!!!!" << endl;
                 
                 //
                cout << "CASE 5 DEBUG" << endl;
                caseFive(root, current, sibling, insideNephew, outsideNephew, parent);
                if (current != NULL) {
                    current->color = 'b';
                }
                 return;
            } 
            else {
                return;
                
            } // wE MUST MAKE SURE TO RETURN EVERYTHING
            // ANIKA's code did not work because she forgot to return..funny
        }
    }

    if (current != NULL) { // ensuring after double blacknode we are on ends as Blck
        // current->color= 'b'
        
        current->color = 'b';
    }
    if (root != NULL) { // always set root ot black
        root->color = 'b';
    }
}
