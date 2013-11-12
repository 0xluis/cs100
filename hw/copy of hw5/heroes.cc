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
