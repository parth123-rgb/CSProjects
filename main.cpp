#include <cstring>
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* right;
    Node* left;

    // newNode -> data;
};

void PUSH(Node*& stackHead, Node* newNode);
Node* POP(Node*& stackHead);
void PRINT(Node* stackHead);
void ENQUEUE(Node*& queueHead, Node* newNode);
Node* DEQUEUE(Node*& queueHead);
int PRECEDENCE(char op);
void SHUNTINGYARD(Node*& queueHead, char infixFunction[], Node*& stackHead);
Node* PEEK(Node* stackHead);
void BINARYTREE(char infixFunction[], Node*& stackHead, Node*& queueHead, Node*& treeNode);
void INFIX(Node* treeNode);
void POSTFIX(Node* treeNode);
void PREFIX(Node* treeNode);

int main() {
    Node* stackHead = NULL;
    Node* queueHead = NULL;
    Node* right = NULL;
    Node* left = NULL;
    Node* treeNode = new Node();
    Node* newNode = new Node();
    bool whileGoing = true;
    char input[50];

    char infixFunction[50];

    while (whileGoing) {

      cout << "Do you want to convert from INFIX to POSTFIX, PREFIX, OR CONVERTED INFIX?" << endl;

      cin >> input;

      cin.ignore();

        Node* stackHead = NULL;
        Node* queueHead = NULL;

        if (strcmp(input, "INFIX") == 0) {

	  cout << "ENTER your INFIX function: ";

	  cin >> infixFunction;
	  //	  cin.ignore();
            SHUNTINGYARD(queueHead, infixFunction, stackHead);
            //cout << "we get here shunting yard" << endl;
            BINARYTREE(infixFunction, stackHead, queueHead, treeNode);
           // cout << "we get to binary tree" << endl;
           
           
            cout << "Infix Function: " << endl;
            INFIX(treeNode);
        }
        else if (strcmp(input, "POSTFIX") == 0) {
            cout << "ENTER your INFIX function: ";
            cin >> infixFunction;
	    //            cin.ignore();
            SHUNTINGYARD(queueHead, infixFunction, stackHead);
            BINARYTREE(infixFunction, stackHead, queueHead, treeNode);
            cout << "Postfix Function: " << endl;
            POSTFIX(treeNode);
        }
        else if (strcmp(input, "PREFIX") == 0) {
            cout << "ENTER your INFIX function: ";
	    //            cin.ignore();
            cin >> infixFunction;
            SHUNTINGYARD(queueHead, infixFunction, stackHead);
            BINARYTREE(infixFunction, stackHead, queueHead, treeNode);
            cout << "Prefix Function: " << endl;
            PREFIX(treeNode);
        }

       // cout << "POSTFIX FUNCTION: ";
        
}
    return 0;
}

void PUSH(Node*& stackHead, Node* newNode) {
    if (newNode == NULL) {
        return;

    }

    if (stackHead == NULL) {
        // if the head is open, create a new node in the head.
        newNode->next = stackHead;
        stackHead = newNode;
    }

    else {
        newNode->next = stackHead;
        stackHead = newNode;
    }
}




Node* POP(Node*& stackHead) {
    if (stackHead == NULL) {
        return NULL;
    }

    Node* temp = stackHead;

    stackHead = stackHead->next;
    temp->next = NULL;
    return temp;
}

