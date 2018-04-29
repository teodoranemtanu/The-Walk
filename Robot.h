//
// Created by teone on 04-Apr-18.
//
#ifndef THEWALK_ROBOT_H
#define THEWALK_ROBOT_H

#include <string>
#include <vector>
#include <iostream>
#include "GameMap.h"

using namespace std;
/**
 * robot will be an abstract class, memorising its position and the items accepted by the type fo the robot
 */
class Robot {
protected:
    pair<int, int> position;
    int resistance;
    vector<string> itemsAccepted;

public:
    friend class GameEngine;

    Robot();

    Robot(int i, int j);

    void setMapPosition(pair<int, int> p, GameMap &world);

    virtual ~Robot();

    virtual bool round(GameMap &world)=0;


    virtual void increaseResistance(int x);

    virtual void decreaseResistance(int x);

    int getResistance() const;

    pair<int, int> getPosition() const {
        return position;
    };

    void setPosition(int moveRow, int moveColumn) {
        position.first = moveRow;
        position.second = moveColumn;
    }

    virtual void changeAttribute(bool x) = 0;
};

class Ninja : public Robot {
    bool agility;
public:
    Ninja();

    Ninja(int i, int j);


    bool round(GameMap &world);

    void changeAttribute(bool x) {
        agility = x;
    }
};

class Warrior : public Robot {
public:
    Warrior(int i, int j);

    Warrior() {};

    bool round(GameMap &world);

    void changeAttribute(bool x) {};

};

class Genius : public Robot {
    int countIdeaBox;
    /// if the robot finds an invincibility item, he will be able to avoid all the traps
    bool invincibility;
    int rightCol, leftCol, upRow, downRow, move;
public:
    Genius(int i, int j);

    Genius() {
        rightCol = leftCol = upRow = downRow = 0;
        move = 0;
    };

    bool round(GameMap &world);


    void changeAttribute(bool x);
};

#endif //THEWALK_ROBOT_H

