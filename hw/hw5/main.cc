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
#include "heroes.cc"
#include <iostream>
#include <list>
using namespace std;

void interesting(list <Hero*> listOfH)
{
    for(list<Hero*>::const_iterator i = listOfH.begin();
	i!=listOfH.end(); i++)
    {
	(*i)->specialAttack();
	cout << endl;
    }
}

int main()
{
    list <Hero*> a;
    
    for(int i=0; i<10; i++)
    {
	Hero* toPush;
	if(i%2==0)
	    toPush = new intHero(10, 10, 12, 10);
	else if (i%3==0)
	    toPush = new agilityHero(10,14,10,10);
	else
	    toPush = new strengthHero(10,10,10,20);

	a.push_back(toPush);
    }

   interesting(a);

}
