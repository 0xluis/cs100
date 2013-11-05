/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW4
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <iostream>
#include "String.h"
using namespace std;

int main()
{
    
    cout << "making an empty string" << endl;
    String a;

    cout <<"this is the size of string a: " << a.length() << endl << endl;
    
    String b("abc");
    cout << "Making a string b with \"abc\"" << endl;
    cout << "this is the contents of b " << b << " with size ";
    cout << b.length() << endl << endl;
    
    String c(b);
    cout << "Making c from b with \"abc\"" << endl;
    cout << "This is the contents of c " << c << endl;
    cout << "This is the length of c " << c.length() << endl << endl;

    String d;
    cout << "Assigning d to b" << endl;
    d = b;
    cout << "This is the contents of d: " << d << endl;
    cout << "This is the index of a: " << d.indexOf('a') << endl;
    cout << "This is the index of f: " << d.indexOf('f') << endl <<endl;

    cout << "Is a equal to b? " << (a==b) << endl 
         << "Is b equal to c? "<< (c==b) << endl;
    cout << "Bracket operator at index 5 returns: ";
    cout << c[5];
    cout << "Bracket operator at index 2 returns: " << c[2] << endl << endl;
    cout << "Modifying the char at index 2" << endl;
    c[2] = 'f';
    cout << "This is now the contents of c: " << c << endl;
    cout << "Is b equal to c? " << (c==b) << endl << endl;

    cout << "This is the concatenation of c+b: " << (c+b) << endl;
    cout << "This is the size of the concatentaion: " << (c+b).length() << endl;
    

    cout << "This is the concatention of c+=d: ";
    c+=d;
    cout << c << endl;
    cout << "This is the length of c: " << c.length() << endl;
    
    cout << "Input into c: ";
    cin >> c;
    cout << "This is now the contents of c: " << c << endl;
    cout << "c now has length of " << c.length() << endl;
}
