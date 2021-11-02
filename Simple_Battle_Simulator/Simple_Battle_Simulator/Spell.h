#pragma once
#include <string>

class GameEntity;

enum class spellType {NULL_SPELL, HEAL, DAMAGE, STAT_CHANGE };
class Spell
{   
public:  
    Spell(): damage(0), manaCost(0), type(spellType::NULL_SPELL){}
    
    int getManaCost() const
    { return manaCost; }
    
    std::string getDescription() const
    { return description; }

    virtual void spell(GameEntity* user, GameEntity* target) = 0;
    
protected:
    spellType type;
    std::string description;
    int manaCost;
    double damage; 
};

class DrawPower : public Spell
{
public:
    DrawPower()
    {
        type = spellType::STAT_CHANGE;
        manaCost = 0;
        damage = 0;
        description = "User gains one Mana";
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class SapHealth : public Spell
{
public:
    SapHealth()
    {
        type = spellType::DAMAGE;
        manaCost = 2;
        damage = 20;
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class LifeForceExplosion : public Spell
{
public:
    LifeForceExplosion()
    {
        type = spellType::DAMAGE;
        manaCost = 4;
        damage = 60;
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class Heal : public Spell
{
public:
    Heal()
    {
        type = spellType::HEAL;
        manaCost = 1;
        description = "User heals 50 health";
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class MegaHeal : public Spell
{
public:
    MegaHeal()
    {
        type = spellType::HEAL;
        manaCost = 1;
        description = "User heals 10 health per mana";
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class BasicAttack : public Spell
{
public:
    BasicAttack()
    {
        type = spellType::DAMAGE;
        manaCost = 2,
        damage = 20;
        description = "User does 20 damage to target";
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class Smash : public Spell
{
public:
    Smash()
    {
        type = spellType::DAMAGE;
        manaCost = 2;
        damage = 20;
    }

    void spell(GameEntity* user, GameEntity* target) override;
};

class SkeleHit : public Spell
{
public:
    SkeleHit()
    {
        type = spellType::DAMAGE;
        manaCost = 2;
        damage = 0; 
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class PowerSurge : public Spell
{
public:
    PowerSurge()
    {
        type = spellType::DAMAGE;
        manaCost = 1;
        damage = 0;
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class SpeedDance : public Spell
{
public:
    SpeedDance()
    {
        type = spellType::STAT_CHANGE;
        manaCost = 0;
    }
    void spell(GameEntity* user, GameEntity* target) override;
};

class FearFreeze : public Spell
{
public:
    FearFreeze()
    {
        type = spellType::DAMAGE;
        manaCost = 4;
        damage = 30;
    }
    void spell(GameEntity* user, GameEntity* target) override;
};