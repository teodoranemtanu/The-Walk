#include <iostream>
#include "GameEngine.h"

using namespace std;
ifstream input("..\\thewalk.in");
ofstream output("..\\thewalk.out");

int main() {

    GameEngine theWalk;

    input >> theWalk;
    string type;
    input >> type;
    Robot *a;
    if (type == "Ninja") {
        a=new Ninja();
    } else if (type == "Warrior") {
        a=new Warrior();

    } else {
        a=new Genius();

    }
    theWalk.setRobo(a);
    theWalk.playGame(output);

    return 0;
}