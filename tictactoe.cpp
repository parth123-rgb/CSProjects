#include <iostream>
#include <cstring>

using namespace std;

void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char Player, bool& replay, int& xWins, int& oWins);
void takeTurn(char board[3][3], int row, int col, char& Player);
// bool playAgain(char input[5], bool replay);
bool checkTie(char board[3][3], char input[5], bool& replay, int row, int col);
// declaring variables for the methods 

int main () {
  // int main method
  
  char board[3][3]; // defining the board variable
  int xWins = 0; // creating an x win count for when player X wins the game
  bool whileGoing = false; 
  int oWins = 0; // creating an o win count for when player O wins the game
  char Player = 'X'; // creating the player, and setting it to O
  // char input[3];
  int row; // row variable
  int col; // column variable
  bool replay = false; // will use when the user wishes or does not wish to replay game
  char input[5]; // for when the user inouts stuff


   while (whileGoing==0) {

     Player = 'X';

     replay = true;

  
     
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) { // creating the board
	 board[row][col] = '-';
       }
   }

  // if (playAgain(input, replay) == true) {
  while (replay) {
    
 printBoard(board);
 takeTurn(board, row, col, Player);  // defining the methods I wish to use
 checkTie(board, input, replay, row, col);
 //playAgain(input, replay);

  

 if (Player == 'X') { // check win regardless of which player it is
	checkWin(board, Player, replay, xWins, oWins);
	Player = 'O';
       //board[row][col] = Player;
     }
     else {
       checkWin(board, Player, replay, xWins, oWins);
       Player = 'X';
     }
}
	   

      
      // if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' && board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-') {
  //cout << "This is a tie" << endl;
  printBoard(board);
  cout << "Do you want to play again? (Yes/No)" << endl;
  // asks the user if they wish to play again
       cin>>input;
      if (strcmp(input, "Yes") == 0) {
	replay = true;
	// if they say yes , the system will replay
      }
        else if (strcmp(input, "No") == 0) {
	  exit(0);
	  // if the user says no, the system will end.
	  replay = false;
          exit(0);
	 
        }
	else{
	  exit(0);
	}
	  replay = false;
  
      }

    

   
   
   //if (replay == true) {
   

      // }
   

return 0;
}










 
// prints the board out here
void printBoard(char board[3][3]) {
  for (int row = 0; row < 3; row++) {
    cout << " " << board[row][0] << " | " << board[row][1] << " | " << board[row][2] << " \n";
    //for (int col = 0; col < 3; col++) {

      //      cout << board[1][col] << " - " << board[2][col] << " - " << board[3][col] << "\n";
        }

}


  
       
     

// method for taking turn , switches the oplayers turn after the last

void takeTurn(char board[3][3], int row, int col, char& Player) {

    //  for (int turn = 0; turn < 9; turn++) {
    //printBoard(board);

    cout << "Player: " << Player << " enter a row (0 to 2) : " << endl;
    cin >> row;
    cout << "Enter a column (0 to 2): " << endl;
    cin >> col;

    // asks the user where they wanna place their player

    
    // if there is in a invalid move...
    while (board[row][col] != '-') {
      cout << "This was an invalid move" << endl;
      cout << "Enter a row: " << endl;
      cin >> row;
      cout << "Enter a column: " << endl;
      cin >> col;
      // will ask the player again
  }
    if (Player == 'X') { // actualyl swtiching the turn
        //Player = 'X';
        board[row][col] = Player;
        //Player = 'O';

      }

      else if (Player == 'O'){
	

       // Player = ' ';
        // board[row][col] = Player;
    // Player = ' ';	// board[row][col] = Player;
       //Player = 'X';

	      board[row][col] = Player;
     }

      
  
  // if (Player = 'X') ? 'O' : 'X'; 
}



// checkWin method , checks for wins for every potential possibility
    
bool checkWin(char board[3][3], char Player, bool& replay, int& xWins, int& oWins) {


  // each time when the win is check for, if it is true, print out the player who won, AND how many wins they have.
  
if (board[0][0] == Player && board[0][1] == Player && board[0][2] ==Player) {
  cout << Player << " Wins!" << endl;
  if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
  replay=false;
  
}
if (board[1][0] == Player && board[1][1] == Player && board[1][2] ==
Player) {

  cout << Player << " Wins" << endl;
   if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
if (board[2][0] == Player && board[2][1] == Player && board[2][2] ==
Player) {
  cout << Player << " Wins" << endl;
   if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
 if (board[0][0] == Player && board[1][0] == Player && board[2][0] ==
Player) {
   cout << Player << " Wins" << endl;
    if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
if (board[0][1] == Player && board[1][1] == Player && board[2][1] ==
Player) {
  cout << Player << " Wins" << endl;
   if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
if (board[0][2] == Player && board[1][2] == Player && board[2][2] ==
Player) {
  cout << Player << " Wins" << endl;
   if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
if (board[0][0] == Player && board[1][1] == Player && board[2][2] ==
Player) {
  cout << Player << " Wins" << endl;
   if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
replay=false;
}
if (board[0][2] == Player && board[1][1] == Player && board[2][0] == Player) {
cout << Player << " Wins" << endl;
  if (Player == 'X') {
    xWins++;
    cout << "Player " << Player << "has won:" << xWins << "times!!" << endl;
  }
  else if (Player == 'O') {
  oWins++;
    cout << "Player" << Player << "has won:" << oWins << "times!!" << endl; 
  }
 
  replay=false;
}
// inputting all win possibilites
      









	  

       

  return false;
}

/*
bool playAgain(char input[5], bool replay) {

 
 
      return false;

}


*/

/* void checkTie (char board[3][3]) {


  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {

      if (board[0][0] && board[0][1] && board[0][2] && board[1][0] && board[1][1] && board[1][2] && board[2][0] && board[2][1] && board[2][2] == '-')
  ction ‘bool checkTie(char (*)[3]
 if (board[0][0] && board[0][1] && board[0][2] && board[1][0] && board[1][1] && board[1][2] && board[2][0] && board[2][1] && board[2][2] == '-')
  
  }

}
*/


// if there is a tie...
bool checkTie(char board[3][3], char input[5], bool& replay, int row, int col) {
  if (board[0][0]=='-' || board[0][1]== '-' || board[0][2]== '-' || board[1][0]== '-' || board[1][1] == '-' || board[1][2] == '-' || board[2][0] == '-' || board[2][1]== '-' || board[2][2] == '-') {
  
    replay = true;
          return true;
        }
     replay = false;
    
  return false;
}
