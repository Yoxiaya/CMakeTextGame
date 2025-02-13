#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Event.h"
#include "Weapon.h"

void showMenu() {
    std::cout << "1.查看玩家信息" << std::endl;
    std::cout << "2.战斗" << std::endl;
    std::cout << "3.查看武器图鉴" << std::endl;
    std::cout << "4.随机装备武器" << std::endl;
    std::cout << "q.退出游戏" << std::endl;
}

Weapon *randomSelection(std::vector<Weapon *> &weapons) {
    int randNum = rand() % weapons.size();
    Weapon *selectedWeapon = weapons[randNum];
    return selectedWeapon;
}

int main() {
    srand(time(NULL));
    Player player("小白", 100, 20, 10, 20, 0);

    std::string filePath = "../config/weapon.txt";
    std::vector<Weapon *> weapons = Weapon::createWeapons(filePath);
    Weapon *selectedWeapon = nullptr;

    Event event;
    char choice = ' ';
    showMenu();
    while (choice != 'q') {
        Monster monster("史莱姆", 50, 15, 0, 5, 120);
        std::cin >> choice;
        switch (choice) {
        case '1': player.displayPlayerStats(); break;
        case '2': event.combat(player, monster); break;
        case '3':
            std::cout << "武器名称\t攻击力" << std::endl;
            for (const auto &weapon : weapons) { weapon->getWeaponInfo(); }
            break;
        case '4':
            selectedWeapon = randomSelection(weapons);
            player.equipWeapon(selectedWeapon);
            break;
        case 'q': std::cout << "游戏结束" << std::endl; break;
        default: std::cout << "无效选项" << std::endl; break;
        }
    }

    for (auto weapon : weapons) { delete weapon; }
    return 0;
}