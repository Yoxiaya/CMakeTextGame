#ifndef EVENT_H
#define EVENT_H

#include "Player.h"
#include "Monster.h"

class Player;
class Monster;
class Event {
    private:
    public:
        void combat(Player* player, Monster* monster);
};

#endif