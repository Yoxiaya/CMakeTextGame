#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Monster.h"
#include "Weapon.h"

class Monster;
class Weapon;
class Player {
private:
    // 名称
    std::string name;
    // 生命值
    int health;
    // 最大生命值
    int maxHealth;
    // 攻击力
    int attack;
    // 防御力
    int defense;
    // 速度
    int speed;
    // 经验值
    int expAccumulation;
    // 经验值上限
    int expLimit;
    // 等级
    int level;
    // 武器
    Weapon* weapon;
    
    void levelUp();
public:
    Player(std::string name, int health, int attack,int defense, int speed, int expAccumulation);

    // getters
    std::string getName() const;
    int getHealth() const;
    int getDefense() const;


    void displayPlayerStats() const;
    void takeDamage(int damage);
    void attackMonster(Monster* monster);

    void equipWeapon(Weapon* weapon);
    void addExp(int exp);

    bool isDead() const;
};
#endif