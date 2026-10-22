#include "Game.h"
#include "RPG.h"
#include <random>
using namespace std;

Game::Game(){
}

void Game::generatePlayers(int n){
    for (int i = 0; i < n; i++){
        players.push_back(new RPG());

        // rename players
        string new_name = "NPC_"+to_string(i);
        players[i]->setName(new_name);
        live_players.insert(i);
    }
}

int Game::selectPlayer(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);
    
    int randomIndex = dist(gen);

    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    int selectedIndex = *it;
    return selectedIndex;
}

void Game::endRound(RPG *winner, RPG *loser, int loserIndex){
    (*winner).setHitsTaken(0);
    live_players.erase(loserIndex);
    (*winner).updateExpLevel();
    printf("%s won against %s\n", (*winner).getName().c_str(), (*loser).getName().c_str());
}

void Game::battleRound(){
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();
    // redundancy checker
    if(playerIndex1 == playerIndex2){
        battleRound();
        return;
    }

    RPG *player1 = players[playerIndex1];
    RPG *player2 = players[playerIndex2];

    while(player1->isAlive() && player2->isAlive()){
        player1->attack(player2);
        if(player2->isAlive()){
            player2->attack(player1);
        }
    }
    if(player1->isAlive()){
        endRound(player1, player2, playerIndex2);
    }
    else{ // if player2 won
        endRound(player2, player1, playerIndex1);
    }
}

void Game::gameLoop(){
    while(live_players.size() > 1){
        battleRound();
    }
}

void Game::printFinalResults(){
    for(int i = 0; i < players.size(); i++){
      players[i]->printStats();
    }
}

Game::~Game(){
}