
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Event.h"

void Event::combat(Player *player, Monster *monster) {
    if (monster->isDead()) { monster->reset(); }
    std::cout << "------------战斗开始-------------" << std::endl;

    while (!player->isDead() && !monster->isDead()) {
        std::cout << "********************************" << std::endl;
        std::cout << "\n"
                  << player->getName() << " 当前血量: " << player->getHealth() << "/" << player->getMaxHealth()
                  << std::endl;
        std::cout << monster->getName() << " 当前血量: " << monster->getHealth() << "/" << monster->getMaxHealth()
                  << "\n"
                  << std::endl;
        std::cout << "********************************" << std::endl;
        int choice;
        bool menuFlag = true;
        while (menuFlag) {
            std::cout << "------------------" << std::endl;
            std::cout << "1.普通攻击" << std::endl;
            std::cout << "2.选择技能" << std::endl;
            std::cout << "------------------" << std::endl;
            std::cout << "请选择技能操作:";
            std::cin >> choice;
            switch (choice) {
            case 1: {
                player->attackMonster(monster);
                menuFlag = false;
                break;
            }
            case 2: {
                player->showSkill();
                int case2;
                bool case2bool = true;
                while (case2bool) {
                    std::cout << "请选择技能操作:";
                    std::cin >> case2;
                    switch (case2) {
                    case 1: {
                        player->skill(monster);
                        case2bool = false;
                        menuFlag = false;
                        break;
                    }
                    case 2: {
                        case2bool = false;
                        break;
                    }
                    default: {
                        std::cout << "请再次选择" << std::endl;
                        break;
                    }
                    }
                }
                break;
            }
            default: {
                break;
            }
            }
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