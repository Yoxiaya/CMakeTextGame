#include "Item.h"

using namespace std;

Item::Item(int itemId, string itemName): id(itemId), name(itemName) {}

int Item::getId() const{
    return id;
}
string Item::getName() const{
    return name;
}