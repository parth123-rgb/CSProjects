#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    char* name;

public:
    Item(char* itemName);
    char* getName();
};

#endif
