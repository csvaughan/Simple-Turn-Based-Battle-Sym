#include "Monster.h"
#include <algorithm>

void Monster::turn(GameEntity* user, GameEntity* target, int)
{
    //creates an array of mana cost values and sorts from small to large
    int manaCosts[DECK_LEN];
    for (int i=0; i<DECK_LEN; i++)
        manaCosts[i]=spellDeck[i]->getManaCost();
    std::sort(std::begin(manaCosts), std::end(manaCosts));

    int choice = moveChoice(manaCosts);
    //std::cout << "\nchoice: " << choice<<std::endl;//debug purposes
    if (choice >= 0)
        spellDeck[choice]->spell(user, target);
    else
        std::cout << "\nPASS\n";
}

int Monster::moveChoice(int manaCosts[])
{
    //AI for monster move choice
    SET_TO_RED;
    const int ARR_LEN = 3;
    int weights[ARR_LEN];
    int choice = (rand() % 10) + 1;
    //sets weight based on mana
    if (Mana < manaCosts[0])
        return -1;
    else if (Mana >= manaCosts[0] && Mana < manaCosts[1])
        weights[0] = 10;
    else if (Mana >= manaCosts[1] && Mana < manaCosts[2])
        weights[0] = 5, weights[1] = 5;
    else if (Mana >= manaCosts[2] && Mana <= manaCosts[2]+2)
        weights[0] = 2, weights[1] = 3, weights[2] = 5;
    else
        weights[0] = 0, weights[1] = 2, weights[2] = 8;

    //finds return value
    for (int i = 0; i < ARR_LEN; i++)
    {
        if (choice <= weights[i])
            return i;
        else
            choice -= weights[i];
    }
    return 0;
}