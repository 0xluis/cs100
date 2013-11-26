/*
* Course: CS 100 Fall 2013
*
* First Name: Luis
* Last Name: Garcia
* Username: lgarc018
* email address: lgarc018@ucr.edu
*
*
* Assignment: HW6
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

//template array
//#include "Array.h"
#include <iostream>
#include <assert.h>
#include <iomanip>
using namespace std;

template <class T>
Array<T>::Array(int newLen)
:len (newLen), buf(new T[newLen])
{
}

template <class T>
Array<T>::Array(Array<T> & l)
:len(l.len), buf (new T[l.len])
{
    for(int i=0; i<l.len; i++)
	buf[i] = l.buf[i];
}

template <class T>
int Array<T>::length()
{
    return len;
}

template <class T>
T& Array<T>::operator [] (int i)
{
    if (0 <= i && i < len)
        return buf[i];
    else
	throw IndexOutOfBoundsException();

}

template <class T>
void Array<T>::print(ostream & out)
{
    for (int i=0; i<len; i++)
	out << setw(5) << buf[i];
	out << endl;
}

template <class T>
ostream & operator << (ostream & out, Array<T> & a)
{
    a.print(out);
    return out;
}
