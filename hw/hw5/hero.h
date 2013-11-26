/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW5
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

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
        virtual ~Hero(){};
};

#endif
