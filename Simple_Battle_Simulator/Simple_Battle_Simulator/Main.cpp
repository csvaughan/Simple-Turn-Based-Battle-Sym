/*
Name:Caleb Vaughan
Date:9/4/2021
Program: Basic battle simulator
*/

#include "Player.h"
#include "Monster.h"

//functions
void battle(Player*, Monster*);
bool speedCheck(double, double);
Monster* init();

Monster* init()
{
    //chooses a monster based on random number
    srand((unsigned)time(0));
    const int NUM_MONSTERS = 3;
    int monsterType = rand() % NUM_MONSTERS;

    switch (monsterType)
    {
        case 0: return new Skeleton(); break;
        case 1: return new Zombie(); break;
        case 2: return new Mage(); break;
        default: return nullptr;
    }
}

int main()
{
    Monster* monster = init();
    Player* player = new Player();

    battle(player, monster);

    delete player;
    delete monster;

    std::cin.ignore();
    std::cin.get();
    return 0;
}

void battle(Player* player, Monster* monster)
{
    int round = 1;

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << ">A " << monster->getName() << " has Appeared!" << std::endl;

    //main game loop
    do {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Round: {" << round << "}\n\n";

        std::cout << monster->getName() << ":\n";
        monster->getInfo();
        std::cout << "\n\n\n\n";
        std::cout << "Player:\n";
        player->getInfo();

        //get user input
        int userInput = player->getInput();

        switch (speedCheck(player->getSpeed(), monster->getSpeed()))
        {
        case false:
            //monster attacks first
            monster->turn(monster, player);
            if (player->getHealth() > 0)
                player->turn(player, monster, userInput);
            break;
        case true:
            //player attacks first
            player->turn(player, monster, userInput);
            if (monster->getHealth() > 0)
                monster->turn(monster, player);
            break;
        }

        //sets texts color to white
        SET_TO_WHITE;
        //breaks from loop if user or monster is dead
        if (player->getHealth() <= 0 || monster->getHealth() <= 0)
        {
            std::cout << "---------------------------------------------" << std::endl;
            break;
        }
        else
        {
            //prepares for next round
            std::cout << "---------------------------------------------" << std::endl
                << "\n>Press any key to continue...";
            _getch();
            std::cout << "\033[2J\033[1;1H";//clears screen
            player->incrementMana();
            monster->incrementMana();
            round++;
        }
    } while (monster->getHealth() > 0 && player->getHealth() > 0);

    //victory/defeat message
    (player->getHealth() <= 0) ? std::cout << "\nDefeat!\n" : std::cout << "\nVictory!\n";
}

bool speedCheck(double playerSpeed, double enemySpeed)
{
    //compares the speed of the player to enemy to determine who goes first.
    if (playerSpeed < enemySpeed)
        return false;//enemy is faster
    else if (playerSpeed > enemySpeed)
        return true;//player is faster
    else
    {
        //in the case of a speed tie, one of the combantants will randomly go first
        int speedTie = rand() % 100;
        //50/50 chance of going first if speed tie
        return (speedTie > 50) ?  true :  false;
    } 
}