//
// Created by teone on 19-Apr-18.
//

#ifndef THEWALK_TRAP_H
#define THEWALK_TRAP_H
#include "Robot.h"
#include "GameMap.h"
using namespace std;
/**
 * one trap is going to decrease the resistance of the robot if possible
 * otherwise, the robot is not going to move this round
 */
class Trap {
    pair <int, int> position;
public:
    friend class Robot;
    friend class Ninja;
    Trap(int i, int j, GameMap & world);
    Trap();
    void effect(Robot *A);
    void read(ifstream & input, GameMap & world);
    void setMapPosition(pair <int, int> p, GameMap &world);
};

#endif //THEWALK_TRAP_H