void PRINT(Node* stackHead) {
    Node* temp = stackHead;

    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

Node* PEEK(Node* stackHead) {

  if (stackHead == NULL) {
        return NULL;
    }
    return stackHead;
}

void ENQUEUE(Node*& queueHead, Node* newNode) {

  if (queueHead == NULL) {
        queueHead = newNode;
    }

  else {
        Node* temp = queueHead;

	while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* DEQUEUE(Node*& queueHead) {

  if (queueHead == NULL) {
        return NULL;
    }

  Node* temp = queueHead;
    queueHead = queueHead->next;
    temp->next = NULL;
    return temp;
}

int PRECEDENCE(char op) {

  if (op == '-' || op == '+') {
        return 1; // least precedence, lowest on PEMDAS
    }

  else if (op == '*' || op == '/') {
        return 2; // more precedence, but less than power
    }

  else if (op == '^') {
        return 3; // highest precedence
    }

  else {
        return 0; // we return 0 if the operator is not valid.
    }
}

void SHUNTINGYARD(Node*& queueHead, char infixFunction[], Node*& stackHead) {
      cout << "Your INFIXED function is " << infixFunction << endl;
    int functionLength = strlen(infixFunction);

    for (int i = 0; i < functionLength; i++) {
        if (infixFunction[i] != '+' && infixFunction[i] != '-' && infixFunction[i] != '(' && infixFunction[i] != ')' && infixFunction[i] != '/' && infixFunction[i] != '^' && infixFunction[i] != '*') {
            Node* newNode = new Node();
            newNode->data = infixFunction[i];
            ENQUEUE(queueHead, newNode);
        }
        else if (infixFunction[i] == '+' || infixFunction[i] == '-' || infixFunction[i] == '/' || infixFunction[i] == '*' || infixFunction[i] == '^') {
            while (stackHead != NULL && PRECEDENCE(PEEK(stackHead)->data) >= PRECEDENCE(infixFunction[i]) && (infixFunction[i] != '^' || PRECEDENCE(PEEK(stackHead)->data) > PRECEDENCE(infixFunction[i]))) {
                Node* newNode = POP(stackHead);
                ENQUEUE(queueHead, newNode);
            }
            Node* newNode = new Node();
            newNode->data = infixFunction[i];
            PUSH(stackHead, newNode);
        }
        else if (infixFunction[i] == '(') {
            Node* newNode = new Node();
            newNode->data = infixFunction[i];
            PUSH(stackHead, newNode);
        }
        else if (infixFunction[i] == ')') {
            while (stackHead != NULL && stackHead->data != '(') {
                Node* temp = POP(stackHead);
                ENQUEUE(queueHead, temp);
            }
            if (stackHead != NULL && PEEK(stackHead)->data == '(') {
                POP(stackHead);
            }
        }
    }

    while (stackHead != NULL) {
        Node* temp = POP(stackHead);
        ENQUEUE(queueHead, temp);
    }
}

void BINARYTREE(char infixFunction[], Node*& stackHead, Node*& queueHead, Node*& treeNode) {
    //Node* temp = queueHead;
    Node* numberStack = NULL;
    
    //    /
        while (queueHead != NULL) {
	 Node* newNode = DEQUEUE(queueHead);

	  char infixFunction = newNode->data;

            if (infixFunction != '+' && infixFunction != '-' && infixFunction != '(' && infixFunction != ')' && infixFunction != '/' && infixFunction != '^' && infixFunction != '*') {
                
	      newNode->left=NULL;
		newNode->right= NULL;
                PUSH(numberStack, newNode);
            }
            else {
              //  Node* newNode = new Node();
                //newNode->data = infixFunction[i];
                Node* right = POP(numberStack);
                Node* left = POP(numberStack);
                //PUSH(numberStack, newNode);
               // temp = DEQUEUE(queueHead);
		  
                        newNode->left = left;
	    
            newNode->right = right;
            PUSH(numberStack, newNode);

            }
            
            
            //
            ///stackHead->data;
     //   }
            
            
        }
        
       treeNode = POP(numberStack);

}

void PREFIX(Node* treeNode) {
    if (treeNode == NULL) {
        return;
    }
    cout << treeNode->data;

    if (treeNode->left != NULL) {
        PREFIX(treeNode->left);
    }

    if (treeNode->right != NULL) {
        PREFIX(treeNode->right);
    }
}

void POSTFIX(Node* treeNode) {
    if (treeNode == NULL) {
        return;
    }

    if (treeNode->left != NULL) {
        POSTFIX(treeNode->left);
    //}

   // if (treeNode->right != NULL) {
        POSTFIX(treeNode->right);
    }

    cout << treeNode->data;
}

void INFIX(Node* treeNode) {
    if (treeNode == NULL) {
        return;
    }

    if (treeNode->left != NULL) {
        INFIX(treeNode->left);
    }

   cout <<  treeNode->data;

    if (treeNode->right != NULL) {
        INFIX(treeNode->right);
    }
}
