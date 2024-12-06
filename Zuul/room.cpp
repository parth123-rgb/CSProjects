#include <cstring>
#include <iostream>
#include "room.h"

using namespace std;

Room::Room(char* descrip) {
    description = new char[50];
    strcpy(description, descrip);
}

void Room::setExit(char* direction, Room* room) {
    exits.insert(pair<char*, Room*>(direction, room));
}

Room* Room::getExit(char* direction) {

  //cout << "here" << endl;

    for (auto it = exits.begin(); it != exits.end(); it++) {

      //cout << "for loop" << endl;
      //cout << direction << endl;

	 if (strcmp (it->first, direction) == 0) {

	   //	   cout << it -> second -> getDescription() << endl;
	   return it->second;
        }
    }
    return NULL;
}

void Room::getDescription() {
    cout << "Your current room is the: " << description << endl;


    // Display exits if they exist
    if (exits.size() > 0) {
        cout << "Exit Directions: " << endl;
        for (auto it = exits.begin(); it != exits.end(); it++) {
            cout << it->first << endl;
        }
    }

    // Display items if they exist
    if (items.size() > 0) {
        cout << "Items in this area: ";
        for (auto it = items.begin(); it != items.end(); it++) {
            cout << it->first << endl;
        }
        cout << endl;
    }

    // Return a pointer to "CONTINUE"
    

}


bool Room::winCondition(Room*& currentRoom, Room* entrance) {
    if (strcmp(description, "Room One Twenty") == 0) {
        cout << "You won! You reached the best room (because Parth is in it)!" << endl;
        cout << "Do you wish to play again? (Yes/No): " << endl;
        char replay[5];
        cin >> replay;
        cin.ignore();  // Ignore the newline left by cin
    
        if (strcmp(replay, "Yes") == 0) {
	  currentRoom = entrance;
	  //char* continueGame = new char[9];  // Allocate space for "CONTINUE" (8 + '\0')
		 //strcpy(continueGame, "CONTINUE");
    return true; 
            // If the player chooses to play again, return a pointer to "CONTINUE"
           
        }
        else if (strcmp(replay, "No") == 0) {
            cout << "Thank you for playing!" << endl;
	    return false;
        }
    }
    return true;
}




void Room::setItem(char* itemName, Item* item) {
    items.insert(pair<char*, Item*>(itemName, item));
}

Item* Room::getItem(char* itemName) {
    for (auto it = items.begin(); it != items.end(); it++) {
        if (strcmp(it->first, itemName) == 0) {
            return it->second;
        }
    }
    return NULL;
}


void Room::itemDrop(Item* item) {
    // Add item to the room
    char* itemName = item->getName();
    setItem(itemName, item);
}




void Room::itemRemove(char* itemName) {
    
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (strcmp(it->second->getName(), itemName) == 0) {
       
            items.erase(it);
            break;
        }
    }
}
