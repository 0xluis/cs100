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
        virtual void specialAttack() = 0;
};

#endif
