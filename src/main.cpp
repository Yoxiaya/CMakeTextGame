#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <sstream>
#include "Player.h"
#include "Monster.h"
#include "Event.h"
#include "Weapon.h"
#include "utils.h"

void showMenu() {
    std::cout << "1.查看玩家信息" << std::endl;
    std::cout << "2.战斗" << std::endl;
    std::cout << "3.查看武器图鉴" << std::endl;
    std::cout << "4.随机装备武器" << std::endl;
    std::cout << "5.查看怪物图鉴" << std::endl;
    std::cout << "q.退出游戏" << std::endl;
}
Weapon *createWeapon(std::stringstream &ss) {
    int id;
    std::string name;
    int attack;
    if (ss >> id >> name >> attack) { return new Weapon(id, name, attack); }
    return nullptr;
}
Monster *createMonster(std::stringstream &ss) {
    std::string name;
    int hp;
    int attack;
    int defense;
    int speed;
    int exp;
    if (ss >> name >> hp >> attack >> defense >> speed >> exp) {
        return new Monster(name, hp, attack, defense, speed, exp);
    }
    return nullptr;
}

int main() {
    srand(time(NULL));
    Player *shiro = new Player("小白", 100, 20, 10, 20, 0);

    // 加载武器数据
    std::string weaponPath = "../config/weapon.txt";
    // 加载怪物数据
    std::string monsterPath = "../config/monster.txt";

    std::vector<Weapon *> weapons = loadfiles<Weapon *>(weaponPath, createWeapon);
    std::vector<Monster *> monsters = loadfiles<Monster *>(monsterPath, createMonster);
    Weapon *selectedWeapon = nullptr;
    Monster *selectedMonster = nullptr;

    Event event;
    char choice = ' ';
    showMenu();
    while (choice != 'q') {
        std::cin >> choice;
        switch (choice) {
        case '1': shiro->displayPlayerStats(); break;
        case '2':
            selectedMonster = randomSelect<Monster *>(monsters);
            event.combat(shiro, selectedMonster);
            break;
        case '3':
            std::cout << "武器名称\t攻击力" << std::endl;
            for (const auto &weapon : weapons) { weapon->getWeaponInfo(); }
            break;
        case '4':
            selectedWeapon = randomSelect<Weapon *>(weapons);
            shiro->equipWeapon(selectedWeapon);
            break;
        case '5':
            std::cout << "怪物名称\t生命值\t攻击力\t防御力\t速度\t经验值" << std::endl;
            for (const auto &monster : monsters) { monster->getMonsterInfo(); }
            break;
        case 'q': std::cout << "游戏结束" << std::endl; break;
        default: std::cout << "无效选项" << std::endl; break;
        }
    }

    for (auto weapon : weapons) { delete weapon; }
    for (auto monster : monsters) { delete monster; }
    delete shiro;
    return 0;
}