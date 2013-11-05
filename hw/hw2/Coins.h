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

//Coins.h
#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKLE = 5;

class Coins
{
    public:
	Coins(int q, int d, int n, int p);
	void depositChange(Coins c);
	bool hasSufficientAmount(int amount);
	Coins extractChange(int amount);
	void print(ostream & out);
    private:
	int quarters, dimes, nickles, pennies;
};
ostream & operator << (ostream & out, Coins & c);
