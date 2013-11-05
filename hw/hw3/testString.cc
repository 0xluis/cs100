/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW3
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

    cout <<"this is the size of string a: " << a.size() << endl 
         << endl;
    
    String b("abc");
    cout << "Making a string b with \"abc\"" << endl;
    cout << "this is the contents of b " << b << " with size "
         << b.size() << endl;

    cout << "Making a new string c with reverse of b" << endl;
    String c = b.reverse();
    cout << "this is the contents of c " << c 
         << " and this is the size of c " << c.size() << endl << endl;


    cout <<"this is the char of c at positon 0 " << c[0] << endl;
    c[0] = '4';
    cout << "I replaced the char at 0 with '4' " 
         << "This is the char of c at positon 0 "
         << c[0] << endl;
    cout << "This is the contents of c now " << c << endl;
    cout << "Lets try returning the char at -1 " << endl;
    cout << c[-1] << endl << endl;

    String d(c);
    cout << "Lets create a copy of c called d\n";
    cout << "Lets set a = to d\n";

    a=d;

    cout << "these are all 4 current string classes: " << endl 
         << "a: " << a << endl 
         << "b: " << b << endl 
         << "c: " << c << endl 
         << "d: " << d << endl;

    cout << "is d == c?: " << (d == c) << endl;
    cout << "is b != c?: " << (b != c) << endl;
    cout << "is d!= c?: " << (d != c) << endl;
    cout << "is b == c?: " << (b == c) << endl;


    cout << "is " << a << " less than " << b <<"?: " << (a<b) << endl;
    cout << "is " << a << " less than " << a <<"?: " << (a<a) << endl;
    cout << "is " << a << " less than or equal to " << a << "?: "
         << (a<=a) << endl;

    cout <<"This is a+b " << a+b << endl;
    cout << "setting a = a+b" << endl;
    a=a+b;
    cout << "setting a+=b" << endl;
    a+=b;
    cout << "This is a now a " << a << endl;

    cout << "You make a string to replace a contents: ";
    cin >> a;

    cout << "This is now a " << a << endl;

    cout << "is the new a: " << a << " greater than b: " << b << "? : "
         << (a>b) << endl;
}
