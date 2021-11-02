#include "Spell.h"
#include "GameEntity.h"

void DrawPower::spell(GameEntity* user, GameEntity* target)
{
    //adds one mana to user's mana pool
    const int MANA_ADD = 1;
    if (user->getMana() < user->getMAX_MANA())
        user->addMana(MANA_ADD), std::cout << "\n>Gained 1 mana\n";
    else
        std::cout << "\n>Mana full!\n";
}

void SapHealth::spell (GameEntity* user, GameEntity* target) 
{
    //user heals 1/2 the amount of damage done to target
    user->deleteMana(manaCost);

    user->addHealth(damage / 2);
    if (user->getHealth() >= user->getMaxHealth())
        user->setHealth(user->getMaxHealth());
    std::cout << "\n>Sapped some health!\n";
    std::cout << "\n>Attack " << damage << " damage\n";
    std::cout << "\n>Returned " << damage / 2 << " heath\n";
    target->deleteHealth(damage);
}

void LifeForceExplosion::spell(GameEntity* user, GameEntity* target)
{
    //damage related to how much health the user has
    user->deleteMana(manaCost);
    std::cout << "\n>It's an explosion of life force energy!\n";
    damage = (damage * user->getHealth()) / user->getMaxHealth();
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
}

void Heal::spell(GameEntity* user, GameEntity* target)
{
    user->deleteMana(manaCost);
    int healing = 50;
    //heals 50 points of player's  health
    user->addHealth(healing);
    if (user->getHealth() >= user->getMaxHealth())
        user->setHealth(user->getMaxHealth());
    std::cout << "\n>" << healing << " health\n";
}

void MegaHeal::spell(GameEntity* user, GameEntity* target)
{
    manaCost = user->getMana();
    int healing = 10 * user->getMana();
    user->deleteMana(manaCost);
    std::cout << "\n>" << healing << " health\n";
}

void BasicAttack::spell(GameEntity* user, GameEntity* target)
{
    user->deleteMana(manaCost);
    int crit = (rand() % 3) + 1;
    if (crit > 2)
    {
        //attack critical hits
        damage *= 1.5;
        std::cout << "\n>It's a critical hit!\n";
    }
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
    damage=20;
}

void Smash::spell(GameEntity* user, GameEntity* target)
{
    user->deleteMana(manaCost);
    //attack hits for 20 damage
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
}

void SkeleHit::spell(GameEntity* user, GameEntity* target)
{
    damage=(double)(rand() % 30)+10; //attack hits between 10 and 30 damage
    user->deleteMana(manaCost);
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
}

void PowerSurge::spell(GameEntity* user, GameEntity* target)
{
    //does damage based on total mana
    manaCost = user->getMana();
    user->deleteMana(manaCost);
    damage = (double)manaCost*7;
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
}

void SpeedDance::spell(GameEntity* user, GameEntity* target)
{
    user->deleteMana(manaCost);
    user->addSpeed(5);
    std::cout << "\n>Plus 5 Speed\n";
}

void FearFreeze::spell(GameEntity* user, GameEntity* target)
{
    const int SPEED_DOWN = 5;
    user->deleteMana(manaCost);
    target->deleteSpeed(SPEED_DOWN);
    std::cout << "\n>Your speed was lowered\n";
    std::cout << "\n>" << damage << " damage\n";
    target->deleteHealth(damage);
}


/*
enum spellTypes { DRAW_POWER, SAP_HEALTH, LIFE_FORCE_EXPLOSION };
    Spell* createSpell(spellTypes type)
    {
        switch (type)
        {
        case DRAW_POWER: return new DrawPower();
            break;
        case SAP_HEALTH: return new SapHealth();
            break;
        case LIFE_FORCE_EXPLOSION: return new LifeForceExpolsion();
            break;
        default:
            break;
        }
    }
*/