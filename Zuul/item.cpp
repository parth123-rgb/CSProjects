#include <cstring>
#include <iostream>
#include "item.h"

Item::Item(char* itemName) {
    name = new char[50];
    strcpy(name, itemName);
}

char* Item::getName() {
    return name;
}
