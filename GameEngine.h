//
// Created by teone on 26-Apr-18.
//

#ifndef THE_WALK_2_GAMEENGINE_H
#define THE_WALK_2_GAMEENGINE_H

#include "GameMap.h"
#include "Robot.h"
#include "Item.h"
#include "Trap.h"
#include <fstream>

using namespace std;

class GameEngine {
    int nrRounds;
    vector<Item *> items;
    vector<Trap *> traps;
    int countItems;
    int countTraps;
    Robot *robo;
    GameMap world;

public:
    void setRobo(Robot *a)
    {
        robo=a;
    }
    friend class Robot;

    friend class Item;
    friend class Trap;
    friend class JumpBoost;

    GameEngine() : world(1, 1) {
        nrRounds = 0;
        countItems = 0;
        countTraps = 0;
    }

    ~GameEngine();

    friend ifstream &operator>>(ifstream &input, GameEngine &game);

    void setRobotPosition(int x, int y);

    ofstream &playGame(ofstream &output);
};

#endif //THE_WALK_2_GAMEENGINE_H
