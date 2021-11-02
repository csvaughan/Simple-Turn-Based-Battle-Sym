#pragma once
#include "GameEntity.h"

class Monster : public GameEntity
{
protected:
    std::string Name;
public:

    //constructor
    Monster() {}
    ~Monster()
    {
        for (Spell* i : spellDeck)
            delete i;
    }

    std::string getName() const 
    {return Name;}

    void turn(GameEntity*, GameEntity*, int =0) override;
    int moveChoice(int []);
};

class Mage : public Monster
{
public:
    Mage()
    {
        Name = "Dark Wizard";
        maxHealth = 75,
        Health = maxHealth,
        Speed = 60;
        spellDeck[0] = new DrawPower;
        spellDeck[1] = new SapHealth;
        spellDeck[2] = new LifeForceExplosion;
    }
    ~Mage()
    {
        for (Spell* i : spellDeck)
            delete i;
    }
};

class Skeleton : public Monster
{
public:
    Skeleton()
    {
        Name = "Skeleton Warrior";
        maxHealth = 80,
        Health = maxHealth,
        Speed = 70;
        spellDeck[0] = new SpeedDance;
        spellDeck[1] = new PowerSurge;
        spellDeck[2] = new SkeleHit;
    }
    ~Skeleton()
    {
        for (Spell* i : spellDeck)
            delete i;
    }

};

class Zombie :public Monster
{
public:
    Zombie()
    {
        Name = "Undead Battler";
        maxHealth = 100,
        Health = maxHealth,
        Speed = 50;
        spellDeck[0] = new  DrawPower;
        spellDeck[1] = new  Smash;
        spellDeck[2] = new  FearFreeze;
    }
    ~Zombie()
    {
        for (Spell* i : spellDeck)
            delete i;
    }
};