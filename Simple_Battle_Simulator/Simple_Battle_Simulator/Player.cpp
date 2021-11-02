#include "Player.h"

void Player::getSpells() const
{
    for (int i = 0; i < DECK_LEN; i++)
        std::cout << i + 1 << ": [" << spellDeck[i]->getDescription() << "]{" << spellDeck[i]->getManaCost() << "}\n";
}

void Player::turn(GameEntity* p, GameEntity* m, int userInput)
{
    SET_TO_GREEN;
    spellDeck[userInput]->spell(p,m);
}

int Player::getInput()
{
    int unsigned userInput;

    //the player chooses a move
    std::cout << "\nWhat will you do? \n";
    getSpells();
    std::cout << "Input: ";
    std::cin >> std::setw(1) >> userInput;
    std::cout << "---------------------------------------------" << std::endl;
   
    //makes sure the user input is good
    while (!std::cin.good()) 
    {
        std::cout << "Invalid Input: Please enter a number.\n";

        //clear input stream
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');

        //prompt user again
        
        getSpells();
        std::cout << "Input: ";
        std::cin >> std::setw(1) >> userInput;
        std::cout << "---------------------------------------------" << std::endl;
    }
    userInput = boundsCheck(userInput-1);

    //makes sure that the user has enough mana for the spell
    switch (userInput) {
    case 0:
        if (Mana >= spellDeck[0]->getManaCost())
            return 0;
        else
        {
            std::cout << "\n-You don't have enough mana for that spell\n";
            getInput();
        }
        break;
    case 1:
        if (Mana >= spellDeck[1]->getManaCost())
            return 1;
        else
        {
            std::cout << "\n-You don't have enough mana for that spell\n";
            getInput();
        }
        break;
    case 2:
        if (Mana >= spellDeck[2]->getManaCost())
            return 2;
        else
        {
            std::cout << "\n-You don't have enough mana for that spell\n";
            getInput();
        }
        break;
    }
    return 0;
}

int Player::boundsCheck(int input)
{
    while ((input <0) || (input > 2))
    {
        std::cout << "Value out of range:" << std::endl;
        input = boundsCheck(getInput());
    }
    return input;
}