
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Event.h"

void Event::combat(Player* player, Monster* monster) {
    if (monster->isDead()) {
        std::cout << "怪物已经死亡" << std::endl;
        return;
    }
    std::cout << "战斗开始" << std::endl;
    while (!player->isDead() && !monster->isDead()) {
        player->attackMonster(monster);
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