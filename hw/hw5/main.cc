#include "hero.h"
#include "heroes.cc"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <Hero*> a;
    
    for(int i=0; i<10; i++)
    {
	Hero* toPush;
	if(i%2==0)
	    toPush = new intHero(10, 10, 10, 10);
	else if (i%3==0)
	    toPush = new agilityHero(10,10,10,10);
	else
	    toPush = new strengthHero(10,10,10,10);

	a.push_back(toPush);
    }

    for (int i=0; i<a.size();i++)
    {
	a.at(i)->level_up();
	a.at(i)->specialAttack();
    }
}
