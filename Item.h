//
// Created by teone on 19-Apr-18.
//

#ifndef THEWALK_ITEM_H
#define THEWALK_ITEM_H

#include "GameMap.h"
#include "Robot.h"

using namespace std;

class Item {
protected:
    pair<int, int> position;

public:
    friend class Robot;

    Item(int, int);

    virtual void effect(Robot &A) = 0;

    pair<int, int> getPosition() const {
        return position;
    }

    void setMapPosition(pair<int, int> P, GameMap &World);

    ifstream &read(ifstream &input, GameMap &world);
};

class Oil : public Item {
public:
    Oil(int x = 0, int y = 0) : Item(x, y) {}

    void effect(Robot &A);
};

class JumpBoost : public Item {
    Ninja *A;
public:
    JumpBoost(int x = 0, int y = 0) : Item(x, y) {}

    void effect(Robot &A);
};

class Armour : public Item {
public:
    Armour(int x = 0, int y = 0) : Item(x, y) {}

    void effect(Robot &A);
};

class IdeaBox : public Item {
public:
    IdeaBox(int x = 0, int y = 0) : Item(x, y) {}

    void effect(Robot &A);
};

#endif //THEWALK_ITEM_H
