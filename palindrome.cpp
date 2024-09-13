/*
Parth Chaudhary
Mr. Galbraith
C++ 
9/11/2024
CITATIONS AT BOTTOM THERE ARE A LOT


*/




#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() { // main method
       
   
    bool stillActive = true; // setting this as true, because system will ask user if they want to enter another stirng
   
    while (stillActive) { // sets most of the function as 'active'
   
   
   
    char str1[81]; // creating 2 string variables, will be useful for later in code
    char str2[81];

    cout << "Enter a string with CHARACTERS: " << endl; // asks user to input a string 
    cin.getline(str1, 80, '\n'); // this will allow reading multiple lines of a string.
   

    int count = 0; // creating variables which will be beneficial for "cleaning" out the strings from puncuation and spaces
    int clean = 0;
    
    while (str1[count] != '\0') { // while it does not equal to a null charcter..
        if (!ispunct(str1[count]) && !isspace(str1[count])) { // does not allow puncuation and SPaces
            str2[clean]  = tolower(str1[count]); // for each char "cleaned" it will be compared to the originally entered sentence
            clean++; // adds to a clean so it can go to the next character
                bool palindrome = true; 

        }
        count++;
    }
   
    str2[clean] = '\0'; 
   
    bool palindrome = true;


    for (int i = 0; i < count/2; i++) { // creates an array which is the algorithim to figuring if it is a plaindrome or not
        if (str2[i] != str2[clean - i - 1]) {
        // this is the method which sttaes that if it does NOT equal (!=), then it will be incomplete


           
            palindrome = false;
           
            break; // breaks/exits the for loop
        }
    }
   
    if (palindrome == true) { 
        // if it meets the requirements of a palindorme (goes through the alogiithim above), thne it will set it as true
        // and inform the user that their string is a palindrome.
        cout << "It is a palindrome!" << endl;
       
    }
    else if (palindrome == false) { 
        // however, if it does not meet the requiemtns of a plaindrome, it will let the user know
        cout << "This string is NOT a palindrome" << endl;
       
    }
   
    char anotherString[5]; // after the user is either RIGHT or WRONG, the system will ask the user
    // if they want to play another round.
    cout << "Want to do another string?: (type yes/no) "  << endl;
            cin >> anotherString; // stores anotherSTring is a variable
            cin.ignore(); // ignores, because we mix cin.getline(), and cin above.
            
            // Compares the entered string to a potential answer of the string. If the user enters yes
            // it will tell the user to enter another string.
            if (strcmp(anotherString, "Yes") == 0) {
                stillActive = true; 
                // if they type yes, the system will rerun
            }
            else if (strcmp(anotherString, "yes") == 0) {

                stillActive = true;
                // if they type yes, the system will rerun
            }
           
            else if (strcmp(anotherString, "No") == 0) { // if the user enters no, then the game will end (active will be false)
                cout << "Thanks for playing!" << endl;
                stillActive = false; 
            }
            else if (strcmp(anotherString, "no") == 0) { 
                // if the user enters no, then the game will end (active will be false)
                cout << "Thanks for playing!" << endl;
                stillActive = false; 
            }

    }
   
    return false; 

   
}

/*
People:

- Jamal
- Aleena Shaik
- Sriram
- Elliot
- Aiden
- Diya Shah
- ruwa


Websites: https://www.programiz.com/cpp-programming/library-function/cctype/isspace

- https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
*/
