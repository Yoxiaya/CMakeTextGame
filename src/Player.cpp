#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Weapon.h"

Player::Player(std::string playerName, int playerHealth, int playerAttack, int playerDefense, int playerSpeed,
               int playerExpAccumulation) :
    name(playerName), health(playerHealth), maxHealth(playerHealth), attack(playerAttack), defense(playerDefense),
    speed(playerSpeed), expAccumulation(playerExpAccumulation), weapon(nullptr), level(1), expLimit(200) {};

void Player::displayPlayerStats() const {
    std::cout << "玩家名称:" << name << std::endl;
    std::cout << "等级: " << level << std::endl;
    std::cout << "生命值: " << health << "/" << maxHealth << std::endl;
    std::cout << "攻击力: " << attack << "+" << (weapon == nullptr ? 0 : weapon->getAttack()) << std::endl;
    std::cout << "防御力: " << defense << std::endl;
    std::cout << "速度: " << speed << std::endl;
    std::cout << "装备武器: " << (weapon == nullptr ? "无" : weapon->getName()) << std::endl;
    std::cout << "经验值: " << expAccumulation << "/" << expLimit << std::endl;
}
void Player::showSkill() const {
    std::cout << "1.普通攻击" << std::endl;
    std::cout << "2.技能1" << std::endl;
}
void Player::levelUp() {
    level++;
    expAccumulation -= expLimit;
    maxHealth += 50;
    health = maxHealth;
    attack += 10;
    defense += 5;
    speed += 2;
    std::cout << name << "升级了！等级提升至" << level << std::endl;
}
std::string Player::getName() const {
    return name;
}
int Player::getHealth() const {
    return health;
}
int Player::getDefense() const {
    return defense;
}
int Player::getMaxHealth() const {
    return maxHealth;
}

void Player::equipWeapon(Weapon *weapon) {
    this->weapon = weapon;
    std::cout << name << "装备了" << weapon->getName() << std::endl;
}

void Player::attackMonster(Monster *monster) {
    std::cout << name << "攻击了" << monster->getName() << std::endl;
    int weaponAttack = weapon == nullptr ? 0 : weapon->getAttack();
    int attack = (this->attack + weaponAttack) - monster->getDefense();
    monster->takeDamage(attack);
    std::cout << monster->getName() << "受到了" << attack << "点伤害，" << "剩余生命值:" << monster->getHealth()
              << std::endl;
}
void Player::skill1(Monster *monster) {
    monster->takeDamage(20);
    std::cout << monster->getName() << "受到了" << 20 << "点真实伤害，" << "剩余生命值:" << monster->getHealth()
              << std::endl;
}
void Player::addExp(int exp) {
    expAccumulation += exp;
    if (expAccumulation >= expLimit) { levelUp(); }
    std::cout << name << "获得了" << exp << "点经验值，当前经验值:" << expAccumulation << std::endl;
}
void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}
bool Player::isDead() const {
    return health == 0;
}