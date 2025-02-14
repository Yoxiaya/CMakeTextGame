#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <iostream>
#include <vector>

class Item;
class Weapon : public Item {
private:
    int attack;

public:

    Weapon(int id, std::string name, int attack);

    int getAttack() const;

    void getWeaponInfo() const;
};

#endif
