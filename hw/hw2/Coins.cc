/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW2
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
//Coins.cc define all of coins methods
#include <iostream>
#include "Coins.h"
using namespace std;

Coins::Coins(int q, int d, int n, int p)
:quarters(q), dimes(d), nickles(n), pennies(p)
{
    //constructor
}

void Coins::depositChange(Coins c)
{
    quarters += c.quarters;
    dimes += c.dimes;
    nickles += c.nickles;
    pennies += c.pennies;
}

bool Coins::hasSufficientAmount(int amount)
{
	//basic check do we even have enough money
    int total = 0;
    total = (quarters*CENTS_PER_QUARTER) + (dimes*CENTS_PER_DIME)
            + (nickles*CENTS_PER_NICKLE) + pennies;
            
    if(total < amount)
		return false;
    
    //pretty nasty and hacky
    //the prettier solution probably being mod
    //but this is easy to mindlessly code
    //we need to check if we have the right number of coins
    //we are getting the amount of change we get if we were to extract
    int qN = 0, dN=0, nN=0, pN=0,
        bkupq=quarters, bkupd = dimes, bkupn = nickles, 
        bkupp = pennies, bkupAmount = amount;
    
    while(bkupq > 0 && amount/CENTS_PER_QUARTER > 0)
    {
		bkupq--;
		qN++;
		amount -= CENTS_PER_QUARTER;
    }

    while(bkupd > 0 && amount/CENTS_PER_DIME > 0)
    {
		bkupd--;
		dN++;
		amount -= CENTS_PER_DIME;
    }

    while(bkupn > 0 && amount/CENTS_PER_NICKLE > 0)
    {
		bkupn--;
		nN ++;
        	amount -= CENTS_PER_NICKLE;
    }

    while(bkupp > 0 && amount > 0)
    {
		bkupp--;
		pN++;
        	amount -= 1;
    }
    
    //run total of change we get if we extracted
    amount = qN*CENTS_PER_QUARTER + dN*CENTS_PER_DIME +
		     nN*CENTS_PER_NICKLE + pN;
		     
    return amount==bkupAmount;

}

Coins Coins::extractChange(int amount)
{
    //this could be easier with mod but this logic works
    int qN = 0, dN=0, nN=0, pN=0;
    
    while(quarters > 0 && amount/CENTS_PER_QUARTER > 0)
    {
	quarters --;
	qN++;
	amount -= CENTS_PER_QUARTER;
    }

    //amount = amount - (qN * CENTS_PER_QUARTER);

    while(dimes > 0 && amount/CENTS_PER_DIME > 0)
    {
	dimes --;
	dN++;
        amount -= CENTS_PER_DIME;
    }

    //amount = amount - (dN * CENTS_PER_DIME);

    while(nickles > 0 && amount/CENTS_PER_NICKLE > 0)
    {
	nickles --;
	nN ++;
        amount -= CENTS_PER_NICKLE;
    }

    //amount = amount - (nN * CENTS_PER_NICKLE);

    while(pennies > 0 && amount > 0)
    {
	pennies --;
	pN++;
        amount -= 1;
    }

    //amount = amount - pN;

   return Coins(qN, dN, nN, pN);
}

void Coins::print(ostream & out)
{
    out << quarters << " quarters, " << dimes << " dimes, "
	<< nickles << " nickles, and " << pennies << " pennies";
}

ostream & operator << (ostream & out, Coins& c)
{
    c.print(out);
}

