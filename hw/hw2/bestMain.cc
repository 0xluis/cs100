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
#include "Coins.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void deposit(Coins &);
void withdraw(Coins &);
void menu(Coins &);

int main()
{
	//no loose mains
	Coins myCoins(0,0,0,0);
    while(true)
    {
		menu(myCoins);
	}
}

//ask user how many quarters dimes nickles pennies
void deposit(Coins & c)
{
    int q=0,d=0,n=0,p=0;
    cout << "How many quarters will you deposit? ";
    cin >> q;
    cout << "How many dimes will you deposit? ";
    cin >> d;
    cout << "How many nickles will you deposit? ";
    cin >> n;
    cout << "How many pennies will you deposit? ";
    cin >> p;
    
    Coins toDeposit(q,d,n,p);

    c.depositChange(toDeposit);
}   

//ask for cents to extract
//then make a coin object using the extractChange function
void withdraw(Coins & c)
{
    int amount=0;
    cout << "How many cents will you extract? ";
    cin >> amount;
    if(!c.hasSufficientAmount(amount))
    {
	cout << "Not enough change!" << endl;
        return;
    }

    c.extractChange(amount);
}
//print the menu and control the menu input
void menu(Coins & myCoins)
{
        char command;
	cout << "\n   $$$$$COIN THING PROGRAM HW2 $$$$$$$$\n"
		 << "============================================="
		 << "=====\n"
		 << "||\td - deposit coins!\t\t||\n"
		 << "||\te - extract coins!\t\t\t||\n"
		 << "||\tp - print balance!\t\t\t||\n"
		 << "||\tq - quit the program!\t\t||\n";
	cout << "Type in letter command: ";
	cin >> command;
	if(cin.peek()!='\n')
	{
	    cout << "Input reduced 1st char";
	    cin.ignore();
	}
	cout << endl;

	switch (command)
	{
		case 'd':
		  deposit(myCoins);
		break;
		case 'e':
		  withdraw(myCoins);
		break;
		case 'p':
		  cout << "You have " << myCoins << " left!\n";
		break;
		case 'q':
		  exit(0);
		break;
		default:
		   cout << "Not a valid Command!\n";
		break;
	 }
}
