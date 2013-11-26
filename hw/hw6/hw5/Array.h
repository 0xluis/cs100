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
#ifndef ARRAY_H
#define ARRAY_H
#include <ostream>

//needed to decalre << outside of this file
template <typename T> class Array;
template <typename T> std::ostream& operator <<(std::ostream & out, Array<T>&a);

class IndexOutOfBoundsException{};

template <typename T>
class Array
{
    private:
	int len;
	T *buf;
    public:
	
	Array(int newLen);
	Array(Array<T>&);
	int length();
	T &operator [] (int);
	void print(std::ostream &);
	//<> to define non template funciton
	friend std::ostream & operator << <>(std::ostream & out, Array<T>& a);
};
//needed or linking errors
#include "Array.cpp"
#endif

