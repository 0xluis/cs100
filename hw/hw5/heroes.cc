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

#include "hero.h"
class intHero: public Hero
{
    public:
	intHero(int a, int b, int c, int d)
	:Hero(a,b,c,d)
	{
	    //Hero(a,b,c,d);
	}
 	
	virtual void specialAttack()
	{
	    cout << "This intHero derived from Hero converts all of its "
		 << "intelligence to attack damage resulting in " 
		 << intel*20 << " pure damage.\n";
	}
};

class strengthHero: public Hero
{
    public:
	strengthHero(int a, int b, int c, int d)
	:Hero(a,b,c,d)
	{
	    //Hero(a,b,c,d);
	}

	virtual void specialAttack()
	{
	    cout << "This strengthHero derived from Hero reduces his intelligence"
		 << " in order to gain more strength.\n";
	    strength += intel;
	    intel = 0;
	    cout << "The strength of this hero is now " << strength << "with "
	         << intel << " intelligence.\n";
	}
};

class agilityHero: public Hero
{
    public:
	agilityHero(int a, int b, int c, int d)
	:Hero(a,b,c,d)
	{
	    //Hero(a,b,c,d);
	}

        virtual void specialAttack()
	{
	    cout << "This agilityHero derived from Hero splits his agility by 2"
		 << " In order to gain more intel and strength. This is actually"
		 << " a horrible special attack.\n";
	    agility = agility/2;
	    strength+=agility/2;
	    intel+=agility/2;
	
	    cout << "The stats of this hero is now:\n"
		 << "agility: " << agility << endl
		 << "strength: " << strength << endl
		 << "intel: " << intel << endl;
	}
};
