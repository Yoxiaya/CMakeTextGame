#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include "Player.h"

class Player;

class Monster {
private:
    // 名称
    std::string name;
    // 生命值
    int health;
    // 攻击力
    int attack;
    // 防御力
    int defense;
    // 速度
    int speed;
    // 经验值
    int exp;

public:
    Monster(std::string name, int health, int attack, int defense, int speed, int exp);

    // getters
    std::string getName() const;
    int getHealth() const;
    int getDefense() const;
    int getExp() const;
    void getMonsterInfo() const;

    void displayPlayerStats() const;
    void attackPlayer(Player *player);
    void takeDamage(int damage);
    bool isDead() const;
};
#endif