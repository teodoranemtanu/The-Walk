//
// Created by teone on 04-Apr-18.
//

#include "Robot.h"
#include "Trap.h"

Robot::Robot() {
    position.first = 0;
    position.second = 0;
    resistance = 0;
}

Robot::Robot(int i, int j) {
    position.first = i, position.second = j;
    resistance = 0;
}

void Robot::setMapPosition(pair<int, int> p, GameMap &world) {
    world.M[p.first][p.second] = R;
}

int Robot::getResistance() const {
    return resistance;
}

void Robot::increaseResistance(int x) {
    resistance += x;
}

void Robot::decreaseResistance(int x) {
    resistance -= x;
}

Robot::~Robot() {
    cout << "apel robot" << endl;
    for (int i = 0; i < itemsAccepted.size(); i++)
        itemsAccepted[i].clear();
    itemsAccepted.clear();
}

Ninja::Ninja() : Robot() {
}

Ninja::Ninja(int i, int j) : Robot(i, j) {
    agility = false;
    itemsAccepted.push_back("Oil");
    itemsAccepted.push_back("JumpBoost");
    // itemsAccepted.push_back("Key");

}

/**
 *
 * @param world - the map where the game is going to play
 * @return true if the robot found the treasure, false otherwise
 */
bool Ninja::round(GameMap &world) {
    pair<int, int> prevPoz = getPosition();
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;
    int yF = world.treasurePosition.second;
    if (world.getTreasurePosition() == make_pair(j, i)) {
        //checks if the ninja found the treasure
        // move(i, j, world, 1);
        return true;
    } else {
        //checks if the treasure is nearby
        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            if (xF < i) setPosition(i - 1, j);
            else if (xF > i) setPosition(i + 1, j);
            if (yF < j) setPosition(i, j - 1);
            else if (yF > j) setPosition(i, j + 1);
            setMapPosition(getPosition(), world);
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
            }
        } else {
            // the ninja is going to move line by line
            setMapPosition(getPosition(), world);
            if ((getPosition().second == world.getWidth() - 1 && i % 2 == 0) ||
                (getPosition().second == 0 && i % 2 == 1)) {
                setPosition(i + 1, j);
                setMapPosition(getPosition(), world);
                return 0;
            }
            if (i % 2 == 0) setPosition(i, j + 1);
            else setPosition(i, j - 1);
            setMapPosition(getPosition(), world);
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if (resistance == 0) {
                    // if the resistance of the ninja is >0, it will be decreased
                    // otherwise the robot will not move this round
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }
            return 0;
        }
    }

    return false;
}


bool Warrior::round(GameMap &world) {
    pair<int, int> prevPoz = getPosition();
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;
    int yF = world.treasurePosition.second;
    // checks if the treasure is here
    if (world.getTreasurePosition() == make_pair(j, i)) {
        // move(i, j, world, 1);
        return true;
    } else {

        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            if (xF < i) setPosition(i - 1, j);
            else if (xF > i) setPosition(i + 1, j);
            if (yF < j) setPosition(i, j - 1);
            else if (yF > j) setPosition(i, j + 1);
            setMapPosition(getPosition(), world);
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
            }
        } else {
            // the warrior will move column by column
            setMapPosition(getPosition(), world);
            if ((getPosition().first == world.getHeight() - 1 && j % 2 == 0) ||
                (getPosition().first == 0 && j % 2 == 1)) {
                setPosition(i, j + 1);
                setMapPosition(getPosition(), world);
                return 0;
            }
            if (j % 2 == 0) setPosition(i + 1, j);
            else setPosition(i - 1, j);
            setMapPosition(getPosition(), world);

            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if (resistance == 0) {
                    // if the resistance of the ninja is >0, it will be decreased
                    // otherwise the robot will not move this round
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }
        }
    }
    return false;
}

Warrior::Warrior(int i, int j) : Robot(i, j) {
    resistance = 3;
    itemsAccepted.push_back("Oil");
    itemsAccepted.push_back("Armour");
}


Genius::Genius(int i, int j) : Robot(i, j) {
    countIdeaBox = 0;
    invincibility = false;
    itemsAccepted.push_back("Oil");
    itemsAccepted.push_back("IdeaBox");
}


bool Genius::round(GameMap &world) {
    pair <int, int> prevPoz = getPosition();
    int i = getPosition().first;
    int j = getPosition().second;
    int xF = world.treasurePosition.first;
    int yF = world.treasurePosition.second;

    if (world.getTreasurePosition() == make_pair(j, i)) {
        return true;
    } else {
        if (abs(xF - i) <= 4 && abs(yF - j) <= 4) {
            if (xF < i) setPosition(i - 1, j);
            else if (xF > i) setPosition(i + 1, j);
            if (yF < j) setPosition(i, j - 1);
            else if (yF > j) setPosition(i, j + 1);
            setMapPosition(getPosition(), world);
            if (world.isTrap(getPosition())) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
            }
        } else {
            /// the genius will move in spiral
            setMapPosition(getPosition(), world);
            if (move % 4 == 0) { // checks on which direction the warrior moves
                if (j == world.getWidth() - 1 - rightCol) {
                    setPosition(i + 1, j);
                    move++;
                    upRow++;
                } else setPosition(i, j + 1);
            } else if (move % 4 == 1) {
                if (i == world.getHeight() - 1 - downRow) {
                    setPosition(i, j - 1);
                    move++;
                    rightCol++;
                } else setPosition(i + 1, j);
            } else if (move % 4 == 2) {
                if (j == 0 + leftCol) {
                    setPosition(i - 1, j);
                    move++;
                    downRow++;
                } else setPosition(i, j - 1);
            } else if (move % 4 == 3) {
                if (i == 0 + upRow) {
                    setPosition(i, j + 1);
                    move++;
                    leftCol++;
                } else setPosition(i + 1, j);
            }
            setMapPosition(getPosition(), world);

            if (world.isTrap(getPosition()) && !invincibility) {
                Trap currentTrap(getPosition().first, getPosition().second, world);
                currentTrap.effect(this);
                if(resistance == 0) {
                    // if the resistance of the ninja is >0, it will be decreased
                    // otherwise the robot will not move this round
                    setPosition(prevPoz.first, prevPoz.second);
                    setMapPosition(prevPoz, world);
                }
            }

            return 0;
        }
    }

    return false;
}

void Genius::changeAttribute(bool x) {
    if (countIdeaBox >= 3) invincibility = true;
}
