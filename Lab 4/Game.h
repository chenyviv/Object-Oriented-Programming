#ifndef Game_H
#define Game_H
#include <string>
#include <vector>
#include <set>
using namespace std;

class RPG;

class Game{
    public: 
        //constructors
        Game();

        //
        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG * winner, RPG * loser, int index);
        void battleRound();
        void gameLoop();
        void printFinalResults();

    private:
        vector <RPG*> players;
        set <int> live_players;
};
#endif