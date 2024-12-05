#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

void createRooms(vector<Room*>& room);
void playGame(vector<Room*>& room, vector<Item*>& inventory, bool& stillPlaying);
//void winCondition(Room* currentRoom, bool& stillPlaying, vector<Room*>& room);

int main() {
    bool stillPlaying = true;
    vector<Room*> room;
    vector<Item*> inventory;  // Inventory vector to hold items the player collects
    createRooms(room);
    playGame(room, inventory, stillPlaying);
  //  winCondition(currentRoom, stillPlaying);
    
    return 0;
}

void createRooms(vector<Room*>& room) {
    
    
    // 
 char* roomOne = new char[10];
  strcpy(roomOne, "Entrance");
 
  char* roomTwo = new char[15];
  strcpy(roomTwo, "Hallway");

  char* roomThree = new char[20];
  strcpy(roomThree, "Living Room");

  char* roomFour = new char[15];
  strcpy(roomFour, "Classroom");

  char* roomFive = new char[15];
  strcpy(roomFive, "Bathroom");

  char* roomSix = new char[20];
  strcpy(roomSix, "Study Room");
 
  char* roomSeven = new char[20];
  strcpy(roomSeven, "Library");

  char* roomEight = new char[10];
  strcpy(roomEight, "Garden");

  char* roomNine = new char[20];
  strcpy(roomNine, "Lunch Hall");


  char* roomTen = new char[15];
  strcpy(roomTen, "Basement");

  char* roomEleven = new char[10];
  strcpy(roomEleven, "Attic");

  char* roomTwelve = new char[10];
  strcpy(roomTwelve, "Baclony");


    char* roomThirteen = new char[10];
  strcpy(roomThirteen, "Garage");

  char* roomFourteen = new char[10];
  strcpy(roomFourteen, "Rooftop");

 char* roomFifteen = new char[35];
  strcpy(roomFifteen, "Outside entrance");

   char* roomSixteen = new char[30];
  strcpy(roomSixteen, "Lecture Theater");

   
  char* roomSeventeen = new char[25];
  strcpy(roomSeventeen, "Campus pub");

  char* roomEighteen = new char[25];
  strcpy(roomEighteen, "Computer lab");


  char* roomNineteen = new char[15];
  strcpy(roomNineteen, "Office");

  char* roomTwenty = new char[20];
  strcpy(roomTwenty, "Room One Twenty");


  char* roomTwentyOne = new char[10];
  strcpy(roomTwentyOne, "Kitchen");




 Room* entrance = new Room(roomOne);
  room.push_back(entrance);

//  cout << "here " << endl;
  
  Room* hallway = new Room(roomTwo);
  room.push_back(hallway);
  
  Room* livingRoom = new Room(roomThree);
  room.push_back(livingRoom);
  
  Room* classroom = new Room (roomFour);
  room.push_back(classroom);
  
  Room* bathroom = new Room(roomFive);
  room.push_back(bathroom);
  
  Room* studyRoom = new Room(roomSix);
  room.push_back(studyRoom);
  
  Room* library = new Room(roomSeven);
  room.push_back(library);
  
  Room* garden = new Room(roomEight);
  room.push_back(garden);
  
  Room* lunchHall = new Room(roomNine);
  room.push_back(lunchHall);

  Room* basement = new Room(roomTen);
  room.push_back(basement);
  
  Room* attic = new Room(roomEleven);
  room.push_back(attic);
  
  Room* balcony = new Room(roomTwelve);
  room.push_back(balcony);
  
  Room* garage = new Room(roomThirteen);
  room.push_back(garage);
  
  Room* rooftop = new Room(roomFourteen);
  room.push_back(rooftop);
  
  Room* outside = new Room(roomFifteen);
  room.push_back(outside);
  
  Room* theatre = new Room(roomSixteen);
  room.push_back(theatre);
  
  Room* pub = new Room(roomSeventeen);
  room.push_back(pub);
  
  Room* lab = new Room(roomEighteen);
  room.push_back(lab);
  
  Room* office = new Room(roomNineteen);
  room.push_back(office);
  
  Room* onetwenty = new Room(roomTwenty);
  room.push_back(onetwenty);


  Room* kitchen = new Room(roomTwentyOne);
  room.push_back(kitchen);



 /*
  char* book = new char[10];
  strcpy(book, "book");

  char* key = new char[10];
  strcpy(key, "key");

  char* map = new char[10];
  strcpy(map, "key");

  char* torch = new char[10];
  strcpy(torch, "torch");

  char* hammer = new char[10];
  strcpy(hammer, "hammer");
*/


    // Create items
    char* keyName = new char[50];
    strcpy(keyName, "Key");
    Item* key = new Item(keyName);
    
    entrance->setItem(keyName, key);  // Add the key to the entrance room
    
    
    char* bookName = new char[50];
    strcpy(bookName, "Book");
    Item* book = new Item(bookName);
    
    library -> setItem(bookName, book);
    
    
     
    char* mapName = new char[50];
    strcpy(mapName, "Map");
    Item* map = new Item(mapName);
    
    hallway -> setItem(mapName, map);
   
    
    char* torchName = new char[50];
    strcpy(torchName, "Torch");
    Item* torch = new Item(torchName);
    
    hallway -> setItem(torchName, torch);
    
    
      
    char* hammerName = new char[50];
    strcpy(hammerName, "Hammer");
    Item* hammer = new Item(hammerName);
    
    attic -> setItem(hammerName, hammer);
    
    
    
    

    // Set exits (directions as char arrays)
    char* North = new char[6];
    strcpy(North, "NORTH");

    char* South = new char[6];
    strcpy(South, "SOUTH");

    char* West = new char[6];
    strcpy(West, "WEST");
    
    char* East = new char[6];
    strcpy(East, "EAST");
   
   
   
   
   
   
    livingRoom->setExit(South, hallway);
    outside -> setExit(West, pub);
outside -> setExit(North, onetwenty);

entrance -> setExit(North, hallway);

hallway -> setExit(South, entrance);
hallway -> setExit(West, kitchen);
hallway -> setExit(East, livingRoom);
hallway -> setExit(North, studyRoom);

kitchen -> setExit(West, hallway);
kitchen -> setExit(North, lunchHall);


 
 livingRoom -> setExit(West, hallway);
 livingRoom -> setExit(North, library);
 livingRoom -> setExit(East, garden);

 classroom -> setExit(South, basement);
classroom -> setExit(West, bathroom);

 bathroom -> setExit(East, classroom);

 studyRoom -> setExit(South, hallway);
 studyRoom -> setExit(West, library);
// studyRoom -> setItem(book);

 
 library -> setExit(South, livingRoom);
 library -> setExit(East, studyRoom);


 
 garden -> setExit(West, livingRoom);
 garden -> setExit(North, lunchHall);
 garden ->setExit(East, balcony);

 lunchHall -> setExit(South, garden);
 lunchHall -> setExit(West, kitchen);

 basement -> setExit(North, classroom);
 basement -> setExit(East, attic);

 attic -> setExit(West, basement);
 attic -> setExit(North, rooftop);

 balcony -> setExit(West, garden);
 balcony -> setExit(North, garage);

 garage -> setExit(South, balcony);

 rooftop -> setExit(South, attic);



//    classroom->setExit(East, NULL);  // No exit yet

    // Set another exit
    livingRoom->setExit(East, classroom);
}


