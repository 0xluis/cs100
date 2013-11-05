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
using namespace std;


int main()
{
    Coins pocket(5, 3, 6, 8);
    Coins piggyBank(50, 50, 50, 50);
    cout << "I started with " << pocket << " in my pocket." << endl;
    cout << "and " << piggyBank << " in my piggy bank" << endl << endl;
    //buy chips
    cout << "Bought some chips because I'm so fat for 68 cents.\n";
    pocket.extractChange(68);
    cout << "I now have " << pocket << " left in my pocket" << endl << endl;

    cout << "I transfer a bunch of coins (166 cents)"
         << " from my piggy bank to my pocket" 
         << endl;

    pocket.depositChange(piggyBank.extractChange(166));
    cout << "I now have " << pocket << " in my pocket" << endl
         << "and " << piggyBank << " in my bank" << endl << endl;

    cout << "While vacuuming I found lose change, cha ching!" 
         << endl;
    Coins looseChange(3, 2, 5, 1);

    cout << "I put the loose change into my piggy bank" << endl;
    piggyBank.depositChange(looseChange);
    cout << "I now have " << piggyBank << " in my bank" << endl;
    
}
