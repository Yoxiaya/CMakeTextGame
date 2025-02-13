#include <iostream>
#include <string>
#include <vector>

#include <utils.h>
#include <Player.h>

struct OldPlayer {
    std::string name;
    int health;
    int attack;
    int speed;
    int expAccumulation;
};

struct Monster {
    std::string name;
    int health;
    int attack;
    int speed;
    int exp;
};
struct CombatResult {
    bool isWin;
    int expGain;
};

enum MeatEventType {
    BATTLE_EVENT,
    CHEST_EVENT,
    RECOVERY_EVENT,
};

// 时间进度条
const int TIME_ACCUMULATION = 100;

void showMenu() {
    std::cout << "1.查看玩家信息" << std::endl;
    std::cout << "2.向北移动" << std::endl;
    std::cout << "q.退出游戏" << std::endl;
}
void showPlayerInfo(OldPlayer player) {
    clearWindow();
    std::cout << "玩家名称:" << player.name << std::endl;
    std::cout << "生命值: " << player.health << std::endl;
    std::cout << "攻击力: " << player.attack << std::endl;
    std::cout << "经验值: " << player.expAccumulation << std::endl;
    std::cout << "-----------------" << std::endl;
}

void showCombatInfo(OldPlayer player, Monster monster, int &round) {
    round++;
    std::cout << "第" << round << "回合" << std::endl;
    std::cout << "玩家生命值:" << player.health << std::endl;
    std::cout << "怪物生命值:" << monster.health << std::endl;
    std::cout << "-----------------" << std::endl;
}
Monster randomMonster(std::vector<Monster> monster) {
    int random = rand() % 4;
    return monster[random];
};
CombatResult combat(OldPlayer &player, Monster &monster) {
    int playerSpeedAccumulation = 0;  // 玩家速度积累
    int monsterSpeedAccumulation = 0; // 怪物速度积累
    int round = 0;
    while (player.health > 0 && monster.health > 0) {
        playerSpeedAccumulation += player.speed;
        monsterSpeedAccumulation += monster.speed;
        bool playerTurn = playerSpeedAccumulation >= TIME_ACCUMULATION;
        bool monsterTurn = monsterSpeedAccumulation >= TIME_ACCUMULATION;

        if (playerTurn && monsterTurn) {
            if (player.speed >= monster.speed) {
                player.health -= monster.attack;
                playerSpeedAccumulation -= TIME_ACCUMULATION;
                monster.health -= player.attack;
                monsterSpeedAccumulation -= TIME_ACCUMULATION;
                showCombatInfo(player, monster, round);
            } else {
                monster.health -= player.attack;
                monsterSpeedAccumulation -= TIME_ACCUMULATION;
                player.health -= monster.attack;
                playerSpeedAccumulation -= TIME_ACCUMULATION;
                showCombatInfo(player, monster, round);
            }

        } else {
            if (playerTurn) {
                playerSpeedAccumulation -= TIME_ACCUMULATION;
                monster.health -= player.attack;
                showCombatInfo(player, monster, round);
            }
            if (monsterTurn) {
                monsterSpeedAccumulation -= TIME_ACCUMULATION;
                player.health -= monster.attack;
                showCombatInfo(player, monster, round);
            }
        }
        if (player.health <= 0) {
            CombatResult result = {false};
            return result;
            break;
        }
        if (monster.health <= 0) {
            CombatResult result = {true, monster.exp};
            return result;
            break;
        }
    }
    return {false};
}

bool goNorth(OldPlayer &player) {
    Monster monster1 = {"史莱姆", 50, 15, 5, 10};
    Monster monster2 = {"哥布林", 60, 20, 10, 20};
    Monster monster3 = {"巫妖", 70, 25, 15, 30};
    Monster monster4 = {"龙", 80, 30, 20, 40};

    std::vector<Monster> monsterList = {monster1, monster2, monster3, monster4};
    Monster monster = randomMonster(monsterList);
    std::cout << "遇到怪物" << monster.name << std::endl;
    std::cout << "开始战斗" << std::endl;
    std::cout << "****************" << std::endl;
    CombatResult res = combat(player, monster);
    if (res.isWin) {
        player.expAccumulation += res.expGain;
        std::cout << "战斗胜利，获得经验" << res.expGain << std::endl;
        return true;
    } else {
        std::cout << "战斗失败,游戏结束" << std::endl;
        return false;
    }
}

void testFun() {
    std::cout << "测试" << std::endl;
}

int main() {
    srand(time(0));
    OldPlayer player1 = {"Yoi", 100, 20, 20, 0};
    Player classPlayer("Yoimiya", 100, 20, 20, 0);

    char isGameOver;
    while (isGameOver != 'q') {
        showMenu();
        std::cin >> isGameOver;
        if (isGameOver == '1') {
            showPlayerInfo(player1);
        }
        if (isGameOver == '2') {
            bool flag = goNorth(player1);
            if (!flag) {
                break;
            }
        }
        if (isGameOver == 't') {
            classPlayer.displayPlayerStats();
        };
    }

    return 0;
}
