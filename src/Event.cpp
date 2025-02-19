
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Event.h"

void Event::combat(Player *player, Monster *monster) {
    if (monster->isDead()) { monster->reset(); }
    std::cout << "战斗开始" << std::endl;

    while (!player->isDead() && !monster->isDead()) {
        std::cout << "\n"
                  << player->getName() << " 当前血量: " << player->getHealth() << "/" << player->getMaxHealth()
                  << std::endl;
        std::cout << monster->getName() << " 当前血量: " << monster->getHealth() << "/" << monster->getMaxHealth()
                  << std::endl;
        player->showSkill();
        int choice;
        std::cout << "请选择技能（输入数字）";
        std::cin >> choice;
        switch (choice) {
        case 1: player->attackMonster(monster); break;
        case 2: player->skill1(monster); break;
        default: break;
        }
        if (monster->isDead()) {
            int exp = monster->getExp();
            std::cout << "战斗胜利" << std::endl;
            player->addExp(exp);
            break;
        }
        monster->attackPlayer(player);
        if (player->isDead()) {
            std::cout << "战斗失败" << std::endl;
            break;
        }
    }
}