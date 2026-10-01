#include <iostream>
#include "RPG.h"
using namespace std;

int main()
{
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    RPG p2 = RPG();

    printf("%'s Current Stats:\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());
    printf("%'s Current Stats:\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n", p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    // call setHitsTaken(new_hit) on either p1 and p2
    p1.setHitsTaken(5);
    // p2.setHitsTaken(10);

    cout << "\nP1 hits taken ";
    cout << p1.getHitsTaken(); 
    cout << "\nP2 hits taken ";
    cout << p2.getHitsTaken(); 

    cout << "0 is dead, 1 is alive\n";
    p1.isAlive();
    p2.isAlive();

    return 0;
}