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
std::vector<Weapon *> Weapon::createWeapons(std::string &filePath) {
    std::vector<Weapon *> weapons;
    std::ifstream file(filePath);

    if (!file) {
        std::cout << "无法打开文件" << std::endl;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int id, attack;
        if (ss >> id >> name >> attack) {
            weapons.push_back(new Weapon(id, name, attack));
        }
    }
    return weapons;
}

int Weapon::getAttack() const {
    return this->attack;
}
void Weapon::getWeaponInfo() const {
    std::cout << getName() << "\t\t" << this->attack << std::endl;
}