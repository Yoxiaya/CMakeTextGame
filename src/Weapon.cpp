#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Weapon.h"
#include "Item.h"

Weapon::Weapon(int id, std::string name, int attack) :
    Item(id, name), attack(attack) {
    };


int Weapon::getAttack() const {
    return this->attack;
}
void Weapon::getWeaponInfo() const {
    std::cout << getName() << "\t\t" << this->attack << std::endl;
}