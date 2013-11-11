//abstract class
#ifndef HERO_ACLASS
#define HERO_ACLASS
#include <iostream>
#include <string>
using namespace std;
class Hero
{
    protected:
	int health;
        int strength, agility, intel;
    public:
	Hero(int hp, int str, int agil, int intell)
	:health(hp), strength(str), agility(agil), intel(intell)
	{
	    //constructor
	}
	virtual void level_up() = 0;
        virtual void specialAttack()
	{
	    cout << "this message should never pop up because a mere hero class "
	         << "cannot be created but still needs to be defined\n";
	}
};

#endif
