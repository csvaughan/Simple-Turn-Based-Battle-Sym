#pragma once
#include "GameEntity.h"

class Player : public GameEntity
{
public:
    Player()
    {
        maxHealth = 100,
            Health = maxHealth,
            Speed = 55,
            Mana = 3;
        spellDeck[0] = new BasicAttack;
        spellDeck[1] =  new Heal;
        spellDeck[2] = new DrawPower;
    }
    ~Player()
    {
        for (Spell* i : spellDeck)
            delete i;
    }

    void getSpells() const;
    int boundsCheck(int input);
    int getInput();
    void turn(GameEntity*, GameEntity*, int) override;
};