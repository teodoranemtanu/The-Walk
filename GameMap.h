//
// Created by teone on 02-Apr-18.
//

#ifndef THE_WALK_GAMEMAP_H
#define THE_WALK_GAMEMAP_H

#include <utility>
#include <vector>
#include <fstream>

#define R 1
#define T -1
#define C 3
#define I 2
using namespace std;

///saves the map details
class GameMap {
    int width;
    int height;
    pair<int, int> treasurePosition;
    vector < vector < int > > M;
    friend class Item;
    friend class Robot;
    friend class Ninja;
    friend class Warrior;
    friend class Genius;
    friend class Trap;
    friend class GameEngine;
public:

    GameMap() : width(1), height(1) {
        M.resize(1);
        M[1].resize(1);
    };

    GameMap(int n, int m);

    GameMap(GameMap &M);

    ~GameMap();

    int getHeight() const{
        return height;
    }

    int getWidth() const{
        return width;
    }

    pair<int, int> getTreasurePosition() {
        return treasurePosition;
    };
    void setTreasurePosition(pair <int, int> p){
        treasurePosition.first = p.first;
        treasurePosition.second = p.second;
        M[p.first][p.second] = C;
    }

    bool isItem(pair<int, int> p) const; // check if a position contains an item
    bool isTrap(pair<int, int> p) const; // check if a position contains a trap

    GameMap &operator=(const GameMap &A);

    friend ofstream &operator <<(ofstream &fout, GameMap & world);
};


#endif //THE_WALK_GAMEMAP_H
