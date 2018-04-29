//
// Created by teone on 19-Apr-18.
//

#include "Trap.h"

Trap::Trap(int i, int j, GameMap &world) {
    world.M[i][j] = T;
    position.first = i;
    position.second = j;
}

Trap::Trap() {
    position.first = -1;
    position.second = -1;
}


///reads a trap
void Trap::read(ifstream &input, GameMap &world) {
    input >> position.first;
    input >> position.second;
    world.M[position.first][position.second] = T;
}

void Trap::effect(Robot *robo) {
    if (robo->getResistance() > 0) robo->decreaseResistance(1);
    if (robo->getResistance() == 0);
}

void Trap::setMapPosition(pair<int, int> p, GameMap &world) {
    world.M[p.first][p.second] = T;
}
