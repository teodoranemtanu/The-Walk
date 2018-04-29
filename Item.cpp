//
// Created by teone on 19-Apr-18.
//

#include "Item.h"

Item::Item(int i = 0, int j = 0) {
    position.first = i;
    position.second = j;
}

void Item::setMapPosition(pair<int, int> p, GameMap &world) {
    world.M[p.first][p.second] = I;
}

ifstream &Item::read(ifstream &input, GameMap &world) {
    input >> position.first;
    input >> position.second;
    world.M[position.first][position.second] = I;
    return input;
}

void Oil::effect(Robot &A) {
    A.increaseResistance(1);
}

void JumpBoost::effect(Robot &A) {
    A.changeAttribute(true);
}

void IdeaBox::effect(Robot &A) {
    A.changeAttribute(true);
}

void Armour::effect(Robot &A) {
    A.increaseResistance(2);
}
