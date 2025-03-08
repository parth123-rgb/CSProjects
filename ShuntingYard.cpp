#include <cstring>
#include <iostream>

using namespace std;

struct Node {

    char data;
    Node* next;
    Node* right;
    Node* left;

    //   newNode -> data;

};



void PUSH(Node*& stackHead, Node* newNode);
Node* POP(Node*& stackHead);
void PRINT(Node* stackHead);
void ENQUEUE(Node*& queueHead, Node* newNode);
Node* DEQUEUE(Node*& queueHead, Node* newNode);
int PRECEDENCE(char op);
void SHUNTINGYARD(Node*& queueHead, char infixFunction[], Node*& stackHead);
Node* PEEK(Node* stackHead);
void BINARYTREE(char infixFunction[50], Node*& stackHead, Node *& queueHead);



void INFIX(Node* stackHead);
void POSTFIX(Node* stackHead);
void PREFIX(Node* stackHead);




int main() {

    Node* stackHead = NULL;
    Node* queueHead = NULL;
    //char input[50];

    Node* right = NULL;
    Node* left = NULL;
    //  int queue;
    Node* newNode = new Node();
    bool whileGoing = true;
    char input[50];

    //PUSH(stackHead, newNode);
    //POP(stackHead);
    //PRINT(stackHead);

    char infixFunction[50];

    while (whileGoing) {



        cout << "Do you want to convert from INFIX to POSTFIX, PREFIX, OR CONVERTED INFIX?" << endl;
        cin >> input;


        cin.ignore();



        if (strcmp(input, "INFIX") == 0) {
            cout << "ENTER your INFIX function: ";


            cin >> infixFunction;
            cin.ignore();
	                SHUNTINGYARD(queueHead, infixFunction, stackHead);

			cout << "we get here shunting yard" << endl;
            BINARYTREE(infixFunction, stackHead, queueHead);

	    cout << "we get ot binary tree" << endl;
            INFIX(stackHead);


        }


        else if (strcmp(input, "POSTFIX") == 0) {


            cout << "ENTER your INFIX function: ";



            cin >> infixFunction;
            cin.ignore();
            SHUNTINGYARD(queueHead, infixFunction, stackHead);

            BINARYTREE(infixFunction, stackHead, queueHead);
            POSTFIX(stackHead);

        }
        else if (strcmp(input, "PREFIX") == 0) {

            cout << "ENTER your INFIX function: ";
            cin.ignore();
            cin >> infixFunction;
	                SHUNTINGYARD(queueHead, infixFunction, stackHead);

            BINARYTREE(infixFunction, stackHead, queueHead);
            PREFIX(stackHead);



        }







        //cout << "Precedence of + is: " << precedence(input);

      //cout << "Do you wish to convince from INFIX to POSTFIX, PREFIX, and 



        cout << "POSTFIX FUNCTION: ";
        while (queueHead != NULL) {

            Node* temp = DEQUEUE(queueHead, newNode);
            cout << temp->data; // print out the postfix function
            //cout << "Ahh" <<
        }

        PRINT(stackHead);
    }
    return 0;

}


void PUSH(Node*& stackHead, Node* newNode) { //x Node* current) {


    if (newNode == NULL) {

        return;

    }

    if (stackHead == NULL) {
        // if the head is open, create a new node in the head.
        // newNode -> next = stackHead;
        stackHead = newNode;
    }

    else {

        //Node* temp = stackHead;

      // stackHead = current;
        //while (stackHead->next != NULL) {
        newNode->next = stackHead;
        // temp->next = newNode;

           //}
    }
    stackHead = newNode;

    //temp->next = newNode;








}



Node* POP(Node*& stackHead) {


    if (stackHead == NULL) {

        return NULL;



    }
    Node* temp = stackHead;

    //if (stackHead->next != NULL) { // while the current's next is NOT open, set the current node equal to the current's next
    stackHead = stackHead->next; // edit ORIGINAL stackhead, and set it equal to the stackhead's next.

    temp->next = NULL;

    //cout << temp -> data;

    //return temp;

    //}
    //else if (stackHead->next == NULL) {
    // else if there is only one node in the stack, open it up!;
    //stackHead = NULL;
    return temp;

    //->next = stackHe



}


void PRINT(Node* stackHead) {

    Node* temp = stackHead;
    while (temp != NULL) { // while the list is not empty, print out the char data.


        cout << temp->data;
        temp = temp->next; // go to next node

        // PRINT(stackHead->next);


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
            //      temp = temp->next;

        }
        temp->next = newNode;

    }

}




Node* DEQUEUE(Node*& queueHead, Node* newNode) {



    if (queueHead == NULL) {

        return NULL;


    }


    Node* temp = queueHead;

    //cout << queueHead;
    queueHead = queueHead->next;
    // cout << queueHead;
    temp->next = NULL; // reset, and unattach from linked list, because we use QUEUEHEAD multiple times, and it could cause issues!

    return temp; // returning queuehead's temp

    // if the front is open 
    /* if (front == NULL) {
      rear = NULL;

    }
    */

}


