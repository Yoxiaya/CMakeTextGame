#include <iostream>
#include <string>
#include "Monster.h"
#include "Player.h"

Monster::Monster(std::string monsterName, int monsterHealth, int monsterAttack, int monsterDefense, int monsterSpeed, int monsterExpAccumulation) :
    name(monsterName), health(monsterHealth),maxHealth(monsterHealth), attack(monsterAttack), defense(monsterDefense), speed(monsterSpeed), exp(monsterExpAccumulation) {
}
void Monster::displayPlayerStats() const {
    std::cout << "怪物名称:" << name << std::endl;
    std::cout << "生命值: " << health << std::endl;
    std::cout << "攻击力: " << attack << std::endl;
    std::cout << "经验值: " << exp << std::endl;
}

std::string Monster::getName() const {
    return name;
}
int Monster::getHealth() const {
    return health;
}
int Monster::getDefense() const {
    return defense;
}
int Monster::getExp()const {
    return exp;
}
void Monster::getMonsterInfo() const {
    std::cout << name << "\t" << health << "\t" << defense << "\t" << speed << "\t" << exp << std::endl;
}
int Monster::getMaxHealth() const {
    return maxHealth;
}

void Monster::attackPlayer(Player *player) {
    std::cout << name << "攻击了" << player->getName() << std::endl;
    int attack = this->attack - player->getDefense();

    player->takeDamage(attack);
    std::cout << player->getName() << "受到了" << attack << "点伤害，" << "剩余生命值:" << player->getHealth() << std::endl;
}

void Monster::takeDamage(int damage) {
    int damageTaken = damage - defense;
    health -= damageTaken;
    if (health < 0)
        health = 0;
}

void Monster::reset() {
    health = maxHealth;
}

bool Monster::isDead() const {
    return health == 0;
}