//
// Created by teone on 26-Apr-18.
//

#include "GameEngine.h"
#include <bits/stdc++.h>
#include <algorithm>
void GameEngine::setRobotPosition(int x, int y) {
    robo->setPosition(x, y);
}

ifstream &operator>>(ifstream &input, GameEngine &game) {
    int x, y;
    input >> game.nrRounds;
    input >> x >> y;
    GameMap A(x, y);
    input >> x >> y;
    A.setTreasurePosition(make_pair(x, y));
    input >> game.countItems >> game.countTraps;
    for (int i = 0; i < game.countItems; i++) {
        //sets the type of robot and items
        string type;
        Item *currentItem;
        input >> type;
        if (type == "Oil") {
            Oil oil;
            oil.read(input, A);
            currentItem = &oil;
        } else if (type == "JumpBoost") {
            JumpBoost jboost;
            jboost.read(input, A);
            currentItem = &jboost;
        } else if (type == "Armour") {
            Armour armour;
            armour.read(input, A);
            currentItem = &armour;
        } else {
            IdeaBox ibox;
            ibox.read(input, A);
            currentItem = &ibox;
        }
        game.items.push_back(currentItem);
    }

    for (int i = 0; i < game.countTraps; i++) {
        Trap *currentTrap = new Trap();
        (*currentTrap).read(input, A);
        game.traps.push_back(currentTrap);
    }
    game.world = A;
    return input;
}

GameEngine::~GameEngine() {
    items.clear();
    traps.clear();
}

ofstream &GameEngine::playGame(ofstream &output) {
    int iterator = 0;
    output << world;
    //robo->position.first=robo->position.second=0;
    int i, j;
    //plays rounds until the treasure is not found
    while(robo->round(world)==0) {
            output << "Round:" << iterator << "\n";
            if (world.isItem(robo->getPosition())) {
                for (auto h: items) {
                    if (h->getPosition() == robo->position) {
                        if (dynamic_cast<Ninja *>(robo) != nullptr) { // verifies if the item
                            if (dynamic_cast<Oil *>(h) != nullptr || dynamic_cast<JumpBoost *>(h) != nullptr)
                                h->effect(*robo);
                        }else if(dynamic_cast<Warrior *>(robo) != nullptr){
                            if (dynamic_cast<Oil *>(h) != nullptr || dynamic_cast<Armour *>(h) != nullptr)
                                h->effect(*robo);
                        }else if(dynamic_cast<Genius*>(robo) != nullptr){
                            if (dynamic_cast<Oil *>(h) != nullptr || dynamic_cast<IdeaBox *>(h) != nullptr)
                                h->effect(*robo);
                        }
                    }
                }
            }
            output << world;
            iterator++;
            if (iterator == nrRounds) exit(0);
        }
    return output;
}

