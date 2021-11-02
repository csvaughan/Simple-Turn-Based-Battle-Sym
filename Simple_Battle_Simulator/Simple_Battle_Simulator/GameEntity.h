#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h> 
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "Spell.h"

#define GET_HANDLE HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE) 
#define SET_TO_GREEN GET_HANDLE; SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN) 
#define SET_TO_RED GET_HANDLE; SetConsoleTextAttribute(hConsole, FOREGROUND_RED)
#define SET_TO_WHITE GET_HANDLE; SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

class GameEntity
{
public:
    static const int MAX_MANA = 10,
        DECK_LEN = 3;

    GameEntity() : Mana(3), maxHealth(0), Health(0), Speed(0){}

    void getInfo() const
    {
        const int BAR_LENGTH = 20;
        int numChars =(int)Health*BAR_LENGTH / maxHealth;
        
        //health bar
        std::cout << "Health [";
        for (int i = 0; i < numChars; i++)
                std::cout<< '#';
        for (int i = 0; i < BAR_LENGTH-numChars; i++)
            std::cout << '-';
        std::cout << "] " << Health << "/" << maxHealth;
        //mana
        std::cout << "\n[Mana: " << Mana << "/" << MAX_MANA << "]\n";
    }

    double getHealth() const
    {return Health;}

    double getMaxHealth()const
    {return maxHealth;}

    int getMAX_MANA()const 
    { return MAX_MANA; }

    double getSpeed() const
    {return Speed;}

    int getMana() const
    {return Mana;}

    void setHealth(double input)
    {Health = input;}

    void incrementMana() 
    { if (Mana < MAX_MANA) Mana++; }

    //functions used by spell class to modify stats
    void addHealth(double amnt) 
    {Health += amnt; }
    void deleteHealth(double amnt) 
    { Health -= amnt; }
    void addMana(int amnt) 
    { if (Mana<MAX_MANA) Mana += amnt; }
    void deleteMana(int amnt) 
    { Mana -= amnt; }
    void addSpeed(int amnt) 
    { Speed += amnt; }
    void deleteSpeed(int amnt)
    { if (Speed>0) Speed -= amnt;}

    //monster and player turn
    virtual void turn(GameEntity*, GameEntity*, int) = 0;

protected:
    int Mana,
        maxHealth;
    double Health,
        Speed;

    Spell* spellDeck[DECK_LEN] = {};
};