int PRECEDENCE(char op) { // PEMDAS



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


    cout << "Your INFIXED function is" << infixFunction << endl;
    int functionLength = strlen(infixFunction);

    for (int i = 0; i < functionLength; i++) {
        // so we can get an index value!


        if (infixFunction[i] != '+' && infixFunction[i] != '-' && infixFunction[i] != '(' && infixFunction[i] != ')' && infixFunction[i] != '/' && infixFunction[i] != '^' && infixFunction[i] != '*') {

            Node* newNode = new Node();
            newNode->data = infixFunction[i];


            ENQUEUE(queueHead, newNode);

        }

        else if (infixFunction[i] == '+' || infixFunction[i] == '-' || infixFunction[i] == '/' || infixFunction[i] == '*' || infixFunction[i] == '^') {// if there is an operator... 
            while (stackHead != NULL && PRECEDENCE(PEEK(stackHead)->data) >= PRECEDENCE(infixFunction[i]) && (infixFunction[i] != '^' || PRECEDENCE(PEEK(stackHead)->data) > PRECEDENCE(infixFunction[i]))) {
                // checking if the stack head has something, compare the PRECEDENCE (order of operations)
                Node* newNode = POP(stackHead); // we can save it because this returns a NODE!!! pop operator onto the queue
                ENQUEUE(queueHead, newNode);



            }
            Node* newNode = new Node(); // getting operators from function
            newNode->data = infixFunction[i]; // set data equal to the operator
            PUSH(stackHead, newNode);


        }

        else if (infixFunction[i] == '(') {

            Node* newNode = new Node(); // to store parentheses on stack to manage operators.
            newNode->data = infixFunction[i];
            PUSH(stackHead, newNode); // if parentheses, push NODE ONTO THE OPERATOR STACK!
            PRINT(stackHead);

        }
        else if (infixFunction[i] == ')') {
            while (stackHead != NULL && stackHead->data != '(') { // while the saved character is not (



                Node* temp = POP(stackHead); // save the parentheses
		//ueHead);

		
	      temp->next = NULL;
	      temp->right = NULL;
	      temp -> left = NULL;
		ENQUEUE(temp, queueHead);
		//PRINT(stackHead);
            }

            if (stackHead != NULL && PEEK(stackHead)->data == '(') { // if the stack head is not empty, and if the data is ( WHILE the other conditions, pop it off

              //cout << stackHead -> data << endl;

                POP(stackHead); // removed the ( from stack.
                //cout << stackHead -> data << endl;





            }

        }

    }
    while (stackHead != NULL) { // while the stackhead is not empty, we pop off the top, and then queue it
      //    cout << "we get here" << endl;
        Node* temp = POP(stackHead);
        ENQUEUE(queueHead, temp);
    }


}





void BINARYTREE(char infixFunction[], Node*& stackHead, Node *& queueHead) {

    Node* temp = queueHead;
    cout << queueHead->data;
    Node* numberStack = new Node(); // creating stack so we can push the nodes onto it later

    int functionLength = strlen(infixFunction);

    for (int i = 0; i < functionLength; i++) {


        if (temp == NULL) {
            return;
        }

        while (temp != NULL) { // while the stackHead is NOT empty, we should run this code.   
            if (infixFunction[i] != '+' && infixFunction[i] != '-' && infixFunction[i] != '(' && infixFunction[i] != ')' && infixFunction[i] != '/' && infixFunction[i] != '^' && infixFunction[i] != '*') {

                Node* newNode = new Node();
                // we create a new node, then push the numbers into the data variable
                newNode->data = infixFunction[i];


                PUSH(newNode, numberStack); // push onto stack

            }

            else { // if the input is not a number (so if it is an operator)

                Node* newNode = new Node();
                newNode->data = infixFunction[i]; // similar to before, setting data variable as the OPERATOr this time.

                newNode->right = POP(numberStack); // we will take this for the right node of the tree, and set the operator to it
		
                //Node* leftOperatorNode = POP(numberStack);

                //newNode->left = leftOperatorNode;
		newNode -> left = POP(numberStack);
                PUSH(newNode, numberStack); // pushing the operand nodes to the number stack.



                temp = DEQUEUE(queueHead, newNode);
            }
        }
        stackHead = PEEK(numberStack);

        cout << stackHead->data;
    }
}




void PREFIX(Node * stackHead) {

        if (stackHead == NULL) {
            return;
        }
        // opposite of postfix!
        cout << "PREFIX FUNCTION: " << stackHead->data;

        if (stackHead->left != NULL) {

            PREFIX(stackHead->left);
        }

        if (stackHead->right != NULL) {

            PREFIX(stackHead->right);
	    
        }
    }





    void POSTFIX(Node * stackHead) {

        if (stackHead == NULL) {
            return;
        }

        if (stackHead->left != NULL) {

            POSTFIX(stackHead->left);

        }

        if (stackHead->right != NULL) {

            POSTFIX(stackHead->right);

        }
        // after all the changes in shunting yard and binary tree are done, THEN PRINT!
        cout << "POSTFIX FUNCTION: " << stackHead->data;

    }



    void INFIX(Node * stackHead) {


        if (stackHead == NULL) {

            return;
        }

        if (stackHead->left != NULL) {

            INFIX(stackHead->left);
        }

        cout << "INFIX FUNCTION: " << stackHead->data;


        if (stackHead->right != NULL) {


            INFIX(stackHead->right);
        }
    }
