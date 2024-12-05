#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include "item.h"

using namespace std;

class Room {

  
public:
    Room(char* descrip);
    void setExit(char* direction, Room* room);
    Room* getExit(char* direction);
    char* getDescription();
    void setItem(char* itemName, Item* item);  // Add an item to the room
    Item* getItem(char* itemName);  // Get an item from the room
    void itemRemove(char* itemName);
    char* description;
    map<char*, Room*> exits;
    map<char*, Item*> items;
    void itemDrop(Item* item);
    bool userPlay = true;
    char* winCondition();

};

#endif
