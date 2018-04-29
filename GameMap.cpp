//
// Created by teone on 02-Apr-18.
//

#include "GameMap.h"
using namespace std;

GameMap::GameMap(int n, int m) {
    height = n;
    width = m;
    M.resize(n);
    for (int i = 0; i < n; i++)
        M[i].resize(m);
    M[0][0] = R;
}

GameMap::~GameMap() {
    M.erase(M.begin(), M.end()); // ?
    // for (int i = 0; i < height; i++)
    //    delete[] M[i];
    // delete[] M;
}

GameMap::GameMap(GameMap &obj) {
    height = obj.height;
    width = obj.width;
    M.resize(height);
    for (int i = 0; i < height; i++)
        M[i].resize(width);
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            M[i][j] = obj.M[i][j];
}

bool GameMap::isTrap(pair<int, int> p) const{
    if (M[p.first][p.second] == T) {
        return true;
    }
    return false;
}


bool GameMap::isItem(pair<int, int> p) const{
    if (M[p.first][p.second] == I) {
        return true;
    }
    return false;
}

GameMap &GameMap::operator=(const GameMap &A) {
    if (this != &A) {
        height = A.height;
        width = A.width;
        treasurePosition.first = A.treasurePosition.first;
        treasurePosition.second = A.treasurePosition.second;

        M.resize(height);
        for (int i = 0; i < height; i++)
            M[i].resize(width);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                M[i][j] = A.M[i][j];
    }
    return *this;
}

ofstream &operator << (ofstream &output, GameMap & world) {
    int i, j;
    for (i = 0; i < world.height; i++) {
        for (j = 0; j < world.width; j++) {
            output << world.M[i][j] << " ";
        }
        output << "\n";
    }
    return output;
}

