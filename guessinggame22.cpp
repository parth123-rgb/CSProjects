    #include <iostream>
    #include <cstdlib>
    #include <ctime>
    #include <cstring>
    
    using namespace std;
    
    int main() {
        srand(time(0)); // Seed for random number generation
        
        bool stillActive = true;
        
        while (stillActive) {
            int randomNumber = rand() % 100; // Generate a random number
            int userGuess = 0;
            int guessCount = 0;
            char input[100]; 
            // creates a char array and will understand any number inputted by the suer
            // from 1-100, will allow system to read. User must  enter 1 to 100.
    
            cout << "Enter your guess: " << endl;  // asks the user to enter their integer guess
    
            while (userGuess != randomNumber) { 
                // while the guess by the user does not match with the randomly guessed number...
                cin >> input; // analyze the user input
                guessCount++; // adds a number to guess count variable (will print out at end)
                userGuess = atoi(input); // "ATOI" converts a char array (that we created above) input to integer
    
                cout << "You Typed: " << input << endl; // Basically repeats what the user guessed.
                cout << userGuess << endl; // prints out the user guess (attached to line above)
    
                if (userGuess < randomNumber) { 
                    //if the user makes a guesss that is lower than the randomly guessed number..
                    cout << "You guessed lower than the number! Guess again: " << endl;
                    //the user prints this out
                } 
                else if (userGuess > randomNumber) {
                    // or if the user guesses greater than the random number...
                    cout << "Your guess is greater than the random number! Guess again: " << endl;
                    //requests to guess again
                } 
            
                else { 
                // if the guess is neither greater or lower than the guess, than they are correct....
                    cout << "Your guese is correct!!!! " << randomNumber 
                    << "You took : "<< guessCount << " guesses" << endl;
                }
            }
    
            cout << "Do you want to play again? You should:  (Type 1 to play again, type 2 to end the system)" << endl;
            cin >> input; // This code prints out and asks for an onput
    
            // This checks/verifies if the user wants to play again 
            if (strcmp(input, "1") == 0) {
                // if they type yes, the system will rerun
                stillActive = true;
            } 
            else if (strcmp(input, "2") == 0) { // if they do not type yes, and type no, it will not.
                stillActive = false;
                //
            }
        }
        
        return false;
    }