void playGame(vector<Room*>& room, vector<Item*>& inventory, bool& stillPlaying) {
    Room* currentRoom = room[0];  // starting room

    char input[10];
    char direction[10];
    char itemName[50];

    while (stillPlaying) {
        // Get the room description and check for the win condition
                char* descr = currentRoom->getDescription();

        // Prompt for actions
        cout << "Type 'GO' to move" << endl;
        cout << "Type 'PICK' to pick up an item" << endl;
        cout << "Type 'DROP' to drop any item in your inventory" << endl;
        cout << "Type 'SHOW' to display your inventory" << endl;
        cout << "Type 'QUIT' to quit the game" << endl;

        cin >> input;
        cin.ignore();

        if (strcmp(input, "GO") == 0) {
            cout << "Enter a cardinal direction (NORTH/EAST/SOUTH/WEST): " << endl;
            cin >> direction;
            cin.ignore();
    
            Room* nextRoom = currentRoom->getExit(direction);

	    cout << nextRoom;
	      //  cout << "here" << endl;
	    if (nextRoom != NULL) {
	     
	      currentRoom = nextRoom;
	      
	    }
            else {
                cout << "This exit does not exist, try again!" << endl;
            }
        }

        
       
        else if (strcmp(input, "PICK") == 0) {
            cout << "Enter item to pick up: ";
            cin >> itemName;
            cin.ignore();

            Item* item = currentRoom->getItem(itemName);
            if (item != NULL) {
                cout << item->getName() << " has been added to your inventory!" << endl;
                inventory.push_back(item);
                currentRoom->itemRemove(itemName);
            }
            else {
                cout << "This item is not in this room, try again!" << endl;
            }
        }
        else if (strcmp(input, "DROP") == 0) {
            cout << "Enter the item you wish to drop:" << endl;
            cin >> itemName;
            cin.ignore();

            for (auto it = inventory.begin(); it != inventory.end(); ++it) {
                if (strcmp((*it)->getName(), itemName) == 0) {
                    Item* dropItem = *it;
                    currentRoom->itemDrop(dropItem);
                    inventory.erase(it);
                    cout << "You dropped: " << dropItem->getName() << "!" << endl;
                    break;
                }
            }
        }
        else if (strcmp(input, "SHOW") == 0) {
            cout << "Current items in your inventory: " << endl;
            for (auto it = inventory.begin(); it != inventory.end(); it++) {
                cout << (*it)->getName() << endl;
            }
        }
        else if (strcmp(input, "QUIT") == 0) {
            cout << "Thank you for playing!" << endl;
            exit(0);
            }

        // If the player has won or quit the game
        if (strcmp(currentRoom -> winCondition(), "CONTINUE") == 0) {
//        char* winCondition = currentRoom->winCondition();

         //   cout<<"getting here?"<<endl;
          //currentRoom = room[0];
        //  cout << "Your current room is the: Entrance " << endl;
            stillPlaying = true;  // Allow the player to start a new game
        }
    }
}


/*
void winCondition(Room* currentRoom, bool& stillPlaying, vector<Room*>& room) {
    if (strcmp(currentRoom->getDescription(), "Hallway") == 0) { // Win condition room
        char playAgain[5];
        cout << "Congratulations! You have won. You have reached Room One Twenty." << endl;
        cout << "Do you wish to play again (Yes/No): ";
        cin >> playAgain;
        cin.ignore();  // Ignore the newline left by cin

        if (strcmp(playAgain, "Yes") == 0) {
            stillPlaying = true;  // Continue playing
        }
        else if (strcmp(playAgain, "No") == 0) {
            cout << "Thanks for playing!" << endl;
            stillPlaying = false;  // End the game
        }
    }
 //   return 0;
}
*/
