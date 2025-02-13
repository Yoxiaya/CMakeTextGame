#ifndef ITEM_H
#define ITEM_H

#include <string>
class Item{

private:


    std::string name;
    int id;

public:
    Item(int id, std::string name);

    int getId() const;
    std::string getName() const;



};
#endif